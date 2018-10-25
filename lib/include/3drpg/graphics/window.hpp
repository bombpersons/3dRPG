#ifndef RPG_INCLUDED_WINDOW
#define RPG_INCLUDED_WINDOW

#include <3drpg/graphics/graphics.hpp>
#include <3drpg/input/input.hpp>

#include <irrlicht/irrlicht.h>
#include <glm/glm.hpp>

namespace rpg {
  class Window {
  public:
    Window(int width, int height, bool fullscreen);
    virtual ~Window();

    // Get the settings.
    glm::ivec2 getSize();
    bool getFullscreen();

    void setCaption(const char* caption);

    // Create the graphics device.
    Graphics* getGraphics();

    // Get the input manager;
    InputManager& getInput();

    // Update the window.
    bool run();

  public:
    // Irrlicht stuff.
    irr::IrrlichtDevice* m_device;
    bool m_fullscreen;

    // The graphics device.
    Graphics* m_graphics;

    // The input manager.
    InputManager* m_inputManager;
  };
}

#endif
