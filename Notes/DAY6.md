[TOC]



# 类和对象

## 练习案例1 ：立方体类

**要求**：Cube类 求出立方体的面积和体积，分别用全局函数和成员函数判断两个立方体是否相等

```c++
class cube
{
public:
	void setData(int Long, int Short,int Height) {
		m_Long = Long;
		m_Short = Short;
		m_Height = Height;
	}

	int getSquare() {
		Square = m_Long * m_Height * m_Short;
		return Square;
	}

	void justice(int V) {
		getSquare();
		if (V == Square) {
			cout << "体积相等" << endl;
		}
		else {
			cout << "体积不相等" << endl;
		}
	}
private:
	int m_Long;
	int m_Short;
	int m_Height;
	int Square;
};

bool isSame(cube c1, cube c2) {
	if (c1.getSquare() == c2.getSquare()) {
		return true;
	}
	else {
		return false;
	}
}

int main(){
	cube c1;
	c1.setData(10, 20, 30);
	cube c2;
	c2.setData(20, 10, 30);	
	c1.justice( c2.getSquare());
	bool ret = isSame(c2, c1);
	if (ret) {
		cout << "same" << endl;
	}
	else {
		cout << "not same" << endl;
	}
	system("pause");
	return 0;
}
```



## 练习案例2 ：点和圆的关系

**要求**：设计圆形类，和一个点类，计算点和圆的关系。

### 未封装：

```c++
class point
{
public:
	void setPoint(int x, int y) {
		m_x = x;
		m_y = y;
	}

	int getX() {
		return m_x;
	}

	int getY() {
		return m_y;
	}

private:
	int m_x;
	int m_y;
};

class circle
{
public:
	void setCenter(point center) {
		m_center = center;
	}

	point getCenter() {
		return m_center;
	}
	void setR(int r) {
		m_R = r;
	}

	int getR() {
		return m_R;
	}

private:
	int m_R;
	point m_center;
};

void relation(circle &c,point p) {

	int i = (c.getCenter().getX() - p.getX())* (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int j = c.getR() * c.getR();
	if (i == j) {
		cout << "在圆上" << endl;
	}
	else if (i < j) {
		cout << "在圆内" << endl;
	}
	else {
		cout << "在圆外" << endl;
	}
}

int main(){
	circle c1;
	c1.setR(5);
	point center;
	center.setPoint(0, 0);
	c1.setCenter(center);
	point p1;
	p1.setPoint(3, 4);
	relation(c1, p1);
	return 0;
}
```

### 封装：

#### 1.封装实现：circle的函数声明

```c++
#pragma once
#include<iostream>
#include"point.h"
using namespace std;

class circle
{
public:
	void setCenter(point center);
	point getCenter();
	void setR(int r);
	int getR();
private:
	int m_R;
	point m_center;
};

```

#### 2.封装实现：clrcle函数的函数实现

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"circle.h"

	void circle::setCenter(point center) {
		m_center = center;
	}

	point circle::getCenter() {
		return m_center;
	}
	void circle::setR(int r) {
		m_R = r;
	}

	int circle:: getR() {
		return m_R;
	}


```

#### 3.封装实现：point的函数声明

```c++
#pragma once
#include<iostream>
using namespace std;

class point
{
public:
	void setPoint(int x, int y);
	int getX();
	int getY();
private:
	int m_x;
	int m_y;
};
```

#### 4.封装实现：poin的函数实现

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"point.h"

	void point::setPoint(int x, int y) {
		m_x = x;
		m_y = y;
	}

	int point::getX() {
		return m_x;
	}

	int point::getY() {
		return m_y;
	}

```

#### 5.封装实现：main函数

```c++
void relation(circle &c,point p) {

	int i = (c.getCenter().getX() - p.getX())* (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int j = c.getR() * c.getR();
	if (i == j) {
		cout << "在圆上" << endl;
	}
	else if (i < j) {
		cout << "在圆内" << endl;
	}
	else {
		cout << "在圆外" << endl;
	}
}

int main(){
	circle c1;
	c1.setR(5);
	point center;
	center.setPoint(0, 0);
	c1.setCenter(center);
	point p1;
	p1.setPoint(3, 4);
	relation(c1, p1);
	return 0;
}
```



## 构造函数和析构函数

构造函数的结构语法：

> 类名（）{}

析构函数的结构语法：

> ~类名（）{}

==注意：==析构函数不需要返回值 也不要写void

```c++
class person
{
public:
	//构造函数
	person() {
		cout << "构造函数的调用" << endl;
	}
	//析构函数
	~person() {
		cout << "析构函数的调用" << endl;
	}

};
```

### 构造函数的分类和调用

#### 拷贝构造和普通构造

```c++
//构造函数
person() {
	cout << "person的无参构造函数调用" << endl;
}

person(int a) {
	cout << "person的有参构造函数调用" << endl;
}
//拷贝构造函数
person(const person &p) {//记住
	age = p.age;
}
```

==注意==使用默认构造函数的时候不要带括号，不然会被编译器认为是函数声明

#### 构造函数的调用方法

```c++
void test01() {
	//括号法
	person p1;
	person p2(10);
	person p3(p2);
	//显示法
	person p4;
	person p5 = person(10);
	person p7 = person(p5);
	person(10);//匿名对象  特点：当前执行结束之后，系统会直接收回匿名和对象
	//不要利用拷贝构造来初始化匿名对象,编译器会认为是对象声明 person(p3); == = person p3;
	//隐式转换法
	person p8 = 10;//等价于person p4 = person(10);
	person p9 = p8;
}

```

#### 拷贝构造函数的调用时机

使用一个已经创建完成的对象来初始化一个新对象

```c++
void test() {
	person p1(10);
	person p2(p1);
}
```

值传递给函数传参

```c++
void dowork(person p) {//p为临时拷贝出来的值

}

void test01() {
	person p;
	dowork(p);//拷贝构造 但是不会修改真正的p
}
```

值方式返回局部对象

```c++
person dowork2() {
	person p3;
	cout << (int*)&p3 << endl;
	return p3;
}

void test02() {
	person p = dowork2();
	cout << (int*)&p << endl;  
}
int main() {
	//test();
	test02();
	system("pause");
	return 0;
}//根据p3返回一个拷贝的值，按照p3拷贝一个新的对象
```





#### ==只要创建一个类就会添加三个函数：==

1. 默认构造函数
2. 默认析构函数
3. 默认拷贝函数（值拷贝）

- 定义有参构造函数，c++不提供默认构造函数，但是会提供默认拷贝构造函数

- 定义拷贝构造函数，c++不会再提供其他狗凹函数

  ==只要写了有参构造函数，编译器就不会提供默认构造函数，依然提供拷贝构造函数==

  ==只要写了拷贝构造函数，编译器就不会提供其他构造函数==

  

  

##### 深拷贝和浅拷贝

浅拷贝会导致堆区的内存被重复释放

```c++
person(const person& p) {
	cout << "这是拷贝构造函数" << endl;
	m_age = p.m_age;
	m_Height = p.m_Height;
}
```

利用深拷贝解决浅拷贝造成的问题

```c++
	person(int age,int height) {
		m_Height = new int(height);
		m_age = age;
		cout << "这是有参构造函数" << endl;
		
	}

	person(const person& p) {
		cout << "这是拷贝构造函数" << endl;
		m_age = p.m_age;
		m_Height = new int(*p.m_Height);
	}

	~person() {
		cout << "这是析构函数" << endl;
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
	}
	int m_age;
	int* m_Height;
};
```

## 初始化列表

初始化列表初始化属性

构造函数（）：属性1（值1），属性2（值2）...{}

```c++
class person
{
public:
	person(int a,int b):m_age(a),m_Height(b){}

	~person() {
	}
	int m_age;
	int m_Height;
};

void test01() {
	person p1(10,160);
	cout << "p1的年龄为：" << p1.m_age << endl;

}

```



## 类对象作为类成员

```c++
class phone
{
public:
	phone(string name) {
		p_name = name;
	}

	string p_name;
};

class person
{
public:
	person(string name, string pname):m_name(name),m_phone(pname){}
	
	string m_name;

	phone m_phone;
};
```

==当其他类的成员作为本类的成员，其他类的构造函数先运行。析构函数是相反的；==

## 静态成员

静态成员保存在全局区中

==在编译阶段就会分配内存；==

无法解析的外部命令错误一般是链接阶段的错误

==所有对象共享一份数据==

==类内声明，类外初始化==

1. 通过对象进行访问
2. 通过类名进行访问

类外无法访问私有静态成员变量

==静态成员函数只能访问静态成员变量==

1. 通过类名访问静态成员函数
2. 通过对象访问静态成员函数

```c++
class person
{
public:
	static int m_A;
	static void func() {
		cout << m_B << endl;
	}
private:
	static int m_B;
};

 int person::m_A = 100;
 int person::m_B = 100;

void test01() {
	person p;
	cout << p.m_A << endl;
	person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
	//cout << p.m_B << endl;//错误 不可访问
	//1.通过函数访问
	person::func();
	//2.通过对象访问
	person p3;
	p3.func();
}

```



## 成员变量和成员函数分开存储

==只有非静态成员变量才属于类的对象上==

空对象占用的内存大小是1B，因为C++编译器会给每个空对象分配一个字节空间，为了区分空对象占内存的位置

非静态成员函数不属于类的对象上

静态成员函数不属于类的对象上

```c++
class person
{
public:
	int m_A;//非静态成员变量属于类的对象上
	static int m_B;//静态成员变量不属于类的对象上
};

int person::m_B = 1;

void test01() {
	person p;
	cout << "size of p =" << sizeof(p) << endl;
}

void test02() {
	person p;
	cout << "size of p =" << sizeof(p) << endl;
}
```



## this指针的用途

this指针指向被调用的成员函数所属的对象

this指针是隐含每一个==非静态成员函数==内的一种指针

this指针不需要定义，直接使用即可

成员属性和形参命名要区分开

```c++
class person
{
public:
	person() {

	}

	person(int age) {
		this->age = age;//this指向的是被调用的成员函数所属的对象
	}

	int age;
};

void test01() {
	person p1(18);
	cout << " p = " << p1.age << endl;
}
```





对于this解引用是对象

```c++
class person
{
public:
	
	person(int age) {
		this->age = age;//this指向的是被调用的成员函数所属的对象
	}

	person& personAddAge(int b) {//返回引用不返回值的原因是，返回值总是复制一份值
		age += b;
		return *this;
	}

	int age;
};

void test01() {
	person p1(18);
	cout << " p = " << p1.age << endl;
}

void test02() {
	person p1(10);
	person p2(19);
	
	p2.personAddAge(p1.age).personAddAge(p1.age).personAddAge(p1.age);
	cout << p2.age << endl;
}
```

## 空指针访问成员函数

- //此处是this->m_age,空指针可以访问成员，但是会崩溃
  		cout << "age = " << m_age << endl;

```c++
class person
{
public:
	person(int age) {
		m_age = age;
	}

	void showPerson() {
		cout << " person class" << endl;
	}

	void showPersonAge() {
		//this 为空则返回 提高健壮性
		if (this == NULL) {
			return;
		}
		//此处是this->m_age,空指针可以访问成员，但是会崩溃
		cout << "age = " << m_age << endl;
	}


	int m_age;
};

void test01() {

	person* p = NULL;
	p->showPerson();
	p->showPersonAge();
}
```



## const修饰成员函数

### 常函数

- 成员函数后加入const成为常函数
- 常函数中不可以修改成员属性
- 成员属性声明时加关键字mutable后，在常函数中依旧可以修改

```c++
void showPerson()const {
	m_age = 100;//表达式必须是可修改的左值
	cout << " person class" << endl;
}
```

这个const本质是修饰的this指针，让this指针指向的值也不可以修改

```c++
void showPerson() const
{
	this->m_B = 200;//可以修改，mutable修饰的变量
	m_age = 100;//不可以修改
	cout << " person class" << endl;
}

mutable int m_B;
int m_age;
```

### 常对象

- 声明对象前加const叫常对象
- 常对象只能调用常函数

```c++
void test02() {
	const person p(10);
	p.showPerson();
	p.m_age = 100;//不可以修改
	p.m_B = 100;//可以修改
}

mutable int m_B;
int m_age;
```

常对象只能调用常函数

```c++
void test02() {
	const person p(10);
	p.showPerson();
	p.m_B = 100;
	p.func();
}
严重性	代码	说明	项目	文件	行	禁止显示状态
错误(活动)	E1086	对象含有与成员 函数 "person::func" 不兼容的类型限定符	Project1_construct	E:\Code\C++\C++_02(2026.2.1)\Project1_construct\Project1_construct\construct.cpp	50	

```



## 友元

### 全局函数做友元

```c++
class Building
{
	friend void GoodGay(Building* building);
public:
	//构造函数
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom;

private:
	string m_BedRoom;
};

void GoodGay(Building* building) {
	cout << "我的好朋友正在访问的我的 ： " << building->m_SittingRoom << endl;

	cout << "我的好朋友正在访问的我的 ： " << building->m_BedRoom << endl;
}

void tesy01() {
	Building building;
	GoodGay(&building);
}
```



### 友元类

```c++
class Building;
class GoodGay 
{
public:
	//构造函数声明
	GoodGay();
	//访问函数声明
	void visit();

	Building* building;

};

class Building
{
	friend GoodGay;
public:
	//构造函数声明
	Building();

	string m_SittingRoom;

private:
	string m_BedRoom;
};

//类外实现成员函数；
Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay() {
    //初始化指针 指向堆区的一块内存
	building = new Building;
}

void GoodGay::visit() {
	cout << "正在访问：" << building->m_SittingRoom << endl;
	cout << "正在访问：" << building->m_BedRoom << endl;

}

void test01(){
	GoodGay gg;
	gg.visit();
}
```

### 成员函数作友元

```c++
class GoodGay 
{
public:
	//构造函数声明
	GoodGay();
	//访问函数声明
	void visit();//可以访问私有成员
	void visit2();//不可以访问私有成员


	Building* building;

};

class Building
{
	friend void GoodGay::visit();
public:
	//构造函数声明
	Building();

	string m_SittingRoom;

private:
	string m_BedRoom;
};

//类外实现成员函数；
Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << "1正在访问：" << building->m_SittingRoom << endl;
	cout << "1正在访问：" << building->m_BedRoom << endl;

}

void GoodGay::visit2() {
	cout << "2正在访问：" << building->m_SittingRoom << endl;
	cout << "2正在访问：" << building->m_BedRoom << endl;

}
```

==friend void GoodGay::visit();==
