#pragma once
#include "lib.h"
#ifndef Player_H
#define Player_H

class Player {
public:
    Player();
    void cargarAssets();
    void Actualizar(Vector2f mousePosition);
    void Dibujar(RenderWindow& App);
    void reduceLife();
    int getLives() const;
private:
    Sprite PlayerSprite;
    Texture PlayerTexture;
    int vidas;
};
#endif

