#include<iostream> 
using namespace std;

class Apple
{
	int i;
public:
	Apple()
	{
		i = 0;
		cout << "Inside Constructor\n";
	}
	~Apple()
	{
		cout << "Inside Destructor\n";
	}
};

