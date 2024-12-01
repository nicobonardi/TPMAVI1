#pragma once
#include "lib.h"
#include "Menu.h"
#include "Enemy.h"
#include "Innocent.h"
#include "Player.h"
#include "GameOver.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game(RenderWindow* App);
	void cargarAssets();
	void run();
private:	
	RenderWindow* App;
	Texture FondoJT;
	Sprite FondoJS;
	Font font;
	Text lifeT, scoreT;
	Player Player;
	Enemy* archer = nullptr;
	Innocent* knight = nullptr;
	float archerAppearDelay = 2.0f;
	float knightAppearDelay = 0.7f;
};

#endif