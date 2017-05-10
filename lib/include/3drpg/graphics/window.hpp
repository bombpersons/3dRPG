#ifndef RPG_INCLUDED_WINDOW
#define RPG_INCLUDED_WINDOW

#include <3drpg/graphics/graphics.hpp>

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

    // Update the window.
    bool run();

  public:
    // Irrlicht stuff.
    irr::IrrlichtDevice* m_device;
    bool m_fullscreen;

    // The graphics device.
    Graphics* m_graphics;
  };
}

#endif
