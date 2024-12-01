#pragma once
#include "lib.h"
#ifndef INNOCENT_H
#define INNOCENT_H

class Innocent {
public:
    Innocent(const std::string& textureFile);
    void draw(RenderWindow& App);
    void respawn();
    bool isClicked(const Vector2f& point);
private:
    Sprite InnocentSprite;
    Texture InnocentTexture;
    vector<float> CoordX = { 207,420,110,285,466 };
    vector<float> CoordY = { 160,160,335,343,335 };
};

#endif
