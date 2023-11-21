#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


using namespace sf;

class Enemigos {

private:

	Texture* enemText;
	Texture* enemPuertaText;
	Sprite* enemSprite;
	Sprite* enemPuertaSprite;
	



public:

	Enemigos();

	

	void Dibujar(RenderWindow* ventana);




};
