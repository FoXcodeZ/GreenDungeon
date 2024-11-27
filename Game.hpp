#pragma once
#include <SDL3/SDL.h>

class Game
{
public:
    void Initialize();
    void Run();
    void Shutdown();
private:
    void ProcessInput();
    void Update();
    void Render();
private:
    SDL_Window* m_window {};
    SDL_Renderer* m_renderer {};
    bool m_isRunning = true;
};