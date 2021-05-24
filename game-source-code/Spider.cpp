#include "Spider.h"

using namespace sf;

Spider::Spider() {

  if (!mSpiderTexture.loadFromFile("resources/spider.png")) {
    throw SpiderLoadError();
  }

  _spider.setRadius(5.f);
  _spider.setTexture( & mSpiderTexture);
  _spider.scale(4, 4);
  _spider.setPosition(500, 500);
  srand(clock());
  x = (rand() % 2) * pow(-1, rand() % 2);
  y = (rand() % 2) * pow(-1, rand() % 2);

}

void Spider::draw(RenderWindow & window) {
  window.draw(_spider);
}

void Spider::move(RenderWindow & window) {
  while (x == 0 || y == 0) {
    UpdateSpeed();
  }
  _spider.move(x, y);
  if (_spider.getPosition().x > window.getSize().x - 10)
    x *= -1;
  if (_spider.getPosition().x < 10)
    x *= -1;
  if (_spider.getPosition().y > window.getSize().y)
    y *= -1;
  if (_spider.getPosition().y < 300)
    y *= -1;

}

sf::FloatRect Spider::getGlobalBounds() {
  return _spider.getGlobalBounds();
}

void Spider::UpdateSpeed() {

  x = (rand() % 2) * pow(-1, rand() % 2);
  y = (rand() % 2) * pow(-1, rand() % 2);

}

sf::Vector2f Spider::getSpiderCoord() {
  sf::Vector2f currentCoord(_spider.getPosition().x, _spider.getPosition().y);
  return currentCoord;
}

void Spider::DeleteSpider() {
    
  _spider.setPosition(-100, -100);
    
}