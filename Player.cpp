#include "lib.h"
#include "Player.h"

Player::Player() : vidas(3) {}

void Player::cargarAssets()
{
    PlayerTexture.loadFromFile("./Assets/crosshair.png");
    PlayerSprite.setTexture(PlayerTexture);
    PlayerSprite.setScale(0.1f, 0.1f);
}

void Player::Actualizar(Vector2f mousePosition)
{
    FloatRect bounds = PlayerSprite.getLocalBounds();
    PlayerSprite.setPosition(
        mousePosition.x - bounds.width * PlayerSprite.getScale().x / 2.0f,
        mousePosition.y - bounds.height * PlayerSprite.getScale().y / 2.0f
    );
}

void Player::Dibujar(RenderWindow& App)
{
    App.draw(PlayerSprite);
}

void Player::reduceLife()
{
    if (vidas > 0) {
        vidas--;
    }
}

int Player::getLives() const
{
    return vidas;
}