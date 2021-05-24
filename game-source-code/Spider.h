#ifndef SPIDER_H
#define SPIDER_H

#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp> 
#include <vector> 
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>

  using namespace sf;

/**
 * @class SpiderLoadError
 * @brief Used for the spider sprite error checking
 */

class SpiderLoadError {};

/**
 * @class Spider
 * @brief Used to display, control the movement and actions of the spider sprite
 */

class Spider {
  public:
    /**
     * @brief Configures the position and  random movement of the spider sprite. Also checks for loading error of the sprite. 
     */
    Spider();
  /**
   * @brief This movement function moves the spider sprite in random x and y directions
   * @param window: parameterized as a reference to the main window in the Game class
   */
  void move(RenderWindow & window);
  /**
   * @brief Draw function used to display spider on screen
   * @param window: parameterized as a reference to the main window in the Game class
   */
  void draw(RenderWindow & window);
  /**
   * @brief This function find the gloabal bounds of the sprite using the global bounds public member function in sf::Sprite
   * @return Returns the global bounds of the spider sprite
   */
  sf::FloatRect getGlobalBounds();
  /**
   * @brief Randomizes the directions the spider should move in
   */
  void UpdateSpeed();
  /**
   * @brief Returns the spider sprite current position on screen. Used for unit testing
   */
  sf::Vector2f getSpiderCoord();
  /**
   * @brief Removes spider off screen
   */
  void DeleteSpider();
  sf::Texture mSpiderTexture;
  CircleShape _spider;

  private:

  int x;
  int y;

};

#endif // SPIDER_H