#pragma once
#include <SDL\SDL.h>

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
	int _screenWidth;
	int _screenHeight;
	void initShaders();
	void initSystems();
	void processInput();

	void update();
	void draw();

	GameState _gameState;
};

