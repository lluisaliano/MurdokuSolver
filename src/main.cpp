#include <fstream>
#include <print>

#include "Board.hpp"

int main(int argc, char* argv[]) {
  // if (argc < 2) {
  //   std::println("You need to specify the filepath to the Murdoku Map");
  //   return 1;
  // }

  // std::ifstream fileMap{argv[1]};
  std::ifstream fileMap{"exampleMap.txt"};

  if (!fileMap) {
    std::println(stderr, "This file {} path could not be opened", argv[1]);
  }

  Board board{std::move(fileMap)};

}
