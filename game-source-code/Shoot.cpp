#include "Shoot.h"
#include <iostream>

  using namespace std;

Shoot::Shoot(sf::Vector2f playerPosition) {
  if (!mShootTexture.loadFromFile("resources/bullet.png")) {
    throw BulletSpriteLoadError();
  }
  mBullet.setPosition(playerPosition.x, playerPosition.y);
  mBullet.setRadius(10);
  mBullet.setOrigin(10, 10);
  mBullet.setTexture( & mShootTexture);
}

void Shoot::draw(sf::RenderWindow & window) {
  window.draw(mBullet);
}

void Shoot::update() {

  mBullet.move(0.f, -10.f);

}

sf::Vector2f Shoot::getPosition() {
  sf::Vector2f position(mBullet.getPosition());
  return position;
}

sf::FloatRect Shoot::getGlobalBounds() {
  sf::FloatRect bounds(mBullet.getGlobalBounds());
  return bounds;

}