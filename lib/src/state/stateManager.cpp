#include <3drpg/state/stateManager.hpp>
#include <3drpg/game.hpp>

namespace rpg {
  void StateManager::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<StateManager>(), "StateManager");

    // Add some functions here...
  }

  StateManager::StateManager(Game* game) {

  }

  StateManager::~StateManager() {

  }
}
