#include <iostream>
using namespace std;

class Student
{
public:
	// ���е����Ժ���Ϊ ����ͳһ��Ϊ��Ա
	// ���� ��Ա���� ��Ա����
	// ��Ϊ ��Ա���� ��Ա����


	string name;
	int number;

	void showInfo()
	{
		cout << "ѧ���������ǣ�" << name << " ���Ϊ��" << number << endl;
	}
};

int main()
{
	Student s1;
	s1.name = "С��";
	s1.number = 5332112;
	
	s1.showInfo();

	system("pause");
	return 0;
}