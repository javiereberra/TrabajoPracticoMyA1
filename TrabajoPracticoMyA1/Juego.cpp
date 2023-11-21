#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Juego.h"

using namespace sf;

Juego::Juego(int ancho, int alto, std::string titulo) {

	ventana1 = new RenderWindow(VideoMode(ancho, alto), titulo);
	//ventana1->setMouseCursorVisible(false);

	//iniciar todas las variables y posicionarlas en la ventana
	textura1 = new Texture;
	textura2 = new Texture;
	textura3 = new Texture;
	textura4 = new Texture;

	ventana_arriba_cerrada = new Sprite;
	ventana_arriba_cerrada2 = new Sprite;
	ventana_abajo_cerrada = new Sprite;
	ventana_abajo_cerrada2 = new Sprite;
	puerta_cerrada = new Sprite;
	fondo = new Sprite;

	textura1->loadFromFile("assets/fondo_base.jpg");
	textura2->loadFromFile("assets/ventana_arriba_cerrada.png");
	textura3->loadFromFile("assets/ventana_abajo_cerrada.png");
	textura4->loadFromFile("assets/puerta_cerrada.png");

	fondo->setTexture(*textura1);
	ventana_arriba_cerrada->setTexture(*textura2);
	ventana_arriba_cerrada2->setTexture(*textura2);
	ventana_abajo_cerrada->setTexture(*textura3);
	ventana_abajo_cerrada2->setTexture(*textura3);
	puerta_cerrada->setTexture(*textura4);

	ventana_arriba_cerrada->setPosition(75,84);
	ventana_arriba_cerrada2->setPosition(525, 84);
	ventana_abajo_cerrada->setPosition(50, 334);
	ventana_abajo_cerrada2->setPosition(550, 334);
	puerta_cerrada->setPosition(337, 328);

	font = new Font;
	menu = new Text;

	font->loadFromFile("assets/arial.ttf");
	menu->setFont(*font);
	menu->setString("Presiona 'S' para comenzar");
	menu->setCharacterSize(24);
	menu->setPosition(250, 300);

	jugador = new Jugador();
	
	//iniciar el juego siempre desde el menu
	start = false;

}

//Menu de juego donde se incluye el loop
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
	jugador->Movimiento(mousePos.x, mousePos.y);
	
	


}

void Juego::dibujar() {

	ventana1->clear();

	ventana1->draw(*fondo);
	ventana1->draw(*ventana_arriba_cerrada);
	ventana1->draw(*ventana_arriba_cerrada2);
	ventana1->draw(*ventana_abajo_cerrada);
	ventana1->draw(*ventana_abajo_cerrada2);
	ventana1->draw(*puerta_cerrada);
	
	jugador->Dibujar(ventana1);
	
	ventana1->display();


}

Juego::~Juego() {


	delete jugador;
	delete ventana1;


}