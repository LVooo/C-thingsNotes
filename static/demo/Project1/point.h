#pragma once // 防止头文件重复包含
#include <iostream>
using namespace std;

class Point
{
public:
	double getAxisx();

	void setAxisx(double x);

	double getAxisy();

	void setAxisy(double y);

private:
	double m_x;
	double m_y;
};