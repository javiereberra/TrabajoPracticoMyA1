#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigos.h"
#include "Juego.h"

using namespace sf;

Enemigos::Enemigos() {


	enemText = new Texture;
	enemPuertaText = new Texture;
	enemText->loadFromFile("assets/enemy_idle.png");
	enemPuertaText->loadFromFile("assets/puerta_abierta.png");
	enemSprite = new Sprite;
	enemPuertaSprite = new Sprite;
	enemSprite->setTexture(*enemText);
	enemPuertaSprite->setTexture(*enemPuertaText);

	_estaVisible = false;
	
	tiempoVisible = 1.5f;
	tiempoApagado = 0.5f;

}

void Enemigos::Dibujar(RenderWindow* ventana) {
	ventana->draw(*enemSprite);

}

void Enemigos::Actualizar(RenderWindow* ventana) {


	if (!_estaVisible) {
		if (_clock.getElapsedTime().asSeconds() > tiempoApagado) {
			_clock.restart();
			if (rand() % 100 < 25)
				_estaVisible = true;
			//// set position ///
		}
	}
	else {
		if (_clock.getElapsedTime().asSeconds() > tiempoVisible) {
			_estaVisible = false;
			_clock.restart();
		}
	}


}

bool Enemigos::EstaActivo() {

	return _estaVisible;
}