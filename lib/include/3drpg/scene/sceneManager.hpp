#ifndef RPG_INCLUDED_SCENEMANAGER
#define RPG_INCLUDED_SCENEMANAGER

#include <chaiscript/chaiscript.hpp>

namespace rpg {
  class Scene;
  class Game;
  class SceneManager {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    SceneManager(Game* game);
    virtual ~SceneManager();

    // Update.
    void update(float dt);

  private:
    // Switch to a scene.
    bool _showScene(const std::string& sceneName);

  private:
    // Game we belong to.
    Game* m_game;

    // The current scene (can only be one!)
    Scene* m_currentScene;
  };
}

#endif
