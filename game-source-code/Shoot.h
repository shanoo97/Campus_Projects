#ifndef SHOOT_H
#define SHOOT_H

#include <SFML/Graphics.hpp >

  /**
   * @class BulletSpriteLoadError
   * @brief This class is used for error checking in case any of the bullet sprites fails to load upon creating,
   * it will throw this empty class
   */

  class BulletSpriteLoadError {};

/**
 * @class Shoot
 * @brief This class is used for to control the creation and movement of bullets from the player
 */

class Shoot {
  public:
    /**
     * @brief Class constructor to intitialize the shoot object with a certain size and position accoriding to that of the player,
     * to display the bullet at the players current position
     * and to check if there are any sprite loading errors for the bullet
     * @param sf::Vector2f: is used to get the position of the player as seen in
     * the fire member function in the player class where a shoot object is dynamically created using the position of the player
     */
    Shoot(sf::Vector2f);
  /**
   * @brief Draw function displays the bullet sprite on screen
   */
  void draw(sf::RenderWindow & );
  /**
   * @brief Update moves the bullet sprite upwards upon creation of the shoot object
   */
  void update();
  /**
   * @brief Gets the position of the bullet sprite so that we can determine when it reaches the top of the screen 
   * @return Returns the position of the bullet sprite using sf::Sprites getPosition public memeber function
   */
  sf::Vector2f getPosition();
  /**
   * @brief Gets the bounds of the bullet sprite so that we can determine whether it hits a mushroom for deletion
   * sf::FloatRect is used to access all the pixels of the sprite in order to get accurate collisions
   * @return Returns the global bounds of the bullet sprite entity using the getGlobalBounds public memeber function
   */
  sf::FloatRect getGlobalBounds();

  private:
  sf::CircleShape mBullet;
  sf::Texture mShootTexture;

};

#endif