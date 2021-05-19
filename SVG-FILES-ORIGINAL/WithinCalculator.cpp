#include "WithinCalculator.h"

bool WithinCalculator::isWithin(Rect rect, Figure* other)
{
    Vector<int> params;
    params = other->getParams();
    
    

    if (other->getFigureType() == "circle")
    {
        
        Circle circle(params[0], params[1], params[2], "");

        return circleWithinRect(circle, rect);
    }
    else if (other->getFigureType() == "rectangle")
    {
        Rect otherRect(params[0], params[1], params[2], params[3], "");
        
        return rectWithinRect(otherRect, rect);
    }
    else if (other -> getFigureType() == "line")
    {
        Line line(params[0], params[1], params[2], params[3], 0, "");
        return lineWithinRect(line, rect);
    }    
    return 0;
}

bool WithinCalculator::isWithin(Circle circle, Figure* other)
{
    Vector<int> params;
    params = other->getParams();

    if (other->getFigureType() == "circle")
    {
        Circle otherCircle(params[0], params[1], params[2], "");

        return circleWithinCircle(otherCircle, circle);
    }
    else if (other->getFigureType() == "rectangle")
    {
        Rect rect(params[0], params[1], params[2], params[3], "");
        return rectWithinCircle(rect, circle);
    }
    else if (other->getFigureType() == "line")
    {
        Line line(params[0], params[1], params[2], params[3], 0, "");
        return lineWithinCircle(line, circle);
    }
    return 0;
}


bool WithinCalculator::rectWithinRect(Rect& second, Rect& first)
{
    if ((second.getX() + second.getWidth()) < (first.getX() + first.getWidth())
        && (second.getX()) > (first.getX())
        && (second.getY()) > (first.getY())
        && (second.getY() + second.getHeight()) < (first.getY() + first.getHeight())
        )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool WithinCalculator::circleWithinRect(Circle& circle, Rect& rect)
{
	

    if ((circle.getCx() + circle.getR() > rect.getX() + rect.getWidth())  || // if outside on the right 
        (circle.getCx() - circle.getR() < rect.getX()) ||  // if outside on the left
        (circle.getCy() + circle.getR() > rect.getY() + rect.getHeight())  || // if outside on bot
        (circle.getCy() - circle.getR() < rect.getY())) // if outside on top
    {
        return false;
    }
    return true;


}

bool WithinCalculator::lineWithinRect(Line& line, Rect& rect)
{
    if ((pointWithinRect(rect.getX(), rect.getY() + rect.getHeight(),
        rect.getX() + rect.getWidth(), rect.getY(), line.getX1(), line.getY1()))
        && (pointWithinRect(rect.getX(), rect.getY() + rect.getHeight(),
            rect.getX() + rect.getWidth(), rect.getY(), line.getX2(), line.getY2())))
    {
        return true;
    }
    
    return false;
    
}

bool WithinCalculator::circleWithinCircle(Circle& first, Circle& second)
{
    double distanceBetweenCenters = sqrt(((first.getCx() - second.getCx()) 
                      * (first.getCx() - second.getCx())) + ((first.getCy() - second.getCy())
                      * (first.getCy() - second.getCy())));

    if (distanceBetweenCenters + second.getR() < first.getR())
    {
        return true;
    }

    return false;
}

bool WithinCalculator::rectWithinCircle(Rect& rect, Circle& circle)
{
    double distBtwCenterAndUpLeft = sqrt(((circle.getCx() - rect.getX())
        * (circle.getCx() - rect.getX())) + ((circle.getCy() - rect.getY())
            * (circle.getCy() - rect.getY())));

    double distBtwCenterAndUpRight = sqrt(((circle.getCx() - (rect.getX() + rect.getWidth()))
        * (circle.getCx() - (rect.getX() + rect.getWidth()))) + ((circle.getCy() - rect.getY())
            * (circle.getCy() - rect.getY())));

    double distBtwCenterAndDownLeft = sqrt(((circle.getCx() - rect.getX())
        * (circle.getCx() - rect.getX())) + ((circle.getCy() - (rect.getY() + rect.getHeight()))
            * (circle.getCy() - (rect.getY() + rect.getHeight()))));

    double distBtwCenterAndDownRight = sqrt(((circle.getCx() - (rect.getX() + rect.getWidth()))
        * (circle.getCx() - (rect.getX() + rect.getWidth()))) + ((circle.getCy() - (rect.getY() + rect.getHeight()))
            * (circle.getCy() - (rect.getY() + rect.getHeight()))));

    if (distBtwCenterAndUpLeft < circle.getR() && distBtwCenterAndUpRight < circle.getR() & distBtwCenterAndDownLeft < circle.getR() && distBtwCenterAndDownRight)
    {
        return true;
    }

    return false;
}

bool WithinCalculator::lineWithinCircle(Line& line, Circle& circle)
{
    double distBtwCenterAndFirst = sqrt(((circle.getCx() - line.getX1())
        * (circle.getCx() - line.getX1())) + ((circle.getCy() - line.getY1())
            * (circle.getCy() - line.getY1())));

    double distBtwCenterAndSecond = sqrt(((circle.getCx() - line.getX2())
        * (circle.getCx() - line.getX2())) + ((circle.getCy() - line.getY2())
            * (circle.getCy() - line.getY2())));

    if (distBtwCenterAndFirst < circle.getR() && distBtwCenterAndSecond < circle.getR())
    {
        return true;
    }
    return false;
}

bool WithinCalculator::pointWithinRect(int x1, int y1, int x2, int y2, int x, int y)
{
    if (x > x1 and x < x2 and y > y1 and y < y2)
    {
        return true;
    }

    return false;
}
