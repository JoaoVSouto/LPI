#include "../include/Config.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "../include/utils.h"

Config::Config(const std::string& filename) : filename(filename) {
  if (not this->fileExist()) {
    std::cout << "Aviso: Arquivo " << this->filename << " não encontrado.";
    std::cout << " Criando um com configurações padrões..." << std::endl;
    this->createFile();
  }
}

std::unordered_map<std::string, std::string> Config::getConfigs() {
  std::unordered_map<std::string, std::string> configs;
  std::ifstream file(this->filename);

  if (not file or not file.is_open()) {
    std::cout << "Erro: não foi possível abrir o arquivo "
              << this->filename << std::endl;
    return configs;
  }

  std::string line;

  while (std::getline(file, line)) {
    if (line.length() == 0) continue;

    std::vector<std::string> splitted_line = split_string(line, '=');

    configs[splitted_line[0]] = splitted_line[1];
  }

  file.close();

  return configs;
}

bool Config::fileExist() {
  return static_cast<bool>(std::ifstream(this->filename));
}

void Config::createFile() {
  std::ofstream file(this->filename);

  file << "path=diary.md\n";
  file << "default_format=%d %t: %m";

  file.close();
}
