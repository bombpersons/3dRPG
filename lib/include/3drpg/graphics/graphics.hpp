#ifndef RPG_INCLUDED_GRAPHICS
#define RPG_INCLUDED_GRAPHICS

#include <irrlicht/irrlicht.h>
#include <3drpg/graphics/drawable/drawable.hpp>

namespace rpg {
  class Graphics {
  public:
    Graphics(irr::IrrlichtDevice* device);
    virtual ~Graphics();

    // Create a thing to draw.
    Drawable* createDrawable();
    void deleteDrawable(Drawable* drawable);

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
