#include "Position.h"



Position::Position(int i, int j)
{
	this->i = i;
	this->j = j;
}

Position::Position()
{
}


Position::~Position()
{
}

bool Position::equals(Position pos)
{
	if (this->i == pos.i)
	{
		if (this->j == pos.j)
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
