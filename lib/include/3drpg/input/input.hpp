#ifndef INPUT_INCLUDED
#define INPUT_INCLUDED
#include <irrlicht/irrlicht.h>

namespace rpg {
  class InputManager : public irr::IEventReceiver {
  public:
    InputManager();
    virtual ~InputManager();

    bool OnEvent(const irr::SEvent& event) override;

    // Called every frame.
    void update();

  private:
    bool m_currentKeyDown[irr::KEY_KEY_CODES_COUNT];
    bool m_oldKeyDown[irr::KEY_KEY_CODES_COUNT];

    bool isKeyDown(irr::EKEY_CODE keyCode);
    bool wasKeyPressed(irr::EKEY_CODE keyCode);
    bool wasKeyReleased(irr::EKEY_CODE keyCode);
  };
}

#endif
