#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigos.h"
#include "Juego.h"

using namespace sf;
using namespace std;

Enemigos::Enemigos() {


	enemText = new Texture;
	enemFondoText = new Texture;
	enemTextArriba = new Texture;
	enemFondoTextArriba = new Texture;
	enemText->loadFromFile("assets/enemy_idle.png");
	enemFondoText->loadFromFile("assets/puerta_abierta.png");
	enemTextArriba->loadFromFile("assets/enemy_arriba.png");
	enemFondoTextArriba->loadFromFile("assets/ventana_arriba_abierta.png");
	enemSprite = new Sprite;
	enemFondoSprite = new Sprite;
	enemSprite->setTexture(*enemText);
	enemFondoSprite->setTexture(*enemFondoText);

	_estaVisible = false;
	
	tiempoVisible = 1.5f;
	tiempoApagado = 0.5f;

	positions[0] = Vector2f(130.f, 86.f);
	positions[1] = Vector2f(585.f, 86.f);
	positions[2] = Vector2f(105.f, 335.f);
	positions[3] = Vector2f(355.f, 330.f);
	positions[4] = Vector2f(600.f, 335.f);
}

void Enemigos::Dibujar(RenderWindow* ventana) {
	//ventana->draw(*enemFondoSprite);
	ventana->draw(*enemSprite);

}

void Enemigos::Actualizar(RenderWindow* ventana) {


	if (!_estaVisible) {
		if (_clock.getElapsedTime().asSeconds() > tiempoApagado) {
			_clock.restart();
			if (rand() % 100 < 25)
				_estaVisible = true;
			//// set position ///
			pos = rand() % 5;
		
			enemFondoSprite->setPosition(positions[pos]);
			enemSprite->setPosition(positions[pos]);
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