#pragma once
#include <string>
#include <SDL2\SDL.h>
#include <GL\glew.h>
#include <iostream>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	~Display();
	void Update();
	bool IsClosed();
	void Clear(float r, float g, float b, float a);
	void Clear(float r, float g, float b);
protected:
private:
	Display(const Display& other);
	Display& operator=(const Display& other);

	SDL_Window* myWindow;
	SDL_GLContext myGLContext;
	bool isClosed;
};

