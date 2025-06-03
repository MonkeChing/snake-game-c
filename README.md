# 🐍 Snake Game in C

**Console-based Snake Game** developed in C, featuring:

* **User Authentication**: Secure login system with user data stored in `Users.txt`.
* **Leaderboard**: High scores maintained in `Scores.txt`, showcasing top players.
* **Modular Code Structure**: Organized codebase with separate modules for game logic, user input, menu navigation, and more.
* **File Handling**: Efficient reading and writing of user data and scores using file operations.
* **Interactive Menu**: User-friendly interface for starting the game, viewing the leaderboard, and exiting.

---

## 📁 Project Structure

* `main.c`: Entry point of the application.
* `login.c` / `login.h`: Handles user authentication.
* `leader.c` / `leader.h`: Manages the leaderboard functionalities.
* `game_menu.c` / `game_menu.h`: Controls the game menu interface.
* `snake_game.c` / `snake_game.h`: Contains the core game logic.
* `user_input.c` / `user_input.h`: Processes user inputs during the game.
* `board.c` / `board.h`: Manages the game board display.
* `constants.c` / `constants.h`: Defines constants used across the application.
* `start.c` / `start.h`: Initializes game settings and configurations.
* `Users.txt`: Stores registered user credentials.
* `Scores.txt`: Maintains the leaderboard with high scores.

---

## 🚀 Getting Started

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/MonkeChing/snake-game-c.git
   cd snake-game-c
   ```

2. **Compile the Code**:
   Ensure you have a C compiler installed (e.g., GCC). Then, compile the code:

   ```bash
   gcc main.c login.c leader.c game_menu.c snake_game.c user_input.c board.c constants.c start.c -o snake_game
   ```

3. **Run the Game**:

   ```bash
   ./snake_game
   ```

---

## 🎮 How to Play

* **Start Game**: Navigate through the menu to start a new game.
* **Controls**: Use arrow keys to control the snake's direction.
* **Objective**: Eat food to grow longer and increase your score.
* **Game Over**: The game ends if the snake collides with the wall or itself.

---

## 📝 Notes

* Ensure that `Users.txt` and `Scores.txt` are in the same directory as the executable to enable user authentication and leaderboard functionalities.
* The game is designed for Windows systems and uses standard C libraries.
