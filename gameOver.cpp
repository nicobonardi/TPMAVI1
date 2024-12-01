#include "GameOver.h"

GameOver::GameOver(RenderWindow* App, int score) : App(App), score(score) {}
GameOver::GameOver() : App(nullptr), score(0) {}
void GameOver::cargarAssets() {
    FondoT.loadFromFile("./Assets/fondoGO.jpg");
    FondoS.setTexture(FondoT);
    float scaleX = 640.0f / FondoT.getSize().x;
    float scaleY = 480.0f / FondoT.getSize().y;
    FondoS.setScale(scaleX, scaleY);

    font.loadFromFile("./Assets/Perfect DOS VGA 437.ttf");

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::Green);
    scoreText.setString("Puntaje final: " + to_string(score));
    scoreText.setPosition(180, 200);
}

void GameOver::run() {
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                App->close();
            }
        }
        App->clear();
        App->draw(FondoS);
        App->draw(gameOver);
        App->draw(scoreText);
        App->display();
    }
}