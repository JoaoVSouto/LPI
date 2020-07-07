#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>

struct Config {
  std::string filename;

  Config(const std::string& filename);

  std::unordered_map<std::string, std::string> getConfigs();

 private:
  bool fileExist();
  void createFile();
};

#endif  // !CONFIG_H
