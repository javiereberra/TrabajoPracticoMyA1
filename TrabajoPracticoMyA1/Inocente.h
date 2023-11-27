#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigos.h"


using namespace sf;

class Inocente {

private:

	Texture* inocTextArriba;
	Sprite* inocSpriteArriba;

	Texture* inocTextAbajo;
	Sprite* inocSpriteAbajo;

	Texture* inocTextPuerta;
	Sprite* inocSpritePuerta;



	bool _estaVisible;
	Clock _clock;

	float tiempoVisible;
	float tiempoApagado;

	//probar posiciones - hay que repetir o sacarlas de enemigo?
	Vector2f positions[5];
	int pos;

public:

	Inocente();
		
	bool Colision(float x, float y);

	bool EstaActivo();

	void Dibujar(RenderWindow* ventana);

	void Actualizar(RenderWindow* ventana);

	void Eliminado();

	Vector2f ObtenerPosicion();
};