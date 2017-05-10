#ifndef RPG_INCLUDED_GRAPHICS
#define RPG_INCLUDED_GRAPHICS

#include <irrlicht/irrlicht.h>

namespace rpg {
  class Graphics {
  public:
    Graphics(irr::IrrlichtDevice* device);
    virtual ~Graphics();

    // Draw the scene.
    void draw();

  private:
    irr::IrrlichtDevice* m_device;

    irr::video::IVideoDriver* m_driver;
    irr::scene::ISceneManager* m_smgr;
    irr::gui::IGUIEnvironment* m_guienv;
  };
}

#endif
