[TOC]







# 函数

## 函数的默认参数

==如果默认参数位置传入数据，就用传入的数据，没有就默认数据==

1. 错误写法：==默认参数后面的参数必须全部是默认参数==

```c++
int func(int a, int b = 10, int c) {
	return a + b + c;
}
```

2. 错误写法：==函数声明有默认参数，则函数实现就不能有默认参数==

```c++
int func(int a, int b = 10, int c = 10);

int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}
```

正确写法:==函数声明和实现只能有一个拥有默认参数==

```c++
int func(int a, int b, int c);

int func(int a = 30, int b = 10, int c = 10) {
	return a + b + c;
}

int main() {
	
	cout <<  func() << endl;

	system("pause");
	return 0;
}
```

## 函数占位参数

==占位参数也可以用默认参数==

```c++
void func(int a, int) {
	cout << "this is a func" << endl;
}

int main() {
	
	func(10,10);

	system("pause");
	return 0;
}
```



## 函数重载

==作用：==函数名可以相同，提高复用性

1. 同一个作用域
2. 函数名相同
3. 函数参数，类型，顺序不同

==注意==函数的返回值不同不可以作为条件

```c++
void func(int a, int) {
	cout << "this is a fuc a" << endl;
}

void func(int a) {
	cout << "this is a fuc b" << endl;
}

int main() {
	
	func(10,10);
	func(10);
	system("pause");
	return 0;
}
```



### 注意事项：

1. 引用作为重载的条件

   ```c++
   void func(int& a) {
   	cout << "this is a fuc a" << endl;
   }
   
   void func(const int &a) {
   	cout << "this is a fuc b" << endl;
   }
   
   int main() {
   	int a = 10;
   	func(a);
   	func(10);
   	system("pause");
   	return 0;
   }
   ```

   

2. 函数重载碰到默认参数

```c++
void func2(int a,int b) {
	cout << "func2（int a）的调用" << endl;
}

void func2(int a) {
	cout << "func2（int a）的调用" << endl;
}

int main() {
	int a = 10;
	func(a);
	func(10);
	func2(a);
	func2(a,10);
	system("pause");
	return 0;
}
```























