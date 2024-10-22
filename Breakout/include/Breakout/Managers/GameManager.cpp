#include "GameManager.h"

#include <iostream>

GameManager::GameManager(sf::RenderWindow* window)
    : _window(window), _paddle(nullptr), _ball(nullptr), _brickManager(nullptr), _powerupManager(nullptr), _ui(nullptr),_pauseKeyReleased(false) ,_pause(false), _time(0.f), _lives(3), _levelComplete(false),
    _powerupInEffect({ none,0.f }), _timeLastPowerupSpawned(0.f)
{
    _font.loadFromFile("font/montS.ttf");
    _masterText.setFont(_font);
    _masterText.setPosition(_window->getSize().x/2, _window->getSize().y/2);
    _masterText.setCharacterSize(48);
    _masterText.setFillColor(sf::Color::Yellow);
}

void GameManager::initialize()
{
    _paddle = new Paddle(_window);
    _brickManager = new BrickManager(_window, this);
    _ball = new Ball(_window, 400.0f, this); 
    _powerupManager = new PowerupManager(_window, _paddle, _ball);
    _ui = new UI(_window, _lives, this);

    // Create bricks
    _brickManager->createBricks(5, 10, 80.0f, 30.0f, 5.0f);
}

void GameManager::update(float dt)
{
    _powerupInEffect = _powerupManager->getPowerupInEffect();
    _ui->updatePowerupText(_powerupInEffect);
    _powerupInEffect.second -= dt;
    

    if (_lives <= 0)
    {
        setMasterText("Game Over");
        return;
    }
    if (_levelComplete)
    {
        setMasterText("Level Complete");
        return;
    }
    // Pause
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if(_pauseKeyReleased)
        {
            _pause = !_pause;
            _pause ? setMasterText("Paused") : setMasterText("");
        }
        
        _pauseKeyReleased = false;
    }
    else
        _pauseKeyReleased = true;
    
    if (_pause)
        return;

    // timer.
    _time += dt;


    if (_time > _timeLastPowerupSpawned + POWERUP_FREQUENCY && rand()%700 == 0)      // TODO parameterise
    {
        _powerupManager->spawnPowerup();
        _timeLastPowerupSpawned = _time;
    }

    // move paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _paddle->moveRight(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _paddle->moveLeft(dt);

    // update everything 
    _paddle->update(dt);
    _ball->update(dt);
    _powerupManager->update(dt);
}

void GameManager::loseLife()
{
    _lives--;
    _ui->lifeLost(_lives);

    // TODO screen shake.
}

void GameManager::render()
{
    _paddle->render();
    _ball->render();
    _brickManager->render();
    _powerupManager->render();
    _window->draw(_masterText);
    _ui->render();
}

void GameManager::levelComplete()
{
    _levelComplete = true;
}

//this should be done on UI
void GameManager::setMasterText(std::string message)
{
    _masterText.setString(message);

    //If there no message, there is no need to update message position on screen
    if(message.empty())
        return;

    auto center = _masterText.getGlobalBounds().getSize()/2.0f;
    auto localBounds = center + _masterText.getLocalBounds().getPosition();
    _masterText.setOrigin(localBounds);
    auto currentViewSize = _window->getView().getSize();
    _masterText.setPosition(currentViewSize.x/2.0f, currentViewSize.y/2.0f);
}


sf::RenderWindow* GameManager::getWindow() const { return _window; }
UI* GameManager::getUI() const { return _ui; }


Paddle* GameManager::getPaddle() const { return _paddle; }
BrickManager* GameManager::getBrickManager() const { return _brickManager; }
PowerupManager* GameManager::getPowerupManager() const { return _powerupManager; }
