#pragma once
class Sprite
{
private:
	int _width;
	int _height;
	float _x;
	float _y;
	unsigned int _vboID;
	void init(float x, float y, int width, int height);
	void draw();
public:

	Sprite();
	~Sprite();
};

