#include<iostream>
using namespace std;
class A
{
    virtual void fun() {}
};
class B
{
    virtual void fun2() {}
};
class C : virtual public  A
{
public:
    virtual void fun3() {}
};

int main()
{
    /**
     * @brief 8 8 16  ��������̳ж���麯������̳������麯����vptr
     */
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C);

    return 0;
}