# Static

当与不同类型一起使用时，Static关键字具有不同的含义。
## **静态变量**
- 函数中的静态变量

当变量声明为static时，空间将在程序的**生命周期内分配**。多次调用函数，空间也只分配一次，前一次调用中的变量值通过下一次函数调用传递。（存储先前函数状态）
```cpp
void demo()
{
    // static variable
    static int count = 0;
    cout << count << " "；

    // value is updated and will be carried to next function call
    count ++;
}

int main()
{
    for (int i = 0; i < 5; i ++)
        demo();
    return 0;
}
```
输出
```cpp
0 1 2 3 4
```
因为上述变量count被声明为static，因此它的值通过函数来传递，每次调用函数时都不会对变量计数进行初始化。
- 类中的静态变量

因为他们在单独的静态存储中分配了空间，所以声明为static的变量只能被初始化一次，因此类中的静态变量由**对象共享**。对于不同对象，不能有相同静态变量的多个副本，因此静态变量不能使用构造函数初始化。如
```cpp
class Apple
{
public:
    static int i;
    Apple()
    {
        // Do nothing
    };
};

int main()
{
    Apple obj1;
    Apple obj2;
    obj1.i = 2;
    obj2.i = 3;

    cout << obj1.i << obj2.i;
}
```
当尝试为多个对象创建静态变量i的多个副本时无法发生。  
因此，类中的静态变量应由用户使用类外的类名和范围解析运算符显示初始化，如下所示：
```cpp
class Apple
{
public:
    static int i;
    Apple()
    {
        // Do nothing
    };
};

int Apple::i = 1;

int main()
{
    Apple obj;

    cout << obj.i;
}
```
输出：
```cpp
1
```
**静态成员**
- 类对象为静态

就像变量一样，对象也在声明为static时具有范围，直到程序的生命周期。
ex：非静态对象
```cpp
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

int main() 
{ 
	int x = 0; 
	if (x==0) 
	{ 
		Apple obj; 
	} 
	cout << "End of main\n"; 
} 
```
输出
```cpp
Inside Constructor
Inside Destructor
End of main
```
在上面程序中，if块中声明的是非静态，变量的范围仅在if块内。因此会在创建对象时依次调用构造函数和析构函数。  
如果将该对象声明为静态，输出会产生如下变化。
```cpp
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

int main() 
{ 
	int x = 0; 
	if (x==0) 
	{ 
		static Apple obj; 
	} 
	cout << "End of main\n"; 
}
```
输出
```cpp
Inside Constructor
End of main
Inside Destructor
```
现在则是在main函数结束后调用析构函数，因为静态对象的范围是贯穿程序的生命周期的。
- 类中的静态函数

与前者相同，**静态成员函数也不依赖于类的对象**。可以使用对象和'.'来调用静态成员函数，但建议使用类名和范围解析运算符调用静态成员。  
允许静态成员函数仅访问静态数据成员或其他静态成员函数，它们无法访问类的非静态数据成员或成员函数。
```cpp
class Apple
{
    public:
        // static member function
        static void printMsg()
        {
            cout << "Welcome to Apple!";
        }
};

int main()
{
    Apple::printMsg();
}
```
输出：
```cpp
Welcome to Apple!
```
**限定访问范围** static还有限定访问范围的作用，类似于匿名名字空间。
```cpp
// source1.cpp
extern void sayHello();
const char *msg = "Hello World!\n";
int main() {
	sayHello();
	return 0;
}
// source2.cpp
#include <cstdio>
extern const char *msg;
void sayHello()
{
	printf("%s", msg);
}
```
g++对于上面两个代码文件是可以正常编译打印Hello World！但如果给source1.cpp中的msg加上static，则会导致undefined reference to 'msg'的编译错误：
```cpp
// source1.cpp
extern void sayHello();
static const char *msg = "Hello World!\n";
int main() {
	sayHello();
	return 0;
}
```