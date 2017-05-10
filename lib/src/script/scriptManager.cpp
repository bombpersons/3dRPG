#include <3drpg/script/scriptManager.hpp>

#include <3drpg/scene/scene.hpp>
#include <3drpg/scene/entity.hpp>
#include <3drpg/scene/sceneManager.hpp>
#include <3drpg/state/stateManager.hpp>

namespace rpg {
  // Script manager functions.


  /// ScriptManager
  ScriptManager::ScriptManager() {
    // Initialize chaiscript here!
    Scene::InitChai(m_chai);
    Entity::InitChai(m_chai);
    SceneManager::InitChai(m_chai);
    StateManager::InitChai(m_chai);
  }

  ScriptManager::~ScriptManager() {

  }

  void ScriptManager::update(float dt) {

  }

  bool ScriptManager::evalFile(const char* file) {
    try {
      m_chai.eval_file(file);
    } catch (chaiscript::exception::eval_error& e) {
      printf("Chai Error - Evaluating file %s failed\n", file);
      printf("%s\n", e.pretty_print());
      return false;
    } catch (chaiscript::exception::file_not_found_error& e) {
      printf("Chai Error - Couldn't find %s\n", file);
      return false;
    }
    return true;
  }

  bool ScriptManager::eval(const char* code) {
    try {
      m_chai.eval(code);
    } catch (chaiscript::exception::eval_error& e) {
      printf("Chai Error - Evaluating code failed!\n");
      printf("Chai Error - %s\n", e.pretty_print().c_str());
      return false;
    }
    return true;
  }
}
