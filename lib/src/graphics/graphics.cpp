#include <3drpg/graphics/graphics.hpp>

namespace rpg {
  Graphics::Graphics(irr::IrrlichtDevice* device) {
    m_device = device;
    m_driver = m_device->getVideoDriver();
    m_smgr = m_device->getSceneManager();
    m_guienv = m_device->getGUIEnvironment();

    m_smgr->addCameraSceneNode(0, irr::core::vector3df(0, 30, -40), irr::core::vector3df(0, 5, 0));
  }

  Graphics::~Graphics() {
    // Window handles the device and what not, so don't delete anything here.
  }

  void Graphics::draw() {
    m_driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
    m_smgr->drawAll();
    m_guienv->drawAll();
    m_driver->endScene();
  }
}
