
#include "game.h"

// Initialize the game with a title, width, and height
void Game::init(std::string title, int width, int height) {
  screen_size_ = glm::vec2(width, height);
  if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init failed: %s",
                 SDL_GetError());
  }

  if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) != (MIX_INIT_MP3 | MIX_INIT_OGG)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Mix_Init failed: %s",
                 SDL_GetError());
  }

  if (!Mix_OpenAudio(0, NULL)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Mix_OpenAudio failed: %s",
                 SDL_GetError());
  }
  Mix_AllocateChannels(16);
  Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
  Mix_Volume(-1, MIX_MAX_VOLUME / 4);

  if (!TTF_Init()) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "TTF_Init failed: %s",
                 SDL_GetError());
  }

  SDL_CreateWindowAndRenderer(title.c_str(), width, height,
                              SDL_WINDOW_RESIZABLE, &window_, &renderer_);

  if (!window_ || !renderer_) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "SDL_CreateWindowAndRenderer "
                 "failed: %s",
                 SDL_GetError());
  }

  // 设置窗口逻辑分辨率
  SDL_SetRenderLogicalPresentation(renderer_, width, height,
                                   SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

// Handle input events
void Game::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_EVENT_QUIT:
      is_running_ = false;
      break;
    default:
      break;
    }
  }
}

// Update the game state with the given delta time
void Game::update(float deltaTime) {
  std::cout << "Updating game state with deltaTime: " << deltaTime << std::endl;
}

// Render the game
void Game::render() { std::cout << "Rendering game..." << std::endl; }

// Clean up resources
void Game::clean() {
  std::cout << "Cleaning up game resources..." << std::endl;
}

// Run the game loop
void Game::run() {
  std::cout << "Running the game loop..." << std::endl;
  // Example game loop (simplified)
  while (is_running_) {
    handleEvents();
    update(0.016f); // Assume a fixed delta time for simplicity
    render();
  }
  clean();
}
