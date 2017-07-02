#pragma once
/*
Class that handles the position of each part of the snake and the fruits

Author : Jacobus Algera
*/

class Position
{
public:
	Position(int i, int j);
	Position();
	~Position();

	bool equals(Position pos);

public:
	int i;
	int j;
};

