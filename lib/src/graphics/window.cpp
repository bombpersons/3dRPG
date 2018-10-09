#include <3drpg/graphics/window.hpp>

#include <string>

namespace rpg {
  Window::Window(int width, int height, bool fullscreen) {
    m_device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);
    if (!m_device) {
      throw "Error creating irrlicht device!\n";
    }

    // Create the graphics device.
    m_graphics = new Graphics(m_device);
    m_fullscreen = fullscreen;

    Drawable* draw = m_graphics->createDrawable();
    draw->loadModel("data/models/test.obj");
  }

  Window::~Window() {
    if (m_graphics) {
      delete m_graphics;
      m_graphics = nullptr;
    }

    if (m_device) {
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

  bool Window::run() {
    return m_device->run();
  }
}
