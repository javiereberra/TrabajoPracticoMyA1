#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigos.h"
#include "Juego.h"

using namespace sf;
using namespace std;

Enemigos::Enemigos() {


	enemTextArriba = new Texture;
	enemTextArriba->loadFromFile("assets/ventana_arriba_enemigo.png");

	enemTextAbajo = new Texture;
	enemTextAbajo->loadFromFile("assets/ventana_abajo_enemigo.png");

	enemTextPuerta = new Texture;
	enemTextPuerta->loadFromFile("assets/puerta_enemigo.png");
	
	
	enemSpriteArriba = new Sprite;
	enemSpriteArriba->setTexture(*enemTextArriba);

	enemSpriteAbajo = new Sprite;
	enemSpriteAbajo->setTexture(*enemTextAbajo);

	enemSpritePuerta = new Sprite;
	enemSpritePuerta->setTexture(*enemTextPuerta);

	
	

	_estaVisible = false;
	
	tiempoVisible = 1.5f;
	tiempoApagado = 0.5f;

	positions[0] = Vector2f(75.f, 84.f);
	positions[1] = Vector2f(525.f, 84.f);
	positions[2] = Vector2f(50.f, 334.f);
	positions[3] = Vector2f(337.f, 328.f);
	positions[4] = Vector2f(550.f, 334.f);
}

void Enemigos::Dibujar(RenderWindow* ventana) {
	//ventana->draw(*enemSprite);
	switch (pos) {
	case 0:
		ventana->draw(*enemSpriteArriba);
		break;
	case 1:
		ventana->draw(*enemSpriteArriba);
		break;
	case 2:
		ventana->draw(*enemSpriteAbajo);
		break;
	case 3:
		ventana->draw(*enemSpritePuerta);
		break;
	case 4:
		ventana->draw(*enemSpriteAbajo);
		break;
	default:
		break;
	}

}

void Enemigos::Actualizar(RenderWindow* ventana) {


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
				enemSpriteArriba->setPosition(positions[0]);
				break;
			case 1:
				enemSpriteArriba->setPosition(positions[1]);
				break;
			case 2:
				enemSpriteAbajo->setPosition(positions[2]);
				break;
			case 3:
				enemSpritePuerta->setPosition(positions[3]);
				break;
			case 4:
				enemSpriteAbajo->setPosition(positions[4]);
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

bool Enemigos::EstaActivo() {

	return _estaVisible;
}