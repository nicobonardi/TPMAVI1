#pragma once
#include "lib.h"

#ifndef GAMEOVER_H
#define GAMEOVER_H

class GameOver {
public:
    GameOver();
    GameOver(RenderWindow* App, int score);
    void cargarAssets();
    void run();

private:
    RenderWindow* App;
    Texture FondoT,FondoG, gameOverT;
    Sprite FondoS, FondosS , gameOver;
    Font font;
    Text scoreText;
    int score;
};

#endif