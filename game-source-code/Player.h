#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "Shoot.h"

using namespace std;

/**
 * @class SpriteLoadingError
 * @brief This class is used for error checking in case any sprite fails to load it will throw this empty class
 */

class SpriteLoadingError {};

/**
 * @class Player
 * @brief The player class is responsible for player rendering, movement and acts as a manager for the Shooting class.
 * It also contains member functions used specifically for testing, collision detection and for displaying and controlling life sprites
 */

class Player {
  public:
    /**
     * @brief Default class constructor to intitialize the player object automatically when it is created.
     * It is also used for sprite loading error checking and displays the player and life sprites at the correct positions and with the right size
     */
    Player();
  /**
   * @brief Draw function used to display player on screen, also controls the life sprite and displays it according to the number of lives remaining
   * @param window: parameterized as a reference to the main window in the Game class
   */
  void draw(sf::RenderWindow & );
  /**
   * @brief Gets the players position on screen
   * @return Returns the players position 
   */
  sf::Vector2f getPosition();
  /**
   * @brief The moveLeft, moveRight, moveUp and moveDown functions check for player input 
   * on the keyboard and call their resepctive functions when certain keys are pressed
   */
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
  /**
   * @brief The MovingLeft, MovingRight, MovingUp and Movingdown functions are called if certain keys are pressed.
   *  These functions move the player sprite according to the users input and is dependant on the PlayerSpeedx and PlayerSpeedy data member 
   *  which controls the speed of movement
   */
  void MovingLeft();
  void MovingRight();
  void MovingUp();
  void MovingDown();
  /**
   * @brief Continuously updates the movement of the player and checks the position 
   * and deletion of the bullet sprties which are stored in a vector
   */
  void update();
  /**
   * @brief Gets the local bounds of the sprite entity
   * @return Returns the global bounds of the player sprite
   */
  sf::FloatRect getGlobalBounds();
  /**
   * @brief Gets the position of the sprite entity
   * @return Returns the x and y position
   */
  sf::Vector2f getPlayerCoord();
  /**
   * @brief The fire functions checks if the space bar is pressed and dynamically creates an object of the Shoot class
   * at the current positon of the player sprite using the getPosition public member function
   */
  void Fire();
  /**
   * @brief Vector that stores the bullet sprites
   */
  vector < Shoot* > mBullets;
  /**
   * @brief The GetLives function is used to keep track of the number of remaining lives the player has
   * @return Returns the number of lives
   */
  unsigned int GetLives() const;
  /**
   * @brief The SetLives function is used to set an initial number of lives for the player which in this case is 3 
   * and is set the the game class constructor for when the game begins
   */
  void SetLives(const int);
  sf::Sprite mPlayer;
  /**
   * @brief This function is explicitly created for unit testing to push back a bullet into the vecotr of bullet sprites
   */
  void CreateBullet();
  
private:
  
  sf::Texture mTexture;
  const float PlayerSpeedx = 3.f;
  const float PlayerSpeedy = -3.f;
  bool ShootKeyPressed = false;
  sf::Sprite mLife1;
  sf::Texture mLifeTexture1;
  sf::Sprite mLife2;
  sf::Texture mLifeTexture2;
  sf::Sprite mLife3;
  sf::Texture mLifeTexture3;
  sf::Clock mLifeClock;
  int life;

};

#endif