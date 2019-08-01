//
#include<iostream>
using namespace std;

//	一:函数回顾与后置返回类型
//void func123(int, int);	//函数声明 函数原型
//void func(int a, int b);//函数定义
//auto:					//变量自动类型推断
//auto func(int a, int b)->void;//函数声明
//auto func(int a, int b)->void;//函数定义
//{
//	return;
//}
	//二:内联函数
inline int myfunc(int testv)// 函数定义前加inline， 这个普通函数就变成了内联函数。
{
	return 1;
}
int& myfunc()
{
	int tmpvalue = 9;
	cout << &tmpvalue << endl;
	return tmpvalue;
}
int main()
{
	int &k = myfunc();
		cout << &k << endl;
	//	一:函数回顾与后置返回类型
	//	函数定义中，形参如果在函数体内用不到的话，则可以不给形参变量名字，只给其类型。
	//	函数声明是，可以只有形参类型，没有形参名。
	//	把函数返回类型放到函数名字之前，这种写法，叫做前置返回类型。
	//	c++11中，后置返回类型。就是在函数声明和定义中，把返回类型卸载参数列表之后。
	//	前面放auto，表示函数返回类型放到参数列表后，而放在参数列表之后的返回类型是通过->开始的。
	
	//二:内联函数:在函数定义前曾加inline， 导致这个普通函数就变成了内联函数。
	//函数体很小，调用又很频繁的这种函数。咱们引入liline
	//(1)inline影响编译器，在编译阶段对inline这种函数进行处理，系统尝试调用该函数的动作替换为函数本体。通过这种方式来提升性能。
	//inline int myfunc(int testv){return 1}
	//int abc = myfunc(5); //int abc = 1; 直接把调用函数改成这种语句。
	//(2)inline 只是我们开发者对编译器的一个建议，编译器可以尝试去做，也可以不去做，这取决于编译器的诊断功能，也就是说，决定权在编译器，我们控制不了。
	//(3)内联函数定义要放在头文件.h中。这样需要用到这个内联函数的cpp文件都能通过include把这个内联函数的源代码include进来。
	//一边朝到这个函数的本体源代码并尝试将该函数的调用替换为函数体内的语句。

	//优缺点
	//代码膨胀的问题，所以内联函数函数体尽量要少。
	//注意》各种编译器对inline的处理各有不同，inline函数精良可能少。循环分支递归尽量不要用，否则编译器可能会用为代码复杂拒绝让这个函数
	//成为一个inline函数。
	//constexpr(本课程2.3中常量介绍)函数可以看成是更严格的一种内联函数。
	//constexr int mf(){...代码谢的特别简单，否则编译错误}。
	//inline这种函数也有点类似宏这种函数(宏展开) #define ABC 一堆函数 用一堆宏替换函数语句。
		
	//四:const char* , char const*, char *const 三者的区别
		char str[] = "I Love China!";
		char str1[] = "I Love Beijing!";
		
		//const char *p 解析
		const char *p = str;//但是指向地址的内容不可改变，指向可以改变。
		p = str1;
	//	*p = 'Y';	//指向地址的内容不可改变。
		p++;

		//char* const p 解析
		char* const p1 = str1;//指向不可以改变， 但是指向内容可以改变。
	//	 p1 = str;	//指向不可以改变.
		p1[2] = 'Y';

		//const 引用解析
		int i = 100;
		int b = 9898;
		const int &a = i; //a的内容不能修改，
		i = 888;
		//a = 500; a的内容不能修改

		//int& b = 31; 不合法。
		const int &b = 31; //合法;
}