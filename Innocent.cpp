#include "lib.h"
#include "Innocent.h"

Innocent::Innocent(const std::string& textureFile) {
    InnocentTexture.loadFromFile(textureFile);
    InnocentSprite.setTexture(InnocentTexture);
    InnocentSprite.setScale(0.3f, 0.3f);
    respawn();
}
void Innocent::draw(RenderWindow& App) {
    App.draw(InnocentSprite);
}
void Innocent::respawn() {
    int pos = rand() % 5 + 1;
    InnocentSprite.setPosition(CoordX[pos - 1], CoordY[pos - 1]);
}

bool Innocent::isClicked(const Vector2f& point) {
    return InnocentSprite.getGlobalBounds().contains(point);
}