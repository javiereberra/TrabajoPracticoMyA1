#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


using namespace sf;

class Enemigos {

private:

	Texture* enemText;
	Texture* enemFondoText;
	Texture* enemTextArriba;
	Texture* enemFondoTextArriba;
	Sprite* enemSprite;
	Sprite* enemFondoSprite;
	
	bool _estaVisible;
	Clock _clock;

	float tiempoVisible;
	float tiempoApagado;

	//probar posiciones
	Vector2f positions[5];
	int pos;

public:

	Enemigos();

	bool EstaActivo();

	void Dibujar(RenderWindow* ventana);

	void Actualizar(RenderWindow* ventana);



};
