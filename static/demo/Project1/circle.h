#pragma once // 防止头文件重复包含
#include <iostream>
#include "point.h"
using namespace std;

class Circle
{
public:
	double getRadius();

	void setRadius(double r);

	Point getCenter();

	void setCenter(double x, double y);

private:
	double radius;
	Point center; // 在类中可以让另一个类 作为本类中的成员
};