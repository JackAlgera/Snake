#include "Fruit.h"



Fruit::Fruit(int i, int j)
{
	pos.i = i;
	pos.j = j;
}


Fruit::~Fruit()
{
}

void Fruit::draw(int squareSize, sf::RenderWindow& window)
{
	sf::VertexArray cell(sf::Quads, 4);
	cell[0].position = sf::Vector2f(pos.j*squareSize + (pos.j + 1) * 1, pos.i*squareSize + (pos.i + 1) * 1);
	cell[1].position = sf::Vector2f(pos.j*squareSize + (pos.j + 1) * 1, (pos.i + 1)*squareSize + (pos.i + 1) * 1);
	cell[2].position = sf::Vector2f((pos.j + 1)*squareSize + (pos.j + 1) * 1, (pos.i + 1)*squareSize + (pos.i + 1) * 1);
	cell[3].position = sf::Vector2f((pos.j + 1)*squareSize + (pos.j + 1) * 1, pos.i*squareSize + (pos.i + 1) * 1);

	cell[0].color = sf::Color::Red;
	cell[1].color = sf::Color::Red;
	cell[2].color = sf::Color::Red;
	cell[3].color = sf::Color::Red;

	window.draw(cell);
}

bool Fruit::equals(Position pos)
{
	if (this->pos.i == pos.i)
	{
		if (this->pos.j == pos.j)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}