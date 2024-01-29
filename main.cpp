#include <iostream>

#include <SDL2/SDL.h>

using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Grid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    SDL_Renderer*pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if ( NULL == window )
    {
        // In the case that the window could not be made...
        cout << "Could not create window: " << SDL_GetError( ) << endl;
        return 1;
    }

    SDL_Event windowEvent;

    while ( true )
    {
        SDL_SetRenderDrawColor(pRenderer, 204, 0, 0, 255);
        SDL_RenderDrawLine(pRenderer, 300, 250, 350, 250); //350 and 250 - the middle coordinates
        SDL_RenderPresent(pRenderer);
    }

    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}
