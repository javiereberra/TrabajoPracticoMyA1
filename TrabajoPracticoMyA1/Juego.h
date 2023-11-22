#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemigos.h"
#include "Jugador.h"



using namespace sf;

class Juego {

private:
	//variables para la ventana, fuente y sprites
	RenderWindow* ventana1;
	Font* font;
	Text* menu;
	Texture* textura1;
	Texture* textura2;
	Texture* textura3;
	Texture* textura4;
	
	Sprite* fondo;
	Sprite* ventana_arriba_cerrada;
	Sprite* ventana_arriba_cerrada2;
	Sprite* ventana_abajo_cerrada;
	Sprite* ventana_abajo_cerrada2;
	Sprite* puerta_cerrada;

	Jugador* jugador;
	Enemigos* enemigos;


	//un booleano para determinar cuándo se está jugando y cuándo está en el menu
	bool start;
	

public:
	//constructor de juego
	Juego(int ancho, int alto, std::string titulo);

	//función para iniciar el menu y dar lugar al start
	void ejecutar();
	//bucle, dibujo, actualizar y procesar eventos
	void gameLoop();
	void dibujar();
	void actualizar();
	void procesar_eventos();

	//destructor de juego
	~Juego();

};
