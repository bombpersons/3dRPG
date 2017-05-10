#ifndef RPG_INCLUDED_SCRIPTMANAGER
#define RPG_INCLUDED_SCRIPTMANAGER

#include <chaiscript/chaiscript.hpp>

namespace rpg {
  class ScriptManager {
  public:
    ScriptManager();
    virtual ~ScriptManager();

    // Update
    void update(float dt);

    // Evaluate code.
    bool evalFile(const char* file);
    bool eval(const char* file);

  private:
    // The chaiscript interpreter.
    chaiscript::ChaiScript m_chai;
  };
}

#endif
