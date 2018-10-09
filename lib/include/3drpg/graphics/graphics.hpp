#ifndef RPG_INCLUDED_GRAPHICS
#define RPG_INCLUDED_GRAPHICS

#include <chaiscript/chaiscript.hpp>
#include <irrlicht/irrlicht.h>
#include <3drpg/graphics/drawable/drawable.hpp>

namespace rpg {
  class Graphics {
  public:
    static void InitChai(chaiscript::ChaiScript& chai);
  public:
    Graphics(irr::IrrlichtDevice* device);
    virtual ~Graphics();

    // Create a thing to draw.
    Drawable* createDrawable();
    void deleteDrawable(Drawable* drawable);

    void useNormalCamera();
    void useDebugCamera();

    // Draw the scene.
    void draw();

  private:
    irr::IrrlichtDevice* m_device;

    irr::video::IVideoDriver* m_driver;
    irr::scene::ISceneManager* m_smgr;
    irr::gui::IGUIEnvironment* m_guienv;

    irr::scene::ICameraSceneNode* m_camera;
  };
}

#endif
