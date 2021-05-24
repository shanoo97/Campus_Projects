#include "SplashScreen.h"
#include <iostream>

  void SplashScreen::ShowSplash(sf::RenderWindow & splashWindow) {

    if (mSplashTexture.loadFromFile("resources/splashscreen.png") != true) {
      throw SplashScreenLoadError();
    }

    mSplashSprite.setTexture(mSplashTexture);
    mSplashSprite.scale(0.8, 0.8);
    mSplashSprite.setPosition(220.f, 100.f);
    splashWindow.draw(mSplashSprite);
    splashWindow.display();

    sf::Event splashEvent;
    while (true) {
      while (splashWindow.pollEvent(splashEvent)) {
        if (splashEvent.type == sf::Event::EventType::KeyPressed || splashEvent.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || splashEvent.type == sf::Event::EventType::Closed) {
          return;
        }
      }
    }
  }

void SplashScreen::ShowGameOver(sf::RenderWindow & splashWindow) {
  if (mGameOverTexture.loadFromFile("resources/GameOver.png") != true) {
    throw SplashScreenLoadError();
  }

  mGameOverSprite.setTexture(mGameOverTexture);
  mGameOverSprite.scale(0.8, 0.8);
  mGameOverSprite.setPosition(220.f, 100.f);
  splashWindow.draw(mGameOverSprite);
  splashWindow.display();

  while (splashWindow.isOpen()) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      splashWindow.close();
    }
  }
}