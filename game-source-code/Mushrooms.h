#ifndef MUSHROOMS_H
#define MUSHROOMS_H

#include <SFML/Graphics.hpp> 
#include <vector>

  /**
   * @class MushroomLoadError
   * @brief This class is used for error checking, in case any mushroom sprite fails to load, it will throw this empty class
   */

  class MushroomLoadError {};

/**
 * @class Mushrooms
 * @brief Used to randomly display multiple mushroom sprites at different positions of the screen 
 */

class Mushrooms {
  public:

    /**
     * @brief Default class constructor to intitialize the mushroom object automatically when it is created.
     * Used for error checking and for setting the mushroom sprite texture for the different stages of the mushroom 
     * as it gets shot by the bullet of the player
     */
    Mushrooms();
  /**
   * @brief Draws all the mushrooms present in the vector to the screen.
   * @param window: reference to the main window of the game class for diplay
   */
  void draw(sf::RenderWindow & );
  /**
   * @brief Limits the number of mushrooms by setting the size to 50 mushrooms and constantly ensures that more than 50 mushrooms are always on the screen
   * Stores the mushrooms in a vector  and sets the number of times a mushroom can get shot before deletion to 4 
   * @param window: makes use of the main window initialized in the game class to get the size of it for randomizing mushroom sprite positions
   */
  void update(sf::RenderWindow & );
  std::vector < sf::Sprite > Shrooms;
  std::vector < int > health;
  /**
   * @brief This function is called from the Collision class when a mushroom is shot by the players bullet. 
   * This function replaces the mushroom sprite at its current position to indicate a lower life state of the mushroom
   * @param b: These are integers used explicitly to find specific mushroom sprites situated at different elements in the Mushroom vector
   */
  void ChangeTexture(int b);
  /**
   * @brief This function is used to create a mushroom at the position of where a single centipede of the centipede train is shot. 
   * It creates a mushroom at the position and stores it in the vector of mushrooms with 4 life states.
   * @param x: Inputs the x position of the element of the centipede train that was shot
   * @param y: Inputs the y position of the element of the centipede train that was shot
   */
  void createMushroom(float x, float y);
  
  /**
   * @brief This function is called from the Collision class when a mushroom is shot by the players bullet. 
   * This function lowers the health of the selected mushroom
   * @param b: These are integers used explicitly to find specific mushroom sprites situated at different elements in the Mushroom vector
   */
  void DecreaseMushroom(int b);

  private:
  sf::Sprite mShroom;
  sf::Sprite mShroom2;
  sf::Sprite mShroom3;
  sf::Sprite mShroom4;
  sf::Texture mShroomTexture;
  sf::Texture mShroomTexture2;
  sf::Texture mShroomTexture3;
  sf::Texture mShroomTexture4;

};

#endif