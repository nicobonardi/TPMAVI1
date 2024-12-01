#include "menu.h"
#include "lib.h"
Menu::Menu(RenderWindow* App) : App(App) {}
void Menu::cargarAssets() {

    FondoMT.loadFromFile("./Assets/fondoI.jpg");
    FondoS.setTexture(FondoMT);
}

void Menu::run() {
    App->setMouseCursorVisible(false);
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    return;
                }
                if (event.key.code == Keyboard::Escape) {
                    App->close();
                }
            }
        }
        App->clear();
        App->draw(FondoS);
        App->display();
    }
}