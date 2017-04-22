#pragma once

class Sprite{

public:
	Sprite();
	void init(float x, float y, int width, int height);
	void draw();
	~Sprite();

private:
	float _x;
	float _y;
	int _width;
	int _height;
	unsigned int _vboID;
}
