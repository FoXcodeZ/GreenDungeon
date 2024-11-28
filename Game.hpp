#pragma once
#include <SDL.h>

class Game
{
public:
    void Initialize();
    void Run();
    void Shutdown() const;
private:
    void ProcessInput();

    void Update();
    void Render() const;
private:
    SDL_Window* m_window {};
    SDL_Renderer* m_renderer {};
    bool m_isRunning = true;
};