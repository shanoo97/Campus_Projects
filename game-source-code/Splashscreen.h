#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/graphics.hpp>

  /**
   * @class SplashScreenLoadError
   * @brief This class is used for error checking in case splash screen fails to load, it will throw this empty class
   */

  class SplashScreenLoadError {};

 /**
 * @class Splashscreen
 * @brief This class controls the displayment of the opening spash screen which gives instructions on how to play the game 
 * and the game over splash screen which is displayed when either the player loses all 3 lives or the centipede is destroyed.
 * No constructor is set, thus a default constructor is created
 */

class SplashScreen {
  public:
    /**
     * @brief ShowSplash displays the splash screen before the game begins
     * and sets the scale, position and checks for loading errors
     * The function triggers the start of the game when any key is pressed
     * @param Window: parameterized as a reference to the main window in the Game class to display the sprite
     */
  void ShowSplash(sf::RenderWindow & );
  /**
   * @brief ShowGameOver displays the splash screen when the player loses all 3 lives or the centipede is destroyed
   * The function closes the game when the escape key is pressed
   * @param Window: parameterized as a reference to the main window in the Game class to display the sprite
   */
  void ShowGameOver(sf::RenderWindow & );

  private:
  sf::Texture mSplashTexture;
  sf::Texture mGameOverTexture;
  sf::Sprite mSplashSprite;
  sf::Sprite mGameOverSprite;

};

#endif