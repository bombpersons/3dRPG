#include <3drpg/script/scriptManager.hpp>

#include <3drpg/game.hpp>
#include <3drpg/scene/scene.hpp>
#include <3drpg/scene/entity.hpp>
#include <3drpg/scene/sceneManager.hpp>
#include <3drpg/state/stateManager.hpp>

#include <3drpg/util/filepaths.hpp>

namespace rpg {
  /// ScriptManager
  ScriptManager::ScriptManager(Game* game) :
    m_chai({}, {Filepaths::getWorkingDir()}) {

    // Initialize chaiscript here!
    SceneManager::InitChai(m_chai);
    StateManager::InitChai(m_chai);

    // Specific functions the game instance wants..
    game->initChai(m_chai);
  }

  ScriptManager::~ScriptManager() {

  }

  void ScriptManager::update(float dt) {

  }

  chaiscript::Boxed_Value ScriptManager::evalFile(const char* file) {
    std::string fullpath = Filepaths::getFullPath(file);
    chaiscript::Boxed_Value ret;
    try {
      ret = m_chai.eval_file(fullpath.c_str());
    } catch (chaiscript::exception::eval_error& e) {
      printf("Chai Error - Evaluating file %s failed\n", file);
      printf("%s\n", e.pretty_print().c_str());
    } catch (chaiscript::exception::file_not_found_error& e) {
      printf("Chai Error - Couldn't find %s\n", fullpath.c_str());
    }
    return ret;
  }

  chaiscript::Boxed_Value ScriptManager::eval(const char* code) {
    chaiscript::Boxed_Value ret;
    try {
      ret = m_chai.eval(code);
    } catch (chaiscript::exception::eval_error& e) {
      printf("Chai Error - Evaluating code failed!\n");
      printf("Chai Error - %s\n", e.pretty_print().c_str());
    }
    return ret;
  }
}
