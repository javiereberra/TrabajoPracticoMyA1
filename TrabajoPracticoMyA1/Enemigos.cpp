#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigos.h"
#include "Juego.h"

using namespace sf;

Enemigos::Enemigos() {


	enemText = new Texture;
	enemPuertaText = new Texture;
	enemText->loadFromFile("assets/et.png");
	enemPuertaText->loadFromFile("assets/puerta.png");
	enemSprite = new Sprite;
	enemPuertaSprite = new Sprite;
	enemSprite->setTexture(*enemText);
	enemPuertaSprite->setTexture(*enemPuertaText);

	
	
}

void Enemigos::Dibujar(RenderWindow* ventana) {
	ventana->draw(*enemSprite);

}