#ifndef RPG_INCLUDED_SCENE
#define RPG_INCLUDED_SCENE

#include <glm/glm.hpp>
#include <chaiscript/chaiscript.hpp>

namespace rpg {
  class Game;
  class Entity;

  // Represents a scene in the game,
  // A setting for the characters to move around in and interact with.
  class Scene {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);

  public:
    Scene(Game* game, chaiscript::Boxed_Value sceneObj);
    virtual ~Scene();

    void update(float dt);
    void draw();

  private:
    Entity* _newEntity(const std::string& uniqueName);

  private:
    // The game we belong to.
    Game* m_game;

    // The underlying script object.
    chaiscript::Boxed_Value m_scriptObj;

    // The background
    const char* m_backgroundFile;

    // The music
    const char* m_musicFile;

    // Script
    const char* m_scriptFile;

    // List of entities to load here.
    std::map<std::string, Entity*> m_entities;

    // The camera position.
    glm::mat4 m_cameraTransform;
  };
}

#endif
