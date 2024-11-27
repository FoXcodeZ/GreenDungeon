#include "Game.hpp"
#include <iostream>

void Game::Initialize()
{
    SDL_Init(SDL_INIT_VIDEO);

    const SDL_DisplayMode* displayMode = SDL_GetCurrentDisplayMode(1);
    const int width = displayMode->w;
    const int height = displayMode->h;
    std::cout << "Width: " << width << " Height: " << height << std::endl;

    SDL_CreateWindowAndRenderer("Green Dungeon", width, height, SDL_WINDOW_BORDERLESS, &m_window, &m_renderer);
    SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);
    m_isRunning = true;
}

void Game::Run()
{
    while (m_isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Shutdown()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::ProcessInput()
{
    SDL_Event event{};
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                m_isRunning = false;
            break;

            case SDL_EVENT_KEY_DOWN:
                if (event.key.scancode == SDL_SCANCODE_ESCAPE)
                {
                    m_isRunning = false;
                }
                break;

            default:
                break;
        }
    }
}

void Game::Update()
{
}

void Game::Render()
{
    SDL_SetRenderDrawColor(m_renderer, 10, 151, 176, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}
