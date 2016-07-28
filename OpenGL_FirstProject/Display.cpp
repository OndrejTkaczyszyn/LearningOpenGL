#include "Display.h"
#include <iostream>
#define DEBUG
#undef ANNOYME

Display::Display(int width, int height, const std::string& title)//constructor
{
	#ifdef DEBUG
	std::cout << "Display initialized with width " << width << ", height " << height << ", and title \"" << title << "\"" << std::endl;
    #endif
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 32);

	myWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_OPENGL);
	myGLContext = SDL_GL_CreateContext(myWindow);
	
	GLenum status = glewInit();
	isClosed = false;

	if (status != GLEW_OK) {
#ifdef DEBUG
		std::cerr << "Glew failed to initialize, " << status << std::endl;
#endif

	}

}

void Display::Update() {
	SDL_GL_SwapWindow(myWindow);

	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			isClosed = true;
		}
	}
}

bool Display::IsClosed() {
	return isClosed;
}

void Display::Clear(float r, float g, float b, float a) {
#if defined(DEBUG) && defined(ANNOYME)
	std::cout << "Display cleared with color(" << r <<","<< g << "," << b << "," << a << ")" << std::endl;
#endif
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}
void Display::Clear(float r, float g, float b) {
#ifdef defined(DEBUG) && defined(ANNOYME)
	std::cout << "Display cleared with color(" << r << "," << g << "," << b << ")" << std::endl;
#endif
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
Display::~Display()//destructor
{
	SDL_GL_DeleteContext(myGLContext);
	SDL_DestroyWindow(myWindow);
	SDL_Quit();
#ifdef DEBUG
	std::cout << "Display Destroyed" << std::endl;
#endif
}

Display::Display(const Display& other)//destructor
{
}

Display& Display::operator = (const Display& rhs) {
	if (this == &rhs) {
		std::cout << "Warning: Assigning object to itself";
		return *this;
	}
	//assignment operator
	return *this;
}
