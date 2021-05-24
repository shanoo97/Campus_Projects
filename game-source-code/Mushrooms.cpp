#include "Mushrooms.h"
#include <iostream> 
#include <stdlib.h> 
#include <time.h>

  using namespace std;

Mushrooms::Mushrooms() {
  if (!mShroomTexture.loadFromFile("resources/shroom.png")) {
    throw MushroomLoadError();
  }

  if (!mShroomTexture2.loadFromFile("resources/shroom2.png")) {
    throw MushroomLoadError();
  }

  if (!mShroomTexture3.loadFromFile("resources/shroom3.png")) {
    throw MushroomLoadError();
  }

  if (!mShroomTexture4.loadFromFile("resources/shroom4.png")) {
    throw MushroomLoadError();
  }

  srand(clock());
  mShroom.setTexture(mShroomTexture);
  mShroom2.setTexture(mShroomTexture2);
  mShroom3.setTexture(mShroomTexture3);
  mShroom4.setTexture(mShroomTexture4);

}

void Mushrooms::draw(sf::RenderWindow & window) {

  if (!Shrooms.empty()) {
    for (unsigned int i = 0; i < Shrooms.size(); i++) {
      window.draw(Shrooms[i]);
    }
  }
}

void Mushrooms::update(sf::RenderWindow & window) {

  while (Shrooms.size() < 50) {
    mShroom.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
    Shrooms.push_back(mShroom);
    health.push_back(4);
  }
}

void Mushrooms::ChangeTexture(int b) {

  if (health[b] == 3)
    Shrooms[b].setTexture(mShroomTexture4);

  if (health[b] == 2)
    Shrooms[b].setTexture(mShroomTexture2);

  if (health[b] == 1)
    Shrooms[b].setTexture(mShroomTexture3);
}

void Mushrooms::createMushroom(float x, float y) {

  mShroom.setPosition(x, y);
  Shrooms.push_back(mShroom);
  health.push_back(4);

}

void Mushrooms::DecreaseMushroom(int b){
    
    health[b] = health[b] - 1;
}