#pragma once // ��ֹͷ�ļ��ظ�����
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