#include <3drpg/scene/scene.hpp>
#include <3drpg/scene/entity.hpp>
#include <3drpg/game.hpp>

namespace rpg {
  void Scene::InitChai(chaiscript::ChaiScript& chai) {
    chai.add(chaiscript::user_type<Scene>(), "Scene");

    // Add some functions here...
    chai.add(chaiscript::fun(&Scene::_newEntity), "newEntity");

    // Initialize entity scripting.
    Entity::InitChai(chai);
  }

  Scene::Scene(Game* game, chaiscript::Boxed_Value scriptObj) {
    m_game = game;
    m_scriptObj = scriptObj;

    // Attach some helpful functions to the script object.
    // Note: these won't be accessible in the constructor of the object.
    //       Use the init() function to do that!
    auto& chai = m_game->getScript().chai();

    // Call an initialization function on the script object.
    // This function is called when the scene is made active.
    // We expect the scene to create any entities, set the background image,
    // set the music, etc
    auto initFunc = chai.eval<std::function<void(chaiscript::Boxed_Value&, Scene*)>>("init");
    initFunc(m_scriptObj, this);
  }

  Scene::~Scene() {
    auto& chai = m_game->getScript().chai();

    // Call the destroy function if we have one.
    auto destructFunc = chai.eval<std::function<void(chaiscript::Boxed_Value&)>>("destroy");
    destructFunc(m_scriptObj);

    // Destroy our entities.
    for (auto it = m_entities.begin(); it != m_entities.end(); it++) {
      delete it->second;
    }
    m_entities.clear();
  }

  void Scene::update(float dt) {
    auto& chai = m_game->getScript().chai();

    // Call the instances update function.
    auto updateFunc = chai.eval<std::function<void(chaiscript::Boxed_Value&, float)>>("update");
    updateFunc(m_scriptObj, dt);
  }

  Entity* Scene::_newEntity(const std::string& uniqueName) {
    // If the entity already exists, return null;
    if (m_entities.find(uniqueName) != m_entities.end())
      return nullptr;

    // Create a new entity.
    Entity* entity = new Entity(m_game, this, uniqueName);
    m_entities[uniqueName] = entity;

    printf("Created entity with name %s\n", uniqueName.c_str());

    return entity;
  }
}
