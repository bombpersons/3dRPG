#include <3drpg/game.hpp>

#include <iostream>

int main(int argc, char** argv) {
  std::cout << "Current working directory is " << argv[0] << '\n';
  rpg::Game game;
  game.run();
  game.wait();

  return 0;
}
