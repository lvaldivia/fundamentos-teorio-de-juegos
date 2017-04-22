#include "Sprite.h"

Sprite::Sprite(){
	_vboID = 0;	
}

void Sprite::init(float x, float y, int width, int height){
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if(_vboID == 0){

	}
}

void Sprite::draw(){

}

Sprite::~Sprite(){
	if(_vboID != 0){
		//TO-DO
		//delete buffers
	}
}

