#ifndef GAME_H
#define GAME_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "cassert"
#include "Player.h"
#include "Shoot.h"
#include "SplashScreen.h"
#include "Centipede.h"
#include "Mushrooms.h"
#include "Spider.h"
#include "Collision.h"

using namespace std;

#define WidthOfScreen 1200
#define HeightOfScreen 800

/**
 * @class Game
 * @brief Used as an engine for the incorporation of all the other classes to work concurrently
 * in orientating different objects from different classes to make up the entire game
 */

class Game {
  public:
    /**
     * @brief Default class constructor to intitialize all the other class constructors
     * It also sets the number of lives the player has and sets the game state so that the splash screen for instruction on how to play
     * the game is showed first, before the game actually begins 
     */
    Game();
  /**
   * @brief This function that loops processEvents(), render() and update() in the game class until the game ends
   */
  void run();
  ~Game();
  /**
   * @brief This function handles inputs from the user. It polls the game onto the application window and closes it
   * if a closed event occurs.
   * It controls the two splashcreens and the gameplay using the GameState enumeration, which allows the front end splash screen to appear first,
   * thereafter the actual game and, if by conditions set in the code, the back end splash screen.
   */
  void processEvents();
  /**
   * @brief The update functions controls the game logic of all the class objects. It uses various functions from different classes to allow 
   * us to manipulate and achieve the gameplay required.
   */
  void update();
  /**
   * @brief Displays the splash before the game begins, starts the game clock and switches the game state to start the game
   */
  void showSplashScreen();
  /**
   * @brief Displays the game over splash screen if certain conditions occur
   */
  void GameEnd();
  /**
   * @brief This function returns the number of remaining lives of the player sprite after collision with the centipede
   */
  const int DecLives();
  private:
    sf::RenderWindow mWindow;
  /**
   * @brief The render function displays all the sprites created through the objects of all the classes and renders them on the application window
   */
  void render();
  Player _player;
  Shoot _shoot;
  sf::Vector2f vec;
  enum GameState {
    ShowingSplashScreen,
    Playing,
    GameOver
  };
  GameState _stateOfGame;
  SplashScreen splash;
  sf::Clock clock;
  Mushrooms _shrooms;
  Centipede _one;
  Spider _spider;
  Collision collisions;
  int CentiSpeed = 0;
  int _NumberofLives;

};

#endif