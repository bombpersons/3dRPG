#include <3drpg/graphics/window.hpp>

#include <string>

namespace rpg {
  Window::Window(int width, int height, bool fullscreen) {
    m_inputManager = new InputManager();
    m_device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, m_inputManager);
    if (!m_device) {
      throw "Error creating irrlicht device!\n";
    }

    // Create the graphics device.
    m_graphics = new Graphics(m_device);
    m_fullscreen = fullscreen;
  }

  Window::~Window() {
    if (m_graphics) {
      delete m_graphics;
      m_graphics = nullptr;
    }

    if (m_device) {
      delete m_inputManager;
      m_inputManager = nullptr;

      m_device->drop();
      m_device = nullptr;
    }
  }

  glm::ivec2 Window::getSize() {
    auto size = m_device->getVideoDriver()->getScreenSize();
    return glm::ivec2(size.Height, size.Width);
  }

  bool Window::getFullscreen() {
    return m_fullscreen;
  }

  void Window::setCaption(const char* caption) {
    std::string strCaption = caption;
    std::wstring wStrCaption(strCaption.length(), L' ');
    std::copy(strCaption.begin(), strCaption.end(), wStrCaption.begin());
    m_device->setWindowCaption(wStrCaption.c_str());
  }

  Graphics* Window::getGraphics() {
    return m_graphics;
  }

  InputManager& Window::getInput() {
    return *m_inputManager;
  }

  bool Window::run() {
    return m_device->run();
  }
}
