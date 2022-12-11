# C++thingsNotes

## **const定义和作用**
- **防止修改，起保护作用，增强程序的健壮性和鲁棒性**（指在程序崩溃时能对各种异常情况（如输入错误、磁盘故障、网络过载、有意攻击）进行更好的处理）
```cpp
void f(const int i){
    i ++; // 不能修改常量
}
```
- const只有常量表达式初始化时才能作为常量表达式，其他情况const只是在限定一个变量，不要将其与常量混淆。
- **节省空间，减少不必要内存分配**，从汇编角度来看const给出的是内存地址（**一份拷贝**），而#define宏定义给出的是立即数（**多份拷贝**）
- ***注意***：非const的变量默认为extern。如果要在其他文件访问const变量的话需要显示定义为extern。
>不同文件访问非const变量
```cpp
//file1.cpp
int n;
//file2.cpp
extern int n;
int main(){
    std::cout << (n+10) << std::endl;
}
```
>不同文件访问const变量
```cpp
//file1.cpp
extern const int n = 1;
//file2.cpp
extern const int n;
int main(){
    cout << n << endl;
}
```
>小结：显式声明后的const变量需要进行初始化。因为常量在定义后就不能被修改，所以定义时必须初始化！！
- **定义常量**
```cpp
const int a = 0;
a = 1; // error: assignment of read-only variable 'a'
const int i, j = 0; // error: uninitialized const 'i'
```
错误之处：
1. a为常量，不能再更改！
2. i为常量，必须进行初始化！  

## **指针与const**
与指针相关的const有四种
```cpp
const char *a; //指向常量的指针or指向const对象的指针
char const *a; //同上
char *const a; //常指针、const指针or指向类型对象的const指针
const char *const a; //指向const对象的const指针a

const int *pOne;   //指向整形常量的指针，它指向的值不能修改
int * const pTwo;   //指向整形的常量指针，它不能再指向别的变量，但指向（变量）的值可以修改。 
const int *const pThree; //指向整形常量的常量指针 。它既不能再指向别的常量，指向的值也不能修改。

//ex
int a=3;
int b;

/*定义指向const的指针（指针指向的内容不能被修改）*/ 
const int* p1; 
int const* p2; 

/*定义const指针(由于指针本身的值不能改变所以必须得初始化）*/ 
int* const p3=&a; 

/*指针本身和它指向的内容都是不能被改变的所以也得初始化*/
const int* const p4=&a;
int const* const p5=&b; 

p1=p2=&a; //正确
*p1=*p2=8; //不正确（指针指向的内容不能被修改）

*p3=5; //正确
p3=p1; //不正确（指针本身的值不能改变） 

p4=p5;//不正确 （指针本身和它指向的内容都是不能被改变） 
*p4=*p5=4; //不正确（指针本身和它指向的内容都是不能被改变）
```
>小结：  
如果\*在const右侧，则const就是用来修饰指针所指向的变量，即指针指向为常量。  
如果\*在const左侧const就是修饰指针本身，即指针本身是常量。  
**可以分为指针指向的内容和指针本身两种概念**  
指向const的指针（指针指向的内容不能被修改）const关健字总是出现在\*的左边而const指针（指针本身不能被修改）const关健字总是出现在\*的右边，那不用说两个const中间加个*肯定是指针本身和它指向的内容都是不能被改变的。

具体使用如下：  
1）**指向常量的指针**  
指针指向的值不可以被修改。
```cpp
const int *p;
p = 10; //error
```
2）**常指针**  
const指针必须进行初始化，且const指针的值不能修改。  
如果要修改ptr指针所指向的值，可以通过非const指针来修改。
```cpp
int num = 0;
int *const ptr = &num; //const指针必须初始化！且const指针的值不能修改
int *t = &num;
*t = 1;
```
当把一个const常量的地址赋值给ptr的时候，由于ptr指向的是一个变量，而不是const变量，所以会报错，出现：const int* -> int*错误！
```cpp
const int num = 0;
int *const ptr = &num; //error! const int* -> int*
```
3）**指向常量的常指针**  
ptr是一个const指针，然后指向了一个int类型的const对象
```cpp
const int *p = 3;
const int *const ptr = &p;
```

## **函数中使用const**
>const修饰函数返回值

与const修饰普通变量以及指针的含义基本相同：  
1） **const int**  
本身无意义，因为参数返回本身就是赋值给其他的变量！  
```cpp
const int func1();
```
2）**const int***  
指针指向的内容不变。
```cpp
const int* func2();
```
3）**int \*const**  
指针本身不可变。
```cpp
int *const func3();
```
>const修饰函数参数

1）**传递过来的参数及指针本身在函数内不可变**，没有意义
输入参数采用”值传递“，由于函数自动产生临时变量用于复制该函数，该函数无需保护所以不需要加const修饰。    
参数在函数体内不能被修改，但因为var本身就是形参，在函数内不会改变，包括传入的形参是指针也是一样，所以此处没有任何意义。
```cpp
void func(const int var); //传递过来的参数不可变
void func(int *const var); //指针本身不可变
```
2）**参数指针所指内容为常量不可变**  
此处src为输入参数，dst为输出参数。若函数体内语句试图修改src的内容，则编译器将报错。  
```cpp
void StringCopy(char *dst, const char *src);
```
3）**参数为引用，为增加效率同时防止修改**
```cpp
void func(const A &a)
```
对于非内部数据类型（如自己创建的数据类型A）的参数而言，像void func(A a)这样声明的函数注定效率比较低。因为函数体内将产生A类型的临时对象用于复制参数a，而临时对象的构造、复制、析构过程都需要花费时间；相反内部数据类型的参数不存在这个过程，而复制也非常快，”值传递“与”引用传递“效率几乎相当。可以将函数声明改为void func(A &a)来提高效率，因为**引用传递**仅借用参数的别名，不需要产生临时对象，但引用传递可能会改变参数a，所以加入const修饰。
>小结：  
1.对于非内部结构数据类型，应该将”值传递“的方式改为”const引用传递“，目的使提高效率。如：void func(A a) -> void func(const A &a)。  
2.对于内部数据类型（如int）的输入参数，不要将”值传递“方式改为”const引用传递“。否则既达不到提高效率的目的，又降低了函数的可理解性。如：void func(int x) 不应该-> void func(const int &x);

## **类中使用const**
在一个类中，任何不会修改数据成员的函数都应该声明为const类型（常成员函数）。如果在编写const成员函数时，不慎修改了数据成员，或者调用了其他非const成员函数，编译器将报错指出错误，提高程序的健壮性。  
**只有常成员函数才有资格操作常量或常对象！**  
对于类中的const成员变量必须通过初始化列表进行初始化，如下所示：
```cpp
class Apple{
    private:
        int people[100];
    public:
        Apple(int i);
        const int apple_number;
};

Apple::Apple(int i):apple_number(i)
{
     
}
```
const对象只能访问const成员函数，而非const对象可以访问任意的成员函数。如：
```cpp
//apple.cpp
class Apple
{
private:
    int people[100];
public:
    Apple(int i); 
    const int apple_number;
    void take(int num) const;
    int add();
    int add(int num) const;
    int getCount() const;

};
//main.cpp
#include<iostream>
#include"apple.cpp"
using namespace std;

Apple::Apple(int i):apple_number(i)
{

}
int Apple::add(){
    take(1);
    return 0;
}
int Apple::add(int num) const{
    take(num);
    return num;
}
void Apple::take(int num) const
{
    cout<<"take func "<<num<<endl;
}
int Apple::getCount() const
{
    take(1);
    add();  // error
    return apple_number;
}
int main(){
    Apple a(2);
    cout<<a.getCount()<<endl;
    a.add(10);
    return 0;
}
```
>编译：g++ -o main main.cpp apple.cpp

getCount()调用了add方法，而add方法并非const修饰，所以运行报错。**const成员函数只能访问const成员函数**  
当调用改为：
```cpp
const Apple b(3);
b.add(); //error
```
此时，可以证明const对象只能访问const成员函数。  
除了上述的初始化const常量用初始化列表方式外，也可以通过下面方法：  
一：将**常量**定义与static结合，也就是：
```cpp
static const int apple_number;
```
二：在外面初始化：
```cpp
const int Apple::apple_numebr = 10;
```
如果使用**C++11**进行编译的话，可以在定义时直接初始化，可以写成：
```cpp
static const int apple_number = 10;
// or
const int apple_number = 10;
```
编译时直接加上-std=c++11即可  
但static静态成员**变量**不能在类的内部初始化。  
在类的内部只是声明，定义必须在类定义体的外部，通常在类的实现文件中初始化。即c++11不能对此项（变量而不是常量）进行声明并直接初始化。  
在类中声明：
```cpp
static int ap;
```
在类实现文件中使用：
```cpp
int Apple::ap = 666;
```  