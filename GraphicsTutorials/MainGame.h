#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "Error.h"
#include "Sprite.h"

enum class GameState {
	PLAY,
	EXIT
};


class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	SDL_Window* _window;
	Sprite _sprite;
	int _screenWidth;
	int _screenHeight;
	void initShaders();
	void initSystems();
	void processInput();

	void update();
	void draw();

	GameState _gameState;
};

