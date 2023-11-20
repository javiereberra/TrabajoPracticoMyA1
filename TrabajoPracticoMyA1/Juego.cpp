#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Juego.h"

using namespace sf;

Juego::Juego(int ancho, int alto, std::string titulo) {

	ventana1 = new RenderWindow(VideoMode(ancho, alto), titulo);
	//ventana1->setMouseCursorVisible(false);

	textura1 = new Texture;
	fondo = new Sprite;
	textura1->loadFromFile("assets/fondo_base.jpg");
	fondo->setTexture(*textura1);

	font = new Font;
	menu = new Text;

	font->loadFromFile("assets/arial.ttf"); // Reemplaza "arial.ttf" con la ruta de tu fuente
	menu->setFont(*font);
	menu->setString("Presiona 'S' para comenzar");
	menu->setCharacterSize(24);
	menu->setPosition(250, 300);


	start = false;

}

void Juego::ejecutar() {

	while (ventana1->isOpen()) {
		Event evento;
		while (ventana1->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed)
				ventana1->close();

			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::Key::S && !start) {
					
					start = true;
				}
			}
		}

		ventana1->clear(sf::Color::Black);

		if (start) {
			
			gameLoop();

		} else {
			
			
			ventana1->draw(*menu);
		}

		ventana1->display();
	}
}





void Juego::gameLoop() {

	while (ventana1->isOpen()) {


		procesar_eventos();
		actualizar();
		dibujar();

	}

}

void Juego::procesar_eventos() {
	Event evento1;
	while (ventana1->pollEvent(evento1)) {
		switch (evento1.type) {
		case Event::Closed:
			ventana1->close();
			break;
		}
	}
}

void Juego::actualizar() {

	Vector2i mousePos = Mouse::getPosition(*ventana1);
	
	


}

void Juego::dibujar() {

	ventana1->clear();

	ventana1->draw(*fondo);
	
	
	ventana1->display();


}

Juego::~Juego() {



	delete ventana1;


}