#include "robobuba.hpp"
#include <iostream>

int main() {
  std::vector<std::unique_ptr<Command>> commands;
  std::vector<std::unique_ptr<Command>> cmd;
  cmd.emplace_back(std::make_unique<Right>());
  cmd.emplace_back(std::make_unique<Left>());
  cmd.emplace_back(std::make_unique<Add>());
  cmd.emplace_back(std::make_unique<Sub>());


  std::ifstream file;
  file.open("D:\source\repos\misis2024s-23-01-bauer-v-v\prj.app\robobuba\input.txt");
  std::string input = "";
  while (std::getline(file, input)) { 
    std::cout << input << '\n';
    for (int i = 0; i < cmd.size(); ++i) {
      auto Obj = cmd[i]->Create(input);
      if (Obj != nullptr) {
        commands.emplace_back(std::move(Obj));
      }
    }
  }
  std::cout << commands.size();
}
