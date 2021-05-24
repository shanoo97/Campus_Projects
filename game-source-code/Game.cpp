#include "Game.h"
#include <iostream>

  Game::Game():
  mWindow(sf::VideoMode(WidthOfScreen, HeightOfScreen), "Centipede"), _player(), _shoot {
    vec
  }, _shrooms(), _one(), \
  collisions(_player, _spider, _one, _shrooms) {
    _stateOfGame = Game::ShowingSplashScreen;
    _NumberofLives = 3;
    _player.SetLives(_NumberofLives);
    
  }

void Game::run() {
  while (mWindow.isOpen()) {

    processEvents();
    render();
    update();

  }
}

const int Game::DecLives() {

  _player.SetLives(_NumberofLives - 1);
  _NumberofLives--;

  auto remain = _player.GetLives();
  clock.restart();
  return remain;
}

void Game::update() {

  _player.update();
  _player.Fire();

  if (CentiSpeed == 7) {
    _one.move(mWindow, _shrooms.Shrooms);
    CentiSpeed = 0;
  }
  CentiSpeed++;

  if (_one.CentiDestroyed()) {
    _stateOfGame = Game::GameOver;
  }

  if (collisions.PlayerDestroyed() || collisions.SpiderPlayer()) {
    if (clock.getElapsedTime().asSeconds() > 1) {
      DecLives();
    }
  }
  collisions.CentipedeBullet();
  _shrooms.update(mWindow);
  _spider.move(mWindow);
  collisions.MushroomBullet();
  collisions.SpiderBullet();
  collisions.SpiderMushroom();

}

void Game::render() {
  mWindow.clear();
  _shrooms.draw(mWindow);
  _player.draw(mWindow);
  _one.draw(mWindow);
  _spider.draw(mWindow);
  mWindow.display();
}

void Game::processEvents() {

  switch (_stateOfGame) {

  case Game::ShowingSplashScreen:
    {
      showSplashScreen();
      break;
    }
  case Game::Playing:
    {
      sf::Event event;
      while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          mWindow.close();
      }
      if (_player.GetLives() == 0 || _one.getPosition().y>mWindow.getSize().y+20) {
        _stateOfGame = Game::GameOver;
      }
      break;
    }
  case Game::GameOver:
    {
      mWindow.clear();
      mWindow.display();
      GameEnd();
      break;
    }
  default:
    assert(false);
  }
}

void Game::showSplashScreen() {
  splash.ShowSplash(mWindow);
  clock.restart();
  _stateOfGame = Game::Playing;
}

void Game::GameEnd() {
  splash.ShowGameOver(mWindow);
}

Game::~Game() {}