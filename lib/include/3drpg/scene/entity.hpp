#ifndef RPG_INCLUDED_ENTITY
#define RPG_INCLUDED_ENTITY

#include <map>
#include <glm/glm.hpp>
#include <chaiscript/chaiscript.hpp>

namespace rpg {
  // Represents 3d entities in the scene, such as characters, chests, etc.
  class Entity {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    Entity();
    virtual ~Entity();

  private:
    // A script to run on this entity.
    const char* m_scriptFile;

    // A model to load for this entity.
    const char* m_modelFile;

    // A transform for this entity.
    glm::mat4 m_transform;

    // User data
    std::map<std::string, int> m_userData;
  };
}

#endif
