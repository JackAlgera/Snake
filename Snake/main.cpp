#include <SFML\Graphics.hpp>
#include "Game.h"
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>

/*
The good old snake game.

	Z
Q	S	D  : To control the snake

Press R to restart the game.

Author : Jacobus Algera
*/

const int numberOfSquares = 50; //Size in squares of the window
const int squareSize = 12;		//size in pixels of each square
sf::Vector2f screenDimensions(numberOfSquares*squareSize + (numberOfSquares + 1) * 1, numberOfSquares*squareSize + (numberOfSquares + 1) * 1);
int snakeSize = 10;				//initial snake size
int fruitChance = 7;			// 0 no chance, 100 always


int main()
{
	srand(time(0));				// Initialises the random number generator
	bool gameEnd = true;		// Boolean to keep track of game pauses and finishes

	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Snake");	//Initialise the window
	window.setFramerateLimit(20);	//Sets the FPS of the window, which also determines the speed of the snake
	
	//Initialise the game, and thus the snake
	Game newSnake((int)(numberOfSquares/2), (int)(numberOfSquares / 2)-5, snakeSize);
	newSnake.draw(window, squareSize);
	window.display();

	while (window.isOpen())				//main game loop
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))	//Keeps track of and handles events
		{
			if (evnt.type == sf::Event::Closed)
			{
				window.close();
			}
			if (evnt.type == sf::Event::TextEntered) //Events to change the direction the snake is heading in
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					if(!(newSnake.snake.getDirection() == 3))
						newSnake.snake.setDirection(1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					if (!(newSnake.snake.getDirection() == 1))
						newSnake.snake.setDirection(3);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					if (!(newSnake.snake.getDirection() == 2))
						newSnake.snake.setDirection(0);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					if (!(newSnake.snake.getDirection() == 0))
						newSnake.snake.setDirection(2);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) //R to restart the game
				{
					gameEnd = false;
					newSnake.snake = Snake((int)(numberOfSquares / 2), (int)(numberOfSquares / 2) - 5, snakeSize);
					newSnake.resetFruit();
				}
			}
		}

		if (!gameEnd)			//If the game is still running, draw the snake each frame
		{
			window.clear();
			newSnake.draw(window, squareSize);
			window.display();
		}

		if (newSnake.update(numberOfSquares, fruitChance))		//Updates the snakes current position, and checks whether the snake came into contact with itself or the edges of the window
		{
			gameEnd = true;
		}
	}

	return 0;
}