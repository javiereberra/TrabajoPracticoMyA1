#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


using namespace sf;

class Enemigos {

private:

	Texture* enemTextArriba;
	Sprite* enemSpriteArriba;
	
	Texture* enemTextAbajo;
	Sprite* enemSpriteAbajo;

	Texture* enemTextPuerta;
	Sprite* enemSpritePuerta;

	
	
	Clock _clock;

	float tiempoVisible;
	float tiempoApagado;

	

	bool _estaVisible;

	//probar posiciones
	Vector2f positions[5];
	int pos;

public:

	Enemigos();

	
	
	bool Colision(float x, float y);

	bool EstaActivo();

	void Eliminado();

	void Dibujar(RenderWindow* ventana);

	void Actualizar(RenderWindow* ventana);



};
