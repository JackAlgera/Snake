#include "Game.h"
#include "Fruit.h"



Game::Game(int i, int j, int length)
{
	snake = Snake(i, j, length);
	listFruits = {};
}


Game::~Game()
{
}

void Game::draw(sf::RenderWindow & window, int squareSize)
{
	for (int i = 0; i < listFruits.size(); i++)				//Goes through the list of fruits and draws each one.
	{
		listFruits[i].draw(squareSize, window);
	}
	snake.draw(window, squareSize);							//Draws the snake
}

bool Game::update(int numberOfSquares, int fruitChance)
{
	if (fruitHasBeenEaten)									//If a fruit was eaten last frame it's length will increase
	{
		snake.addTail(lastSnakeTail);
		fruitHasBeenEaten = false;
	}

	if (this->fruitEaten())									//If a fruit was eaten this turn, we set the variable fruitHasBeenEaten to true, so that next frame the snake with increase in size.
	{
		fruitHasBeenEaten = true;
		lastSnakeTail = snake.getLastSnakeBodyPart();
	}

	this->addFruit(fruitChance, numberOfSquares);			//Method that gives a chance to generates a fruit every frame
	return snake.update(numberOfSquares);					
}

bool Game::fruitEaten()										//Checks to see if the snake has eaten a fruit this turn, e.g whether or not the head of the snake is in contact with a fruit from the list.
{
	bool fruitEaten = false;
	int k = 0;

	while ((k < listFruits.size()) && !fruitEaten)
	{
		Position snakeHead = snake.getHead();
		if (listFruits[k].equals(snakeHead))
		{
			fruitEaten = true;
			listFruits.erase(listFruits.begin() + k);
		}
		else
			k++;
	}
	return fruitEaten;
}

void Game::addFruit(int fruitChance, int numberOfSquares)
{
	if ((rand() % 100) < fruitChance)
	{
		int i = rand() % numberOfSquares;
		int j = rand() % numberOfSquares;
		listFruits.push_back(Fruit(i, j));
	}
}
