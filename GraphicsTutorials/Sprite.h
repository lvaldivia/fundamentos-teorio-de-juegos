#pragma once
#include <GL/glew.h>
class Sprite
{
private:
	int _width;
	int _height;
	float _x;
	float _y;
	unsigned int _vboID;
	
public:
	void init(float x, float y, int width, int height);
	void draw();
	Sprite();
	~Sprite();
};

