#pragma once
#include "Position.h"
#include <SFML\Graphics.hpp>

/*
Class that handles the Fruits used in the game

Author : Jacobus Algera
*/

class Fruit
{
public:
	Fruit(int i, int j);
	~Fruit();

	void draw(int squareSize, sf::RenderWindow& window);
	bool equals(Position pos);

private:
	Position pos;
};

