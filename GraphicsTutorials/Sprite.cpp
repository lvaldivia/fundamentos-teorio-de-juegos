#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>


Sprite::Sprite(){
	_vboID = 0;	
}

void Sprite::init(float x, float y, int width, int height){
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if(_vboID == 0){
		glGenBuffers(1, &_vboID);
	}

	Vertex vertexData[6];

	vertexData[0].position.x = _x + _width;
	vertexData[0].position.y = _y + _height;

	vertexData[1].position.x = _x;
	vertexData[1].position.y = _y + _height;

	vertexData[2].position.x = _x;
	vertexData[2].position.y = _y;

	vertexData[3].position.x = _x;
	vertexData[3].position.y = _y;

	vertexData[4].position.x = _x + _width;
	vertexData[4].position.y = _y;

	vertexData[5].position.x = _x + _width;
	vertexData[5].position.y = _y + _height;

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertexData), vertexData,
		GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}

void Sprite::draw(){
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (void *)offsetof(Vertex, position));

	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE,
		sizeof(Vertex), (void *)offsetof(Vertex, position));
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Sprite::~Sprite(){
	if(_vboID != 0){
		glDeleteBuffers(1, &_vboID);
	}
}

