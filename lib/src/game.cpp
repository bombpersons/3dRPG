#include <3drpg/game.hpp>

#include <chrono>
#include <sstream>
#include <cassert>

using namespace irr;

namespace rpg {
  Game::Game(const char* gamepath, const char* configpath) {
    // TODO load graphics settings from config.
    m_window = new Window(600, 800, false);
    m_graphics = m_window->getGraphics();

    // Thread hasn't started yet.
    m_runThread = nullptr;

    // Game path
    m_gamepath = gamepath;
    m_configpath = configpath;
    if (m_gamepath.empty()) m_gamepath = "data/gamescript/game/main.chai";
    if (m_configpath.empty()) m_configpath = "data/config.chai";

    // Attempt to evaluate the game script.
    getScript().evalFile(m_gamepath.c_str());
  }

  Game::~Game() {
    // Graphics belongs to the window, so is cleaned up there.
    if (m_window)
      delete m_window;
  }

  // Run the game script initialize function.
  void Game::init() {
    // Attempt to run the init function specified in the gamescript.
    getScript().eval("init();");
  }

  // Update and draw the game.
  void Game::update(float dt) {

  }
  void Game::draw(float dt) {
    // Draw the scene.
    m_graphics->draw();
  }

  // Start running the game (in a separate thread).
  void Game::run() {
    // If we are already running...
    if (m_runThread) {
      assert("Game is already running!");
      return;
    }

    // This is the function that will "run" the game.
    auto runFunc = [this]() {
      auto lastTime = std::chrono::high_resolution_clock::now();

      // Initialize game script.
      init();

      while (m_window->run()) {
        // Get the time difference.
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> dt = now - lastTime;
        lastTime = now;

        std::stringstream ss;
        ss << 1.0f / dt.count();
        m_window->setCaption(ss.str().c_str());

        // Update and draw.
        update(dt.count());
        draw(dt.count());
      }
    };

    // Create a thread to run this function in.
    m_runThread = new std::thread(runFunc);
  }

  // Wait for the game to finish.
  void Game::wait() {
    if (m_runThread) {
      m_runThread->join();
    }
  }
}
