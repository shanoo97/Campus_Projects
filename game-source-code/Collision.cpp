#include "Collision.h"
#include "time.h"

Collision::Collision(Player &p, Spider &s, Centipede &c, Mushrooms &m) {
  player = &p;
  spider = &s;
  centipede = &c;
  mushrooms = &m;
}

bool Collision::SpiderPlayer() {

  if (spider -> getGlobalBounds().intersects(player -> getGlobalBounds())) {
    return true;
  } else
    return false;
}

bool Collision::PlayerDestroyed() {

  for (unsigned int i = 0; i < centipede -> multiple.size(); i++) {
    for (unsigned int a = 0; a < centipede -> multiple[i].size(); a++) {
      if (centipede -> multiple[i][a].getGlobalBounds().intersects(player -> getGlobalBounds())) {
        return true;
      }
    }
  }
  return false;
}

void Collision::MushroomBullet() {

  for (unsigned int c = 0; c < player -> mBullets.size(); c++) {

    for (unsigned int b = 0; b < mushrooms -> Shrooms.size(); b++) {

      if (mushrooms -> Shrooms[b].getGlobalBounds().intersects(player -> mBullets.at(c) -> getGlobalBounds())) {

        if (player -> mBullets.size() > 0) {
          player -> mBullets.erase(player -> mBullets.begin() + c);
        }

        mushrooms -> DecreaseMushroom(b);
        mushrooms -> ChangeTexture(b);

        if (mushrooms -> health[b] == 0) {
          mushrooms -> Shrooms.erase(mushrooms -> Shrooms.begin() + b);
          mushrooms -> health.erase(mushrooms -> health.begin() + b);
        }
        break;
      }
    }
  }
}

void Collision::CentipedeBullet() {

  if (!centipede -> multiple.empty() && !player -> mBullets.empty()) {

    for (unsigned int a = 0; a < centipede -> multiple.size(); a++) {

      for (unsigned int b = 0; b < centipede -> multiple[a].size(); b++) {

        for (unsigned int c = 0; c < player -> mBullets.size(); c++) {

          if (centipede -> multiple[a][b].getGlobalBounds().intersects(player -> mBullets.at(c) -> getGlobalBounds())) {

            player -> mBullets.erase(player -> mBullets.begin() + c);
            SplitCentipede(a, b);
            break;

          }
        }
      }
    }
  }
}

void Collision::SplitCentipede(int a, int b) {

  auto posx = centipede -> multiple[a][b].getPosition().x;
  auto posy = centipede -> multiple[a][b].getPosition().y;
  mushrooms -> createMushroom(posx, posy);
  AddCentipede(a, b);
  centipede -> multiple[a].erase(centipede -> multiple[a].begin(), centipede -> multiple[a].begin() + b + 1);

  if (centipede -> multiple[a].empty()) {
    centipede -> multiple.erase(centipede -> multiple.begin() + a);
    centipede -> control.erase(centipede -> control.begin() + a);
  }
}

void Collision::AddCentipede(int a, int b) {

  auto previousdir = centipede -> control[a];
  auto posx = centipede -> multiple[a][b].getPosition().x;
  auto posy = centipede -> multiple[a][b].getPosition().y;

  std::vector < CircleShape > worm;
  int e = 0;
  if (previousdir == 0) {
    e = -15;
  } else e = 15;

  for (float i = b; i >= 1; i--) {
    centipede -> body.setPosition((posx + i * e), posy);
    worm.push_back(CircleShape(centipede -> body));
  }

  if (!worm.empty()) {
    centipede -> multiple.push_back(worm);
    centipede -> movedown(centipede -> multiple.size() - 1);
    if (previousdir == 0)
      centipede -> control.push_back(2);
    else centipede -> control.push_back(0);
  }
}

void Collision::SpiderBullet() {

  for (unsigned int c = 0; c < player -> mBullets.size(); c++) {
    if (spider -> getGlobalBounds().intersects(player -> mBullets.at(c) -> getGlobalBounds())) {
      spider -> DeleteSpider();
      timer = 1000;
      previouslyshot = true;
    }
  }
  if (timer < 0 && previouslyshot == true) {
    spider -> _spider.setPosition(500, 500);
    spider -> UpdateSpeed();
    previouslyshot = false;
  }
  timer--;
}

void Collision::SpiderMushroom() {

  srand(clock());
  if ((rand() % 100) > 90) {
    for (unsigned int b = 0; b < mushrooms -> Shrooms.size(); b++) {

      if (mushrooms -> Shrooms[b].getGlobalBounds().intersects(spider -> getGlobalBounds())) {
        mushrooms -> health[b] = mushrooms -> health[b] - 1;
        mushrooms -> ChangeTexture(b);
        if (mushrooms -> health[b] == 0) {
          mushrooms -> Shrooms.erase(mushrooms -> Shrooms.begin() + b);
          mushrooms -> health.erase(mushrooms -> health.begin() + b);
        }
      }
    }
  }
}