#ifndef RPG_INCLUDED_SCENE
#define RPG_INCLUDED_SCENE

#include <glm/glm.hpp>
#include <chaiscript/chaiscript.hpp>

namespace rpg {
  // Represents a scene in the game,
  // A setting for the characters to move around in and interact with.
  class Scene {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    Scene();
    virtual ~Scene();

    void update(float dt);
    void draw();

  private:
    // The background
    const char* m_backgroundFile;

    // The music
    const char* m_musicFile;

    // Script
    const char* m_scriptFile;

    // Entrances / Exits

    // List of entities to load here.

    // The camera position.
    glm::mat4 m_cameraTransform;
  };
}

#endif
