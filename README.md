# Capstone Snake Game

The original project had a fully functional Snake game implemented. A Snake game has a keyboard controlled snake that's constantly moving.
When it eats a food (by running over it), it grows in length by one block while still moving. The original implementation infinitely runs until the snake runs into itself.

Original implementation:
- A `main` function handling creating objects of the three main steps of the game loop (`Controller`, `Game`, `Renderer`). The `Game::Game` constructor creates a `Snake` object, while `Game::Run` starts the game loop.
- A `Game::Update` method that takes care of snake movement, handling the snake eating food, basic movement in response to user input.
- Score updated regularly.
- The `Snake` stores float coordinates of the head, and a vector of points (int cell coordinates) as the body. The head has float
coordinates to suggest speed as a gradient, versus blockily moving from point to point. Location updates based on the snake's speed
are all handled. The `Snake::Update` method both handles updating the head and the body.
- Most of the SDL usage is already written.

The project spec asked to create features to the original game which used concepts discussed through the course. 

Added features:
- Create a GUI with speed (frames per second) toggling, leaderboard option, original mode, obstacle mode, computer snake mode. Used [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear/) to do so.
- Leaderboard is read and written from a `*.txt` file. The text file is encrypted using a symmetric key. I kept the key up on GitHub,
so it's not like it's actually a security improvement. I just felt very uncomfortable leaving a plaintext file with data public. I could've
left an optional parameter to toggle encryption, but decided to make it a mandatory design feature.
- New `Obstacle` class with inheritance (fixed, moving).
- New snake controlled by A* algorithm, which will lead to a loss if run into it or
automatic win/rankings multiplier boost if eat the snake by hitting the last box of it.
- Gave the A* algorithm snake a handicap where it can't use the wraparound to go across the screen.
- End print message with score, size, and leaderboard ranking (two leaderboards - respective mode and the general leaderboard).

## How to Run

1. Download `build/SnakeGame` and run using `./SnakeGame` from Unix command line in same directory.

Or:

1. Create own executable by cloning repo.
2. If no build directory, create one `mkdir build`.
3. Compile `cd build && cmake .. && make`.
4. Run `./SnakeGame`

## Notes

- Figured out how to make flashing colored items! Have two `SDL_SetRenderDrawColor`s next to each other and it will effectively be a strobe light!

- `Renderer` and `Controller` don't own any of the class representations e.g. Snake, Obstacle. They just take in references or 
copies and either draw out a renderering from a `const` object or mutate values within the object. The food is 
implemented as an `SDL_Point` and not a class, which is perfect, but for some reason it's being passed in as a reference to 
the `Renderer` instead of another deep copy. I am not sure why the original project creators decided to introduce
that inconsistency. I may change it later.
- `Renderer` contains no game logic and takes in only `const` values to render a snapshot of all logic representations.
- Speed mode is 100% solved without deeply touching classes (handled completely in `main.cpp`).

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)


## Credits

Udacity team credited [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow thread.

## Links

https://dexp.in/articles/nuklear-intro/
https://cpp.hotexamples.com/examples/-/-/nk_option_label/cpp-nk_option_label-function-examples.html
https://www.geeksforgeeks.org/encrypt-and-decrypt-text-file-using-cpp/

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
