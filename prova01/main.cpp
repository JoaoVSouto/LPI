#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using vector_string = std::vector<std::string>;
using map_string = std::map<std::string, std::string>;
using pair_int_string = std::pair<int, std::string>;

void show_usage(std::string const& program_name);
short handle_args(int argc, vector_string& args);
short write_message_to_file(std::string const& filename, std::string const& message);
pair_int_string read_message_from_file(std::string const& filename);
short handle_add(int argc, vector_string args);
short handle_list();
bool today_date_is_present_on_file();
bool does_file_exist(std::string const& filename);
bool is_file_empty(std::string const& filename);
bool file_has_last_line_empty(std::string const& filename);
std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();
vector_string split_string(std::string s, char delimiter);

std::string const FILE_NAME = "diary.md";

map_string const PROGRAM_ARGS = {{"add", "<mensagem>"},
                                 {"list", ""}};

int main(int argc, char const* argv[]) {
  vector_string args(argv, argv + argc);

  if (handle_args(argc, args) != 0) {
    show_usage(args.at(0));
    return 1;
  }

  if (args.at(1) == "add" && handle_add(argc, args) != 0) {
    return 1;
  }

  if (args.at(1) == "list" && handle_list() != 0) {
    return 1;
  }

  return 0;
}

void show_usage(std::string const& program_name) {
  std::cout << "Uso:";
  for (auto const& arg : PROGRAM_ARGS) {
    std::cout << "\t" << program_name << " "
              << arg.first << " " << arg.second << std::endl;
  }
}

short handle_args(int argc, vector_string& args) {
  if (argc == 1) return 1;

  std::string program_name = args.at(0);

  for (auto const& arg : PROGRAM_ARGS) {
    if (arg.first.compare(args.at(1)) == 0) {
      return 0;
    }
  }

  return 1;
}

short write_message_to_file(std::string const& filename, std::string const& message) {
  std::ofstream message_file(filename, std::ios::app);

  if (not message_file or not message_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo...\n";
    return 1;
  }

  message_file << message << "\n";

  message_file.close();

  return 0;
}

pair_int_string read_message_from_file(std::string const& filename) {
  std::ifstream message_file(filename);
  pair_int_string return_message_data(0, "");

  if (not message_file or not message_file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo...\n";
    return_message_data.first = 1;
    return return_message_data;
  }

  std::string file_data;
  std::string current_line;
  std::vector<int> lines_length;

  while (not message_file.eof()) {
    std::getline(message_file, current_line);
    lines_length.push_back(current_line.length());
    file_data.append(current_line + "\n");
  }

  message_file.close();

  if (file_data.length() > 0)
    file_data.pop_back();  // Removes the last \n

  if (lines_length.back() == 0 and file_data.length() > 0) {
    file_data.pop_back();
    file_data.append("\n<new line place>");
  }

  return_message_data.second = file_data;

  return return_message_data;
}

short handle_add(int argc, vector_string args) {
  std::string message;

  if (argc == 2) {
    std::cout << "Digite uma mensagem:\n";
    while (std::getline(std::cin, message) and not message.length()) continue;
  }

  if (not message.length()) {
    message = args.at(2);
  }

  std::string message_composed = "";
  bool file_exist = does_file_exist(FILE_NAME);
  bool file_empty = false;

  if (file_exist) {
    file_empty = is_file_empty(FILE_NAME);
  }

  if (not file_exist or not today_date_is_present_on_file()) {
    message_composed = "\n# " + get_current_date() + "\n\n";
  }

  if (not file_exist or file_empty) {
    message_composed.erase(0, 1);  // deletes the first \n
  }

  bool does_file_has_last_line_empty = true;

  if (file_exist and not file_empty) {
    does_file_has_last_line_empty = file_has_last_line_empty(FILE_NAME);
  }

  if (file_exist and not today_date_is_present_on_file() and not does_file_has_last_line_empty) {
    message_composed.insert(0, 1, '\n');
    does_file_has_last_line_empty = true;
  }

  std::string line_prefix = does_file_has_last_line_empty ? "" : "\n";

  message_composed.append(line_prefix + "- " + get_current_time() + " " + message);

  if (write_message_to_file(FILE_NAME, message_composed) != 0) {
    return 1;
  }

  std::cout << "Mensagem adicionada com sucesso!\n";

  return 0;
}

short handle_list() {
  pair_int_string file_data = read_message_from_file(FILE_NAME);

  if (file_data.first != 0) {
    return 1;
  }

  vector_string file_data_splitted_by_new_line = split_string(file_data.second, '\n');

  bool does_file_has_last_line_empty = file_has_last_line_empty(FILE_NAME);

  if (does_file_has_last_line_empty) {
    file_data_splitted_by_new_line.pop_back();
  }

  std::string current_line_date;

  for (std::string const& current_line : file_data_splitted_by_new_line) {
    if (current_line.length() == 0) continue;

    if (current_line.rfind("#", 0) == 0) {  // detects if line starts with #
      current_line_date = current_line.substr(2);
      continue;
    }

    std::cout << "- " << current_line_date << " "
              << current_line.substr(2) << std::endl;
  }

  return 0;
}

bool today_date_is_present_on_file() {
  std::string file_content = read_message_from_file(FILE_NAME).second;
  std::string current_date = "# " + get_current_date();

  size_t found = file_content.find(current_date);

  return found != std::string::npos;
}

bool does_file_exist(std::string const& filename) {
  return static_cast<bool>(std::ifstream(filename));
}

bool is_file_empty(std::string const& filename) {
  std::string file_content = read_message_from_file(FILE_NAME).second;

  return not(file_content.length() > 0);
}

bool file_has_last_line_empty(std::string const& filename) {
  std::string file_content = read_message_from_file(FILE_NAME).second;

  size_t found = file_content.find("<new line place>");

  return found != std::string::npos;
}

std::string format_current_date(const std::string& format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() {
  return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
  return format_current_date("%H:%M:%S");
}

vector_string split_string(std::string s, char delimiter) {
  vector_string tokens;
  std::string token;
  size_t pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + 1);
  }

  tokens.push_back(s);

  return tokens;
}
