#include "Game.hpp"
#include <iostream>

void Game::Initialize()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    const int width = displayMode.w;
    const int height = displayMode.h;
    std::cout << "Width: " << width << " Height: " << height << std::endl;

    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_BORDERLESS, &m_window, &m_renderer);
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

void Game::Shutdown() const
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
            case SDL_QUIT:
                m_isRunning = false;
            break;

            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
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

void Game::Render() const
{
    SDL_SetRenderDrawColor(m_renderer, 10, 151, 176, 255);
    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 255, 20, 20, 255);
    SDL_Rect player = {100, 100, 200, 200};
    SDL_RenderFillRect(m_renderer, &player);

    SDL_RenderPresent(m_renderer);
}
