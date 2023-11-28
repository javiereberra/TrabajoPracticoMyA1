#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Juego.h"
#include <iostream> 

using namespace sf;
using namespace std;

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
	//	
	vidas = 3;
	ptos = 0;

	puntaje = new Text;
	puntaje->setFont(*font);
	puntaje->setCharacterSize(24);
	puntaje->setString("Puntaje: "+to_string(ptos));
	puntaje->setPosition(650, 10);
	vidasText = new Text;
	vidasText->setFont(*font);
	vidasText->setCharacterSize(24);
	vidasText->setString("Vidas: " + to_string(vidas));
	vidasText->setPosition(10, 10);
	textGameOver = new Text;
	textGameOver->setFont(*font);
	textGameOver->setCharacterSize(36);
	textGameOver->setString("¡Game Over!");
	textGameOver->setPosition(400, 300);

	font->loadFromFile("assets/arial.ttf");
	menu->setFont(*font);
	menu->setString("Presiona 'S' para comenzar");
	menu->setCharacterSize(24);
	menu->setPosition(250, 300);

	jugador = new Jugador();
	enemigos = new Enemigos();
	inocente = new Inocente();
	
	
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
	
	bool gameOver = false;
	
	while (ventana1->isOpen() && !gameOver) {

		procesar_eventos();
		actualizar();
		dibujar();
		
		if (vidas <= 0) {
			gameOver = true;
			
		}
	}

	while (gameOver && ventana1->isOpen()) {
			ventana1->clear();
						
			
			
			ventana1->draw(*textGameOver);

			ventana1->display();

			// Procesar eventos para cerrar la ventana si se presiona la "X" de cerrar
			Event eventoGameOver;
			while (ventana1->pollEvent(eventoGameOver)) {
				if (eventoGameOver.type == Event::Closed) {
					ventana1->close();
				}
			}
		}
	}


void Juego::procesar_eventos() {
	Event evento1;
	while (ventana1->pollEvent(evento1)) {
		switch (evento1.type) {
		case Event::Closed:
			ventana1->close();
			break;
		case Event::MouseButtonPressed:
			if (evento1.mouseButton.button == Mouse::Button::Left)
				disparar();
			break;
		}
	}
}

void Juego::actualizar() {

	Vector2i mousePos = Mouse::getPosition(*ventana1);
	jugador->Movimiento(mousePos.x, mousePos.y);
	
	Vector2f posicionInocente = inocente->ObtenerPosicion();

	enemigos->Actualizar(ventana1);
	inocente->Actualizar(ventana1);

	if (enemigos->EstaActivo()) {
		if (enemigos->Colision(posicionInocente.x, posicionInocente.y)) {
			inocente->Eliminado();
		}
	}

}



void Juego::disparar() {

	Vector2f playerPos = jugador->ObtenerPosicion();
	
	
	if (enemigos->EstaActivo()) {
		if (enemigos->Colision(playerPos.x, playerPos.y)) {
			enemigos->Eliminado();
			ptos += 10;
			puntaje->setString("Puntaje: " + to_string(ptos));
		}
	}

	if (inocente->EstaActivo()) {
		if (inocente->Colision(playerPos.x, playerPos.y)) {
			inocente->Eliminado();
			vidas -= 1;
			vidasText->setString("Vidas: " + to_string(vidas));
		}
	}
	
}


void Juego::dibujar() {

	ventana1->clear();

	ventana1->draw(*fondo);
	ventana1->draw(*puntaje);
	ventana1->draw(*vidasText);
	ventana1->draw(*ventana_arriba_cerrada);
	ventana1->draw(*ventana_arriba_cerrada2);
	ventana1->draw(*ventana_abajo_cerrada);
	ventana1->draw(*ventana_abajo_cerrada2);
	ventana1->draw(*puerta_cerrada);
	

	if (enemigos->EstaActivo()) 
		enemigos->Dibujar(ventana1);

	if (inocente->EstaActivo())
		inocente->Dibujar(ventana1);
	

	jugador->Dibujar(ventana1);
	
	ventana1->display();


}

Juego::~Juego() {

	delete inocente;
	delete enemigos;
	delete jugador;
	delete ventana1;


}