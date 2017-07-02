#pragma once
#include <SFML\Graphics.hpp>
#include "Position.h"

/*
Class that handles and creates the Snake used in the game.

Author : Jacobus Algera
*/
class Snake
{
public:
	Snake(int i, int j, int length);
	Snake();
	~Snake();

	void setDirection(int key) { direction = key; }
	int getDirection() { return direction; }
	Position getHead() { return snakeBody[0]; }

	void draw(sf::RenderWindow& window, int squareSize);	//Draws each part of the snake onto the given window, using the drawVertexSquare method
	void drawVertexSquare(int k, int i, int j, int squareSize, sf::RenderWindow& window);	//The snake is created using vertex,
	bool snakeIntersection(int numberOfSquares);			//Checks to see whether the snake came into contact with the sides of the window, or with itself
	bool update(int numberOfSquares);

	Position getLastSnakeBodyPart() { return snakeBody.back(); }
	void addTail(Position pos) { snakeBody.push_back(pos); }

private:
	int speed;
	sf::Color color = sf::Color::Green;
	std::vector<Position> snakeBody;
	int direction;											//0 up, 1 left, 2 down, 3 right
};

