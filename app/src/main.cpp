#include <3drpg/world.hpp>

#include <irrlicht/irrlicht.h>
using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(int argc, char** argv) {
  IrrlichtDevice* device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16, false, false, false, 0);
  if (!device) {
    printf("Error creating irrlicht device!\n");
    return 1;
  }

  device->setWindowCaption(L"Hello World!");

  IVideoDriver* driver = device->getVideoDriver();
  ISceneManager* smgr = device->getSceneManager();
  IGUIEnvironment* guienv = device->getGUIEnvironment();

  smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

  while (device->run()) {
    driver->beginScene(true, true, SColor(255, 100, 101, 140));

    smgr->drawAll();
    guienv->drawAll();

    driver->endScene();
  }

  device->drop();

  testfunction();
  return 0;
}
