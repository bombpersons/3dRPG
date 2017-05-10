#include <3drpg/game.hpp>

int main(int argc, char** argv) {
  rpg::Game game;
  game.run();
  game.wait();

  return 0;
}
