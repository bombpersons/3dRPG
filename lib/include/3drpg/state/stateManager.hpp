#ifndef RPG_INCLUDED_STATEMANAGER
#define RPG_INCLUDED_STATEMANAGER

#include <string>
#include <map>

#include <chaiscript/chaiscript.hpp>

#include <3drpg/scene/scene.hpp>
#include <3drpg/scene/entity.hpp>

namespace rpg {
  class Game;
  class StateManager {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    StateManager(Game* game);
    virtual ~StateManager();

    // Get variables.
    int getGlobalVar(const char* name);
    int getSceneVar(Scene* scene, const char* name);
    int getEntityVar(Entity* entity, const char* name);

    // Set variables
    void setGlobalVar(const char* name, int value);
    void setSceneVar(Scene* scene, const char* name, int value);
    void setEntityVar(Entity* entity, const char* name, int value);

    // Load and save
    bool loadFromFile(const char* filepath);
    bool saveToFile(const char* filepath);

  private:
    std::map<std::string, int> m_globalVars;
  };
}

#endif
