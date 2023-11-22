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
	
	bool _estaVisible;
	Clock _clock;

	float tiempoVisible;
	float tiempoApagado;


public:

	Enemigos();

	bool EstaActivo();

	void Dibujar(RenderWindow* ventana);

	void Actualizar(RenderWindow* ventana);



};
