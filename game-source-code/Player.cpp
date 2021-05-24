#include "Player.h"
#include <iostream> 
#include <memory>

  using namespace std;

Player::Player() {

  if (!mTexture.loadFromFile("resources/player.png")) {
    throw SpriteLoadingError();
  }

  if (!mLifeTexture1.loadFromFile("resources/life1.png")) {
    throw SpriteLoadingError();
  }

  if (!mLifeTexture2.loadFromFile("resources/life2.png")) {
    throw SpriteLoadingError();
  }

  if (!mLifeTexture3.loadFromFile("resources/life3.png")) {
    throw SpriteLoadingError();
  }

  mPlayer.setTexture(mTexture);
  mPlayer.setPosition(600.f, 650.f);
  mPlayer.scale(0.15, 0.15);

  mLife1.setTexture(mLifeTexture1);
  mLife1.setPosition(100, 50);
  mLife1.scale(0.6, 0.6);

  mLife2.setTexture(mLifeTexture2);
  mLife2.setPosition(100, 50);
  mLife2.scale(0.6, 0.6);

  mLife3.setTexture(mLifeTexture3);
  mLife3.setPosition(100, 50);
  mLife3.scale(0.6, 0.6);

  ShootKeyPressed = false;
}

void Player::Fire() {
  bool isSpaceButtonPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
  if (!isSpaceButtonPressed && ShootKeyPressed){
    CreateBullet();
                    }
  ShootKeyPressed = isSpaceButtonPressed;
}

void Player::CreateBullet(){
    mBullets.push_back(new Shoot(sf::Vector2f(mPlayer.getPosition().x + 10, mPlayer.getPosition().y)));
    }

void Player::draw(sf::RenderWindow & window) {
  window.draw(mPlayer);
  if (!mBullets.empty()) {
    for (unsigned int i = 0; i < mBullets.size(); i++)
      mBullets.at(i) -> draw(window);
  }

  if (life == 3) {
    window.draw(mLife3);
  }

  if (life == 2) {
    window.draw(mLife2);
  }

  if (life == 1) {
    window.draw(mLife1);
  }
}

void Player::moveLeft() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    MovingLeft();
  }
}

void Player::moveRight() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    MovingRight();
  }
}

void Player::moveDown() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    MovingDown();
  }
}

void Player::moveUp() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    MovingUp();
  }
}

void Player::MovingRight() {
  auto movingRight = mPlayer.getPosition().x + PlayerSpeedx;
  auto y = mPlayer.getPosition().y;
  mPlayer.setPosition(movingRight, y);
}

void Player::MovingLeft() {
  auto movingLeft = mPlayer.getPosition().x - PlayerSpeedx;
  auto y = mPlayer.getPosition().y;
  mPlayer.setPosition(movingLeft, y);
}

void Player::MovingUp() {
  if (mPlayer.getPosition().y > 600) {
    auto movingUp = mPlayer.getPosition().y + PlayerSpeedy;
    auto x = mPlayer.getPosition().x;
    mPlayer.setPosition(x, movingUp);
  }
}

void Player::MovingDown() {
  if (mPlayer.getPosition().y < 800) {
  auto movingDown = mPlayer.getPosition().y - PlayerSpeedy;
  auto x = mPlayer.getPosition().x;
  mPlayer.setPosition(x, movingDown);
  }
}

void Player::update() {

  moveUp();
  moveDown();
  moveLeft();
  moveRight();

  if (!mBullets.empty()) {
    for (unsigned int i = 0; i < mBullets.size(); i++) {
      mBullets.at(i) -> update();

      if (mBullets.at(i) -> getPosition().y <= 0)
        mBullets.erase(mBullets.begin() + i);
    }
  }

}

sf::Vector2f Player::getPosition() {
  sf::Vector2f position(mPlayer.getPosition());
  return position;
}

sf::Vector2f Player::getPlayerCoord() {
  sf::Vector2f currentCoord(mPlayer.getPosition().x, mPlayer.getPosition().y);
  return currentCoord;
}

sf::FloatRect Player::getGlobalBounds() {
  return mPlayer.getGlobalBounds();
}

void Player::SetLives(const int _lives) {

  life = _lives;

}

unsigned int Player::GetLives() const {

  return life;

}