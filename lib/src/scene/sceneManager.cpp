#include <3drpg/scene/sceneManager.hpp>
#include <3drpg/game.hpp>

namespace rpg {
  // Init chai.
  void SceneManager::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<SceneManager>(), "SceneManager");

    // Add some functions here...
  }

  SceneManager::SceneManager() {
  }

  SceneManager::~SceneManager() {
  }

  void SceneManager::update(Game* game, float dt) {

  }
}
