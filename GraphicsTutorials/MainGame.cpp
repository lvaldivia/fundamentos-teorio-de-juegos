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
	_sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);
	update();
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
		fatalError("Error loading window");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL_GLContext not loading");
	}

	GLenum error = glewInit();

	if (error != GLEW_OK) {
		fatalError("glew not loading");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	
}

void MainGame::processInput() {
	SDL_Event evt;
	while(SDL_PollEvent(&evt)){
		switch(evt.type){
			case SDL_QUIT:
				_gameState = GameState::EXIT;
			break;
			case SDL_MOUSEMOTION:
				cout << "x " << evt.motion.x << " y " <<evt.motion.y << endl;
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
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, 0.0f);
	_sprite.draw();
	glEnd();
	SDL_GL_SwapWindow(_window);
}

MainGame::~MainGame()
{
}
