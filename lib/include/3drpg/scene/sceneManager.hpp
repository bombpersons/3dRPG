#ifndef RPG_INCLUDED_SCENEMANAGER
#define RPG_INCLUDED_SCENEMANAGER

#include <chaiscript/chaiscript.hpp>

namespace rpg {
  class Game;
  class SceneManager {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    SceneManager();
    virtual ~SceneManager();

    // Update.
    void update(Game* game, float dt);

  private:

  };
}

#endif
