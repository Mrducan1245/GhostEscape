#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

class Game {
  glm::vec2 screen_size_ = glm::vec2(0);
  SDL_Window *window_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;
  bool is_running_ = true;

  Game() {}

  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

public:
  static Game &GetInstance() {
    static Game instance;
    return instance;
  }

  void run();
  void init(std::string title, int width, int height);
  void handleEvents();
  void update(float deltaTime);
  void render();
  void clean();
};
