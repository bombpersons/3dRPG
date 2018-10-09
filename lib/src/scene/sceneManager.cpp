#include <3drpg/scene/sceneManager.hpp>
#include <3drpg/scene/scene.hpp>
#include <3drpg/game.hpp>

namespace rpg {
  // Init chai.
  void SceneManager::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<SceneManager>(), "SceneManager");

    // Add some functions here...
    chai.add(chaiscript::fun(&SceneManager::_showScene), "showScene");

    // Initialize the scene object.
    Scene::InitChai(chai);
  }

  SceneManager::SceneManager(Game* game)
    : m_game(game)
    , m_currentScene(nullptr) {
  }

  SceneManager::~SceneManager() {
    // If we have a scene loaded, close it.
    if (m_currentScene)
      delete m_currentScene;
  }

  void SceneManager::update(float dt) {
    // Call the update func for the current scene.
    m_currentScene->update(dt);
  }

  /// Script functions (should only really be called from scripts)
  bool SceneManager::_showScene(const std::string& sceneName) {
    auto& chai = m_game->getScript().chai();

    // Create an instance of the scene script.
    chaiscript::Boxed_Value sceneObj = chai.eval(std::string("Scene_") + sceneName + "();");
    if (sceneObj.is_null()) {
      return false;
    }

    // If we have a scene currently loaded, unset it.
    if (m_currentScene)
      delete m_currentScene;

    // Create our new scene..
    m_currentScene = new Scene(m_game, sceneObj);

    return true;
  }
}
