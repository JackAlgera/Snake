#pragma once
#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "Fruit.h"

/*
Class that allows us to play the Snake game.
It manages the fruits aswel as the snake.

Author : Jacobus Algera
*/

class Game
{
public:
	Game(int i, int j, int length);
	~Game();

	void draw(sf::RenderWindow& window, int squareSize);		//Draws the snake and the fruits onto the window.
	bool update(int numberOfSquares, int fruitChance);			
	bool fruitEaten();											//Returns true if the snake ate a fruit this turn, and false otherwise.

	void addFruit(int fruitChance, int numberOfSquares);		
	void resetFruit() { listFruits.clear(); }
public:
	Snake snake;
private:
	std::vector<Fruit> listFruits;
	bool fruitHasBeenEaten = false;
	Position lastSnakeTail;
};

