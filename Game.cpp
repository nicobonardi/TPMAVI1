#include "Game.h"
#include "lib.h"

Game::Game(RenderWindow* App) : App(App) {}

void Game::cargarAssets() {
	FondoJT.loadFromFile("./Assets/fondojuego.jpg");
	FondoJS.setTexture(FondoJT);
	float scaleX = 640.0f / FondoJT.getSize().x;
	float scaleY = 480.0f / FondoJT.getSize().y;
	FondoJS.setScale(scaleX, scaleY);

	font.loadFromFile("./Assets/Perfect DOS VGA 437.ttf");

	scoreT.setFont(font);
	scoreT.setCharacterSize(24);
	scoreT.setFillColor(Color::Red);
	scoreT.setPosition(500, 10);
	scoreT.setString("Bajas: 0");

	lifeT.setFont(font);
	lifeT.setCharacterSize(24);
	lifeT.setFillColor(Color::Red);
	lifeT.setPosition(10, 10);
	lifeT.setString("Vidas: " + to_string(Player.getLives()));

	Player.cargarAssets();
	archer = new Enemy("Assets/enemy.png");
	knight = new Innocent("Assets/innocent.png");
};

void Game::run() {
	Clock archerClock;
	Clock knightClock;
	int score = 0;
	int knightsDisparados = 0;
	while (App->isOpen()) {
		Event event;
		while (App->pollEvent(event)) {
			if (event.type == Event::Closed) {
				App->close();
			}
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));


				if (archer->isClicked(mousePosition)) {
					archer->respawn();
					score++;
					scoreT.setString("Bajas: " + to_string(score));
					archerClock.restart();
				}
				if (knight->isClicked(mousePosition)) {
					knight->respawn();
					Player.reduceLife();
					lifeT.setString("Vidas: " + to_string(Player.getLives()));
					knightsDisparados++;
					archerClock.restart();
				}
				if (Player.getLives() == 0) {
					int scoreFinal = score - (knightsDisparados * 2);
					GameOver gameOver(App, scoreFinal);
					gameOver.cargarAssets();
					gameOver.run();
					return;
				}
			}

		}

		App->setMouseCursorVisible(false);
		App->clear();
		App->draw(FondoJS);
		archer->draw(*App);
		knight->draw(*App);

		if (archerClock.getElapsedTime().asSeconds() > archerAppearDelay) {
			archer->respawn();
			Player.reduceLife();
			lifeT.setString("Vidas: " + to_string(Player.getLives()));
			archerClock.restart();
		}
		if (knightClock.getElapsedTime().asSeconds() > knightAppearDelay) {
			knight->respawn();
			knightClock.restart();
		}
		Player.Dibujar(*App);
		Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));
		Player.Actualizar(mousePosition);
		App->draw(lifeT);
		App->draw(scoreT);
		App->display();
	}
};