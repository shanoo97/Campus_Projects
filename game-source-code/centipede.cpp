#include "Centipede.h"
#include <iostream>

  Centipede::Centipede() {

    body.setRadius(10.f);
    body.setFillColor(Color::Red);
    std::vector < CircleShape > worm;

    for (float i = 0; i < 15; i++) {
      body.setPosition((i * 15), 0);
      worm.push_back(CircleShape(body));
    }
    multiple.push_back(worm);
    control.push_back(0);

  }

void Centipede::draw(RenderWindow & window) {

  for (unsigned int i = 0; i < multiple.size(); i++) {
    for (unsigned int j = 0; j < multiple[i].size(); j++) {
      window.draw(multiple[i][j]);
    }
  }
}

void Centipede::follow(int headx, int heady, int i) {
  for (int x = multiple[i].size() - 1; x > 0; x--) {
    int oldx = multiple[i][x - 1].getPosition().x;
    int oldy = multiple[i][x - 1].getPosition().y;
    multiple[i][x - 1].setPosition(headx, heady);
    headx = oldx;
    heady = oldy;
  }
}

void Centipede::move(RenderWindow & window, std::vector < Sprite > & Shrooms) {

  for (unsigned int i = 0; i < multiple.size(); i++) {

    if (control[i] == 0) {
      moveright(i);
      if (bumpshroom(Shrooms, i)) {
        movedown(i);
        control[i] = 2;
      }
      if (multiple[i][multiple[i].size() - 1].getPosition().x >= window.getSize().x - 20)
        control[i] = 1;
    }

    if (control[i] == 1) {
      movedown(i);
      if (multiple[i][multiple[i].size() - 1].getPosition().x >= window.getSize().x - 20)
        control[i] = 2;
      if (multiple[i][multiple[i].size() - 1].getPosition().x <= 0)
        control[i] = 0;
    }

    if (control[i] == 2) {
      moveleft(i);
      if (bumpshroom(Shrooms, i)) {
        movedown(i);
        control[i] = 0;
      }
      if (multiple[i][multiple[i].size() - 1].getPosition().x <= 0)
        control[i] = 1;
    }

  }
}

void Centipede::moveright(int i) {

  int headx = multiple[i][multiple[i].size() - 1].getPosition().x;
  int heady = multiple[i][multiple[i].size() - 1].getPosition().y;

  multiple[i][multiple[i].size() - 1].move(15.f, 0.f);
  follow(headx, heady, i);

}

void Centipede::moveleft(int i) {

  int headx = multiple[i][multiple[i].size() - 1].getPosition().x;
  int heady = multiple[i][multiple[i].size() - 1].getPosition().y;

  multiple[i][multiple[i].size() - 1].move(-15.f, 0.f);
  follow(headx, heady, i);

}

void Centipede::movedown(int i) {

  int headx = multiple[i][multiple[i].size() - 1].getPosition().x;
  int heady = multiple[i][multiple[i].size() - 1].getPosition().y;

  multiple[i][multiple[i].size() - 1].move(0.f, 17.f);
  follow(headx, heady, i);

}

bool Centipede::CentiDestroyed() {
  if (multiple.empty())
    return true;
  else
    return false;
}

bool Centipede::bumpshroom(std::vector < Sprite > & Shrooms, int i) {
  for (unsigned int a = 0; a < Shrooms.size(); a++) {
    if (multiple[i][multiple[i].size() - 1].getGlobalBounds().intersects(Shrooms[a].getGlobalBounds())) {
      return true;
    }
  }
  return false;
}

sf::Vector2f Centipede::getPosition() {
  sf::Vector2f pos(multiple[0][multiple[0].size() - 1].getPosition());
  return pos;
}



