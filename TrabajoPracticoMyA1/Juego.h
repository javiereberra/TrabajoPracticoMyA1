#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>



using namespace sf;

class Juego {

private:

	RenderWindow* ventana1;
	Font* font;
	Text* menu;
	Texture* textura1;
	Sprite* fondo;

	bool start;
	

public:

	Juego(int ancho, int alto, std::string titulo);

	void ejecutar();
	void gameLoop();
	void dibujar();
	void actualizar();
	void procesar_eventos();


	~Juego();

};
