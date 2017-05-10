#include <3drpg/scene/scene.hpp>

namespace rpg {
  // Init chai.
  void Scene::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<Scene>(), "Scene");

    // Add some functions here...
  }

  Scene::Scene() {

  }

  Scene::~Scene() {

  }
}
