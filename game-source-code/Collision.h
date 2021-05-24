#ifndef COLLISION_H
#define COLLISION_H

#include <iostream> 
#include "Player.h"
#include "Spider.h"
#include "Centipede.h"
#include "Mushrooms.h"

/**
 * @class Collision 
 * @brief This class is used to handle all collision detection and object interaction throughout the game. All collisions are found here and
 * are then called to their respected classes through the use of pointers. 
 */
class Collision {

  public:
    /**
     * @brief Constructor to allow access to all other class objects being pointed to
     * @param p: Deference pointer to player object
     * @param s: Deference pointer to spider object
     * @param c: Deference pointer to centipede object
     * @param m: Deference pointer to mushroom object
     */
    Collision(Player &p, Spider &s, Centipede &c, Mushrooms &m);
  /**
   * @brief This function will return a boolean to indicated whether a collision between the spider and player has occured
   */
  bool SpiderPlayer();
  /**
   * @brief This function will return a bolean to indicated whether a collision between any segment of the centipede and the player has occured
   */
  bool PlayerDestroyed();
  /**
   * @brief This function checks for collision detection between the player's bullet and the mushroom. When there is a collision,
   * this function erases the bullet from the vector of bullet sprites. It also calls the ChangeTexture function from the mushroom class to change
   * and the mushroom sprite. It will then erase the mushroom from the vector of mushroom sprites if the mushroom is shot four times.
   */
  void MushroomBullet();
  /**
   * @brief CentipedeBullet checks for collisions between any segment in the centipede train and the player's bullet,
   * and then calls the SplitCentipede function and erases the bullet from the vector of bullet sprites
   */
  void CentipedeBullet();
  /**
   * @brief This function is called when a collision from CentipedeBullet occurs. Thereafter, the function calls other member functions from
   * respective classes to replace the centipede segment with a mushroom and erase the centipede element from the vector of centipedes.
   * @param a: size of the vector of centipedes (multiple)
   * @param b: size of the vector stored in the first element of the vector of centipedes (multiple)
   */
  void SplitCentipede(int a, int b);
  /**
   * @brief This function is called in SplitCentipede and is responsible for creating two smaller centipedes 
   * from the larger one that was previously shot
   * @param a: size of the vector of centipedes (multiple)
   * @param b: size of the vector stored in the first element of the vector of centipedes (multiple)
   */
  void AddCentipede(int a, int b);
  /**
   * @brief Used to check a collision with the player's bullet. If a collision is made, the spider sprite is relocated off the screen to mimic a 
   * destroyed sprite. After a certain time set by a timer variable the spider reappears to mimic many spider sprites. 
   */
  void SpiderBullet();
  /**
   * @brief This function checks for the collision of a spider and a mushroom at random times, resulting in the spider eating several mushrooms 
   * on occasion. The spider is set to eat partial lives of the mushroom sprite.
   */
  void SpiderMushroom();

  private:
  Player * player;
  Spider * spider;
  Centipede * centipede;
  Mushrooms * mushrooms;
  int timer = 0;
  bool previouslyshot = false;

};

#endif // COLLISION_H