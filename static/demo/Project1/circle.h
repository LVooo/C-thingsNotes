#pragma once // ��ֹͷ�ļ��ظ�����
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
	Point center; // �����п�������һ���� ��Ϊ�����еĳ�Ա
};