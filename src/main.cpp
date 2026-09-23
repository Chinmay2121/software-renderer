#include <SDL3/SDL.h>

#include <iostream>

#include "Framebuffer.h"



const int WIDTH = 800;
const int HEIGHT = 600;

int main(){   

//  Initialize SDL 


    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "Error Initializing\n" << SDL_GetError() << '\n';
        return 1;
    }


//  Create SDL Window

    SDL_Window* window = SDL_CreateWindow(
        "Software Renderer", 
        WIDTH, 
        HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "Window creation failed: "
                  << SDL_GetError() << '\n';

        SDL_Quit();
        return 1;
    }

//  Create SDL Renderer

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    
    if(!renderer){
        std::cerr << "Renderer failed\n" << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
//  Create SDL Texture

    SDL_Texture* texture = SDL_CreateTexture(
        renderer, 
        SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH, 
        HEIGHT
    );


    if(!texture){
        std::cerr << "Texture Creation Failed\n" << SDL_GetError() << '\n';
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


//  Create FrameBuffer

    FrameBuffer framebuffer(WIDTH, HEIGHT);

    framebuffer.putPixel(
        WIDTH/2,
        HEIGHT/2,
        {255, 0, 0, 255}
    );



//  Event Loop 

    bool running = true;
    SDL_Event event;


    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT)
                running = false;
        }
    }

// Cleanup 

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


}