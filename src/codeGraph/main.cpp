
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <cstdint>
#include <cstdio>
#include <cassert>

const uint32_t SCREEN_WIDTH = 700;
const uint32_t SCREEN_HEIGHT = 600;

#define ASSERT(cond, ...) if(!(cond)) { fprintf(stderr, __VA_ARGS__); exit(1); }

struct Color{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

class Shape{
    protected:
        uint32_t width, height, x, y;
        Color *color;

    public:
        Shape(){ x = 0; y = 0; color = nullptr; };
        void set_values(uint32_t, uint32_t);
        uint32_t getWidth() const { return width; }
        uint32_t getHeight() const { return height; }
        uint32_t getX() const { return x; }
        uint32_t getY() const { return y; }
        Color* getColor() { return color; }
};

class Rectangle : public Shape{
    public:
        Rectangle() : Shape(){};
        void set_values(const uint32_t, const uint32_t, const uint32_t, const uint32_t, Color&);
};

void Rectangle::set_values(const uint32_t w, const uint32_t h, const uint32_t x, const uint32_t y, Color &c){
    this->width = w;
    this->height = h;
    this->x = x;
    this->y = y;
    this->color = &c;
}

int main( int argc, char* args[] ){

    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;
    SDL_Renderer* windowRenderer = nullptr;

    ASSERT(!SDL_Init(SDL_INIT_VIDEO), "ERROR, could not initialize video: %s\n", SDL_GetError());

    window = SDL_CreateWindow("Testing_Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
    ASSERT(!(window == nullptr), "ERROR, could not create window: %s\n", SDL_GetError());

    //screenSurface = SDL_GetWindowSurface(window);
    //ASSERT(!(screenSurface == nullptr), "ERROR, could attach window surface: %s\n", SDL_GetError());

    //SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 200, 200, 200));
    //SDL_UpdateWindowSurface(window);

    windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    ASSERT(!(windowRenderer == nullptr), "ERROR, Renderer could not be created!: %s\n", SDL_GetError());

    Color c = {255, 0, 0, 255};
    Rectangle rect;
    rect.set_values(200, 200, 100, 100, c);

    SDL_Rect rectangle = { (int)rect.getX(), (int)rect.getY(), (int)rect.getWidth(), (int)rect.getHeight() };
    Color *color = rect.getColor();

    SDL_SetRenderDrawColor( windowRenderer,0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(windowRenderer);
    SDL_SetRenderDrawColor( windowRenderer, color->red, color->green, color->blue, color->alpha);
    SDL_RenderFillRect(windowRenderer, &rectangle);

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
