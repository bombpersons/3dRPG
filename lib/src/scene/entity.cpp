#include <3drpg/scene/entity.hpp>

namespace rpg {
  // Init chai.
  void Entity::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<Entity>(), "Entity");

    // Add some functions here...
  }

  Entity::Entity() {
  }

  Entity::~Entity() {
  }
}
