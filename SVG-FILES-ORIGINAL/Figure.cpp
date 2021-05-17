#include "Figure.h"


int Figure::idCounter = 1;

int Figure::getId() const
{
	return id;
}

void Figure::setId(int _id)
{
	id = _id;
}

Figure::Figure()
{
	id = idCounter++;
}


