#include "Snake.h"



Snake::Snake(int i, int j, int length)
{
	for (int k = 0; k < length; k++)
	{
		snakeBody.push_back(Position(i, j+k));
	}
	direction = 1;
}

Snake::Snake()
{
}


Snake::~Snake()
{
}

void Snake::draw(sf::RenderWindow& window, int squareSize)
{
	for (int k = 0; k < snakeBody.size(); k++)				//Goes through the list containing each part of the snake to draw it
	{
		int i = (int) snakeBody[k].i;
		int j = (int) snakeBody[k].j;
		this->drawVertexSquare(k, i, j, squareSize, window);
	}
}

void Snake::drawVertexSquare(int k, int i, int j, int squareSize, sf::RenderWindow& window)
{
	sf::VertexArray cell(sf::Quads, 4);
	cell[0].position = sf::Vector2f(j*squareSize + (j + 1) * 1, i*squareSize + (i + 1) * 1);
	cell[1].position = sf::Vector2f(j*squareSize + (j + 1) * 1, (i+1)*squareSize + (i + 1) * 1);
	cell[2].position = sf::Vector2f((j+1)*squareSize + (j + 1) * 1, (i+1)*squareSize + (i + 1) * 1);
	cell[3].position = sf::Vector2f((j+1)*squareSize + (j + 1) * 1, i*squareSize + (i + 1) * 1);
	
	cell[0].color = color;
	cell[1].color = color;
	cell[2].color = color;
	cell[3].color = color;

	window.draw(cell);
}

bool Snake::snakeIntersection(int numberOfSquares)
{
	Position pos = snakeBody[0];
	bool test = false;
	int i = 1;

	if ((pos.i < 0) | (pos.j < 0) | (pos.i > numberOfSquares-1) | (pos.j > numberOfSquares-1)) //gone outside of the window
		test = true;

	while ((i < snakeBody.size()) && !test)
	{
		if (pos.equals(snakeBody[i]))
			test = true;
		else
			i++;
	}

	return test;
}

bool Snake::update(int numberOfSquares)		//Method that lets the snake move around on the window
{
	Position pos1 = snakeBody[0];
	Position pos2 = snakeBody[1];
	for (int i = 0; i < snakeBody.size() - 1; i++)
	{
		pos2 = snakeBody[i + 1];
		snakeBody[i + 1] = pos1;
		pos1 = pos2;
	}
	if (direction == 1)
	{
		Position pos = snakeBody[0];
		snakeBody[0] = Position(pos.i, pos.j - 1);
	}
	if (direction == 3)
	{
		Position pos = snakeBody[0];
		snakeBody[0] = Position(pos.i, pos.j + 1);
	}
	if (direction == 0)
	{
		Position pos = snakeBody[0];
		snakeBody[0] = Position(pos.i - 1, pos.j);
	}
	if (direction == 2)
	{
		Position pos = snakeBody[0];
		snakeBody[0] = Position(pos.i + 1, pos.j);
	}
	if (this->snakeIntersection(numberOfSquares))				//returns a boolean value, which is true if the snake came into contact with the sides of the window, or with itself, and false otherwise.
		return true;
	else
		return false;
}
