#ifndef RPG_INCLUDED_ENTITY
#define RPG_INCLUDED_ENTITY

#include <map>
#include <glm/glm.hpp>
#include <chaiscript/chaiscript.hpp>

namespace rpg {
  class Scene;
  class Game;

  // Represents 3d entities in the scene, such as characters, chests, etc.
  class Entity {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    Entity(Game* game, Scene* scene, const std::string& uniqueName);
    virtual ~Entity();

    void callEvent(const std::string& name);
    void interact();

  private:
    typedef std::function<void(Entity*)> EventFunc;
    void _addEvent(const std::string& name, EventFunc func);
    void _setInteractEvent(const std::string& name);

  private:
    Game* m_game;
    Scene* m_scene;
    chaiscript::Boxed_Value m_scriptObj;

    // A model to load for this entity.
    const char* m_modelFile;

    // A transform for this entity.
    glm::mat4 m_transform;

    // The event to trigger when an interaction occurs.
    std::string m_interactionEvent;

    // A map of events attached to this entity.
    std::map<std::string, EventFunc> m_events;
  };
}

#endif
