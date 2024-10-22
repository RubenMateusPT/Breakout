#pragma once
#include <SFML/Graphics.hpp>
#include "Breakout/CONSTANTS.h"
#include "Breakout/Paddle/Paddle.h"
#include "Breakout/Ball/Ball.h"
#include "Breakout/Managers/BrickManager.h"
#include "Breakout/Managers/PowerupManager.h"
#include "Breakout/UI/UI.h"


class GameManager {
public:
    GameManager(sf::RenderWindow* window);
    void initialize();
    void update(float dt);
    void loseLife();
    void render();
    void levelComplete();
    void powerupEffect(POWERUPS pu, float t);

    Paddle* getPaddle() const;
    BrickManager* getBrickManager() const;
    PowerupManager* getPowerupManager() const;
    sf::RenderWindow* getWindow() const;
    UI* getUI() const;


private:
    bool _pauseKeyReleased;
    bool _pause;
    float _time;
    float _timeLastPowerupSpawned;
    int _lives;
    bool _levelComplete;
    std::pair<POWERUPS, float> _powerupInEffect;

    sf::Font _font;
    sf::Text _masterText;

    sf::RenderWindow* _window;
    Paddle* _paddle;
    Ball* _ball;
    BrickManager* _brickManager;
    PowerupManager* _powerupManager;
    UI* _ui;
    
    static constexpr float POWERUP_FREQUENCY = 7.5f;    // time between minimum powerup spawn
    static constexpr int POWERUP_MAX_RANDOMIZE_FREQUENCY = 700; // a random max time for powerup to spawn (based on minumum time

    //this should be done on UI
    void setMasterText(std::string message);

    //this should be in a screen effect class
    //Screen Shake effect
    static constexpr float SCREEN_SHAKE_OFFSET = 25.0f; // Controls how far the shake/view will go offscreen
    static constexpr float SCREEN_SHAKE_SPEED = 15; // Controls how fast the view moves to the offset
    static constexpr int MAX_SCREEN_SHAKES = 5; // Tells how many times the view will move
    
    int _currentScreenShakes = 0; // Keeps track on how many shakes were done during start of animation
    bool _screenShakeIsActive = false; // Flag that tells if the screen shake should be playing

    //play a screen shake effect
    void doScreenShakeEffect(float dt);
};
