
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <cstdint>
#include <cstdio>
#include <cassert>

const uint32_t SCREEN_WIDTH = 700;
const uint32_t SCREEN_HEIGHT = 600;

#define ASSERT(cond, ...) if(!(cond)) { fprintf(stderr, __VA_ARGS__); exit(1); }

class Shape{
    private:
        uint32_t width, height;

    public:
        Shape();
        void set_values(uint32_t, uint32_t);
};

class Rectangle : public Shape{
    char id[5];
    public:
        Rectangle() : Shape(){};
        void set_values(uint32_t, uint32_t, char []);
};

Shape::Shape(){
    width = 0;
    height = 0;
}

void Shape::set_values(uint32_t x, uint32_t y){
    width = x;
    height = y;
}

void Rectangle::set_values(uint32_t x, uint32_t y, char str[]){
    Shape::set_values(x, y);

    for(unsigned i=0; i<sizeof(id); i++){
        id[i] = str[i];
    }
}

int main( int argc, char* args[] ){

    Rectangle rect;
    char str[5] = "Hiii";
    rect.set_values(3, 4, str);

    SDL_Window* window = nullptr;

    SDL_Surface* screenSurface = nullptr;

    ASSERT(!SDL_Init(SDL_INIT_VIDEO), "ERROR, could not initialize video: %s\n", SDL_GetError());

    window = SDL_CreateWindow("Testing_Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT , 0);

    ASSERT(!(window == nullptr), "ERROR, could not create window: %s\n", SDL_GetError());

    screenSurface = SDL_GetWindowSurface(window);

    ASSERT(!(screenSurface == nullptr), "ERROR, could attach window surface: %s\n", SDL_GetError());

    SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 200, 200, 200));

    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;

    while( quit == false ){
        while( SDL_PollEvent( &e ) ){
            if( e.type == SDL_QUIT )
                quit = true;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
