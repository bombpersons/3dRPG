#ifndef RPG_INCLUDED_GAME
#define RPG_INCLUDED_GAME

#include <chaiscript/chaiscript.hpp>
#include <irrlicht/irrlicht.h>
#include <thread>

#include <3drpg/graphics/window.hpp>
#include <3drpg/graphics/graphics.hpp>
#include <3drpg/scene/sceneManager.hpp>
#include <3drpg/state/stateManager.hpp>
#include <3drpg/script/scriptManager.hpp>

namespace rpg {
  class Game {
  public:
    Game(const char* gamepath="", const char* config="");
    virtual ~Game();

    // Initialize the game from script.
    void init();

    // Destroy the game.
    void destroy();

    // Update and draw the game.
    void update(float dt);
    void draw(float dt);

    // Window and renderer.
    Window& getWindow() { return *m_window; }
    Graphics& getGraphics() { return *m_graphics; }

    // Get managers
    StateManager& getState() { return *m_stateManager; }
    SceneManager& getScene() { return *m_sceneManager; }
    ScriptManager& getScript() { return m_scriptManager; }

    // Start running the game (in a separate thread).
    void run();

    // Wait for the game to finish.
    void wait();

    // Bind script functions specifically for this game instance.
    void initChai(chaiscript::ChaiScript& chai);

  private:
    // Thread running the game.
    std::thread* m_runThread;

    // Window and graphics.
    Window* m_window;
    Graphics* m_graphics;

    // Managers
    SceneManager* m_sceneManager;
    StateManager* m_stateManager;
    ScriptManager m_scriptManager;

    // Path to the folder for the game we are running.
    std::string m_gamepath;
    std::string m_configpath;
  };
}

#endif
