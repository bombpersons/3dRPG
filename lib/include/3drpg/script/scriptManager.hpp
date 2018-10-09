#ifndef RPG_INCLUDED_SCRIPTMANAGER
#define RPG_INCLUDED_SCRIPTMANAGER

#include <chaiscript/chaiscript.hpp>

namespace rpg {
  class Game;
  class ScriptManager {
  public:
    ScriptManager(Game* game);
    virtual ~ScriptManager();

    // Update
    void update(float dt);

    // Evaluate code.
    chaiscript::Boxed_Value evalFile(const char* file);
    chaiscript::Boxed_Value eval(const char* code);

    // Get the chai interpreter.
    chaiscript::ChaiScript& chai() { return m_chai; }

  private:
    // The chaiscript interpreter.
    chaiscript::ChaiScript m_chai;
  };
}

#endif
