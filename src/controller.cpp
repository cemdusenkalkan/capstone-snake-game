#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
} // Change the direction of the snake based on input, unless it's the opposite direction

void Controller::AlgorithmInput(bool &running, Snake &fake_snake) const {
  if (!fake_snake.ai) {
    std::cout << "Programmer error: Used AlgorithmInput for a user snake.";
    return; // quick sanity check for programmer error
  } 
  // use A* to come up with a new direction, then update fake.snake = Snake::Direction;
  // need to ensure fake_snake.direction is not an opposite direction (impossible to turn from)
  // ChangeDirection(fake_snake, Snake::Direction::kUp, Snake::Direction::kDown);
  // make it disallowed to go across the screen by using bounds check method here
}

// Handle user input for the snake's movement
void Controller::HandleInput(bool &running, Snake &snake) const {
  if (snake.ai) {
    std::cout << "Programmer error: Used HandleInput for an AI snake.";
    return; // quick sanity check for programmer error
  }
  SDL_Event e; //// Handle key presses for directional control
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}
