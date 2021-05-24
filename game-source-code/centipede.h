#ifndef CENTIPEDE_H 
#define CENTIPEDE_H

#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp> 
#include <vector>
#include "Player.h"
#include "Mushrooms.h"
#include "Spider.h"

using namespace sf;

/**
 * @class Centipede
 * @brief Used for the creation of centipede and centipede movement. It further includes centipede-mushroom collisions. This class
 * is the sole operation of the centipede object and any changes in operation is based here
 */

class Centipede {
  public:
    /**
     * @brief Configures the centipede and initializes the direction the centipede should move in. Stores the centipede segments into a vector
     */
    Centipede();
  /**
   * @brief Draw function used to display each centipede segment on screen
   * @param window: parameterized as a reference to the main window in the Game class
   */
  void draw(RenderWindow & window);
  /**
   * @brief This function iterates through each element of the centipede vector and calls the necessary move functions depending on the original direction
   * and which mushroom sprite it collides with
   * @param window: parameterized as a reference to the main window in the Game class
   * @param Shrooms: The vector of mushroom sprites are passed through to find which mushroom element that the centipede collides with to decide what
   * directions are needed
   */
  void move(RenderWindow & window, std::vector < Sprite > & Shrooms);
  /**
   * @brief Used to change the direction of the centipedes that follow the head to form a centipede train
   * @param headx: x coordinate of the head of the train
   * @param heady: y coordinate of the head of the train
   * @param i: Integer used to iterate through the vector of centipedes.
   */
  void follow(int headx, int heady, int i);
  /**
   * @brief The following move function are called from the move function depending on certain instances that happen through the gameplay. They change the 
   * position of the head, thereafter it calls the follow function to get the other centipede parts to follow suit.
   * @param i: Integer used to iterate through the vector of centipedes.
   */
  void moveright(int i);
  /**
   * @brief The following move function are called from the move function depending on certain instances that happen through the gameplay. They change the 
   * position of the head, thereafter it calls the follow function to get the other centipede parts to follow suit.
   * @param i: Integer used to iterate through the vector of centipedes.
   */
  void moveleft(int i);
  /**
   * @brief The following move function are called from the move function depending on certain instances that happen through the gameplay. They change the 
   * position of the head, thereafter it calls the follow function to get the other centipede parts to follow suit.
   * @param i: Integer used to iterate through the vector of centipedes.
   */
  void movedown(int i);
  /**
   * @brief Returns a boolean if a collision between the head of a centipede train collides with a mushroom. used for unit testing and
   * for the operation of certain functions regarding collision detection
   * @param Shrooms: Vector of mushroom sprites is passed through to find the actual mushroom element at which a collision was made with
   * @param i: Integer used to iterate through the vector of centipedes.
   */
  bool bumpshroom(std::vector < Sprite > & Shrooms, int i);
  /**
   * @brief Used for unit testing and to end the game. Returns a boolean if the vector of centipede sprites is empty.
   */
  bool CentiDestroyed();
  /**
   * @brief Used to return the current postion of the centipede head for unit testing and for certain function regarding collisions
   */
  sf::Vector2f getPosition();

  std::vector < std::vector < CircleShape >> multiple;
  vector < int > control;
  CircleShape body;

};

#endif // CENTIPEDE_H