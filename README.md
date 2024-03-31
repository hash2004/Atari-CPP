# Atari Game 

## Overview
This project is an Atari-like game developed in C++. It includes various features such as player controls, bot movements, collision detection, and a scoring system.

## How to Play
- Use the arrow keys for player movement.
- Press 'b' to shoot bullets.
- Avoid or shoot bots to gain or lose points.
- Navigate through different levels with increasing difficulty.

## Features
- Multiple levels with unique challenges.
- Collision detection between players, bullets, and bots.
- Score tracking and display.
- Player and bot movement mechanics.

## Dependencies
- OpenGL
- GLUT

## Modules

### 1. Player
Handles player creation, movement, and interactions.
- **Files:**
  - `player.h`: Player class declaration.
  - `player.cpp`: Implementation of player functionalities.

### 2. Bullets
Manages bullet generation, movement, and collision logic.
- **Files:**
  - `butllets.h`: Bullet class declaration.
  - `bullets.cpp`: Implementation of bullet functionalities.

### 3. Bots
Controls bot behavior and movement logic.
- **Files:**
  - `bots.cpp`: Bot class implementation and movement logic.

### 4. Collision Detection
Responsible for handling collisions between different game entities.
- **Files:**
  - `coldet.h`: Collision detection class declaration.
  - `coldet.cpp`: Collision handling and logic.

### 5. Menu
Manages game menu and level selections.
- **Files:**
  - `menu.h`: Menu class declaration.
  - `menu.cpp`: Implementation of menu functionalities.

### 6. Main Game
The entry point of the game that integrates all modules.
- **Files:**
  - `game.cpp`: Main game logic and setup.
