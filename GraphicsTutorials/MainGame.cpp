#include "MainGame.h"
#include <iostream>

using namespace std;


MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 512;
	_screenHeight = 384;
	_gameState = GameState::PLAY;
}

void MainGame::initShaders() {
	
}

void MainGame::run() {
	initSystems();
}

void MainGame::initSystems() {
	//init sdl
	SDL_Init(SDL_INIT_EVERYTHING);

	//create window
	//title, centerX, centerY, width, height ,opengl
	_window = SDL_CreateWindow("HOLI",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_screenWidth,
		_screenHeight, 
		SDL_WINDOW_OPENGL);

	if (_window == nullptr) {
		std::cout << "Error loading window" << endl;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		std::cout << "SDL_GLContext not loading " << endl;
	}
}

void MainGame::processInput() {
	SDL_Event evt;

	while(SDL_PollEvent(&evt)){
		switch(evt.type){

			case SDL_QUIT:
				_gameState = GameState::EXIT;
			break;
			case SDL_MOUSEMOTION:
				cout << evt.motion.x << evt.motion.y << endl;
			break;
		}
	}

}

void MainGame::update() {
	while(_gameState != GameState::EXIT){
		processInput();
		draw();
	}
}

void MainGame::draw() {
	
}

MainGame::~MainGame()
{
}
