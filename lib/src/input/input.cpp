#include <3drpg/input/input.hpp>

namespace rpg {
  InputManager::InputManager() {
    memset(m_currentKeyDown, 0, sizeof(m_currentKeyDown));
    memset(m_oldKeyDown, 0, sizeof(m_oldKeyDown));
  }

  InputManager::~InputManager() {

  }

  bool InputManager::OnEvent(const irr::SEvent& event) {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
      m_currentKeyDown[event.KeyInput.Key] == event.KeyInput.PressedDown;
    }

    return false;
  }

  void InputManager::update() {
    // Copy the current keys into the old keys.
    memcpy(m_oldKeyDown, m_currentKeyDown, sizeof(m_currentKeyDown));
  }

  bool InputManager::isKeyDown(irr::EKEY_CODE keyCode) {
    return m_currentKeyDown[keyCode];
  }

  bool InputManager::wasKeyPressed(irr::EKEY_CODE keyCode) {
    return m_currentKeyDown[keyCode] && !m_oldKeyDown[keyCode];
  }

  bool InputManager::wasKeyReleased(irr::EKEY_CODE keyCode) {
    return !m_currentKeyDown[keyCode] && m_oldKeyDown[keyCode];
  }
}
