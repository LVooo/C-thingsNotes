#include "circle.h";

double Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(double r)
{
	radius = r;
}

Point Circle::getCenter()
{
	return center;
}

void Circle::setCenter(double x, double y)
{
	center.setAxisx(x);
	center.setAxisy(y);
}