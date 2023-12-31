#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Inocente.h"
#include "Juego.h"
#include "Enemigos.h"

using namespace sf;
using namespace std;

Inocente::Inocente() {


	inocTextArriba = new Texture;
	inocTextArriba->loadFromFile("assets/civil_arriba.png");

	inocTextAbajo = new Texture;
	inocTextAbajo->loadFromFile("assets/civil_abajo.png");

	inocTextPuerta = new Texture;
	inocTextPuerta->loadFromFile("assets/civil_fullsize.png");


	inocSpriteArriba = new Sprite;
	inocSpriteArriba->setTexture(*inocTextArriba);

	inocSpriteAbajo = new Sprite;
	inocSpriteAbajo->setTexture(*inocTextAbajo);

	inocSpritePuerta = new Sprite;
	inocSpritePuerta->setTexture(*inocTextPuerta);


	pos = 0;

	_estaVisible = false;

	tiempoVisible = 1.5f;
	tiempoApagado = 1.2f;

	positions[0] = Vector2f(75.f, 84.f);
	positions[1] = Vector2f(525.f, 84.f);
	positions[2] = Vector2f(50.f, 334.f);
	positions[3] = Vector2f(337.f, 328.f);
	positions[4] = Vector2f(550.f, 334.f);
}



void Inocente::Dibujar(RenderWindow* ventana) {
	
	switch (pos) {
	case 0:
		ventana->draw(*inocSpriteArriba);
		break;
	case 1:
		ventana->draw(*inocSpriteArriba);
		break;
	case 2:
		ventana->draw(*inocSpriteAbajo);
		break;
	case 3:
		ventana->draw(*inocSpritePuerta);
		break;
	case 4:
		ventana->draw(*inocSpriteAbajo);
		break;
	default:
		break;
	}

}

void Inocente::Actualizar(RenderWindow* ventana) {


	if (!_estaVisible) {
		if (_clock.getElapsedTime().asSeconds() > tiempoApagado) {
			_clock.restart();
			if (rand() % 100 < 25)
				_estaVisible = true;
			//// set position ///
			pos = rand() % 5;
			//switch
			switch (pos) {
			case 0:
				inocSpriteArriba->setPosition(positions[0]);
				break;
			case 1:
				inocSpriteArriba->setPosition(positions[1]);
				break;
			case 2:
				inocSpriteAbajo->setPosition(positions[2]);
				break;
			case 3:
				inocSpritePuerta->setPosition(positions[3]);
				break;
			case 4:
				inocSpriteAbajo->setPosition(positions[4]);
				break;
			default:
				break;
			}
			/// termina switch



		}
	}
	else {
		if (_clock.getElapsedTime().asSeconds() > tiempoVisible) {
			_estaVisible = false;
			_clock.restart();
		}
	}


}

Vector2f Inocente::ObtenerPosicion() {
	Vector2f posicion;

	
	switch (pos) {
	case 0:
	case 1:
		posicion = inocSpriteArriba->getPosition();
		break;
	case 2:
	case 4:
		posicion = inocSpriteAbajo->getPosition();
		break;
	case 3:
		posicion = inocSpritePuerta->getPosition();
		break;
	default:
	
		posicion = Vector2f(0.f, 0.f);
		break;
	}

	return posicion;
}




bool Inocente::EstaActivo() {

	return _estaVisible;
}

bool Inocente::Colision(float x, float y) {

	if (_estaVisible) {

		FloatRect bounds1 = inocSpriteArriba->getGlobalBounds();
		FloatRect bounds2 = inocSpriteAbajo->getGlobalBounds();
		FloatRect bounds3 = inocSpritePuerta->getGlobalBounds();

		if (bounds1.contains(x, y)) {
			return true;
		}

		if (bounds2.contains(x, y)) {
			return true;
		}

		if (bounds3.contains(x, y)) {
			return true;
		}

	}
	return false;
}

void Inocente::Eliminado() {

	_estaVisible = false;

}