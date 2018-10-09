#include <3drpg/scene/entity.hpp>
#include <3drpg/scene/scene.hpp>
#include <3drpg/game.hpp>

namespace rpg {
  // Init chai.
  void Entity::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<Entity>(), "Entity");

    // Add some functions here...
    chai.add(chaiscript::fun(&Entity::_addEvent), "addEvent");
    chai.add(chaiscript::fun(&Entity::_setInteractEvent), "setInteractEvent");

    chai.add(chaiscript::fun(&Entity::callEvent), "callEvent");

    // Change the model / animation
    chai.add(chaiscript::fun(&Entity::_setModel), "setModel");

    // Trigger an interaction on an entity.
    chai.add(chaiscript::fun(&Entity::interact), "interact");
  }

  Entity::Entity(Game* game, Scene* scene, const std::string& uniqueName) {
    m_game = game;
    m_scene = scene;

    m_drawable = game->getGraphics().createDrawable();
  }

  Entity::~Entity() {
    if (m_drawable && m_game) {
      m_game->getGraphics().deleteDrawable(m_drawable);
    }
  }

  void Entity::interact() {
    callEvent(m_interactionEvent);
  }

  void Entity::callEvent(const std::string& name) {
    if (m_events.find(name) == m_events.end())
      return;

    // Call the event.
    m_events[name](this);
  }

  void Entity::_addEvent(const std::string& name, Entity::EventFunc func) {
    m_events[name] = func;
  }

  void Entity::_setInteractEvent(const std::string& name) {
    m_interactionEvent = name;
  }

  void Entity::_setModel(const std::string& path) {
    if (m_drawable) {
      m_drawable->loadModel(path.c_str());
    }
  }
}
