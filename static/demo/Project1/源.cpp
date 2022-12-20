#include <iostream>
using namespace std;

class Student
{
public:
	// 类中的属性和行为 我们统一称为成员
	// 属性 成员属性 成员变量
	// 行为 成员函数 成员方法


	string name;
	int number;

	void showInfo()
	{
		cout << "学生的姓名是：" << name << " 编号为：" << number << endl;
	}
};

int main()
{
	Student s1;
	s1.name = "小葛";
	s1.number = 5332112;
	
	s1.showInfo();

	system("pause");
	return 0;
}