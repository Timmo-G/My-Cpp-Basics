[toc]







# 类和对象_问题

## 类是什么？对象是什么？

回答：类是封装起来的一组操作，对象是类创建的

**修正：类是一种自定义的类型，用来描述对象的行为和属性对象是类的实例，是存在与内存中的数据实体**

## 类和struct的区别？

回答：类可以封装函数，而struct只能定义变量

**修正：class和struct几乎一样，唯一的区别就是class默认private，struct默认public**

## public与private？

回答：public是公用成员或者数据，private是私有成员或者数据，只有类中规定的方式才可以访问private

**修正：public定义类的对外接口，private隐藏内部细节，实现封装**

## 类和对象是否占用内存？

回答：类不占用内存，对象占用内存

**修正：类本身不占用空间，但是在编译阶段会生成类型信息；对象实例才会真正占用空间**

# 类和对象_任务

## 写一个完整类：

- 私有成员：id, score
- 公有成员：
  - set
  - get
  - display

要求：

- 成员函数部分写在类外
- 必须使用 `类名::函数名`
- 在 main 中创建 2 个对象

```c++
class GradeBook
{
public:
	void setCourseName(string name) {
		id = name;
	}

	string getCourseName() {
		return id;
	}

	void displayMessage() {
		cout << "welcome to the grade book for\n" << getCourseName() << "!" << endl;
	}
private:
	string id;
	int score;
};
```



修改：

```c++
```





## 写一个类 Rectangle：

- 长宽为私有
- 面积函数
- 构造时初始化

```c++
class rectangle
{
public:
	rectangle(int l,int s) {
		setchankua(l, s);
	}

	void setchankua(int lon,int kua) {
		chang = lon;
		kuan = kua;
	}
	int square(int lon, int shor) {
		return chang * kuan;
	}

private:
	int chang;
	int kuan;
};

```

修改：

```c++
class Rectangle
{
public:
 Rectangle(int l, int s) : chang(l), kuan(s) {}
    
 void setchankua(int lon,int kua) {
		chang = lon;
		kuan = kua;
	}
 int square() const {
    return chang * kuan;
	}
private:
	int chang;
	int kuan;
}
```



# 类和对象_口头问题

## 类和对象的区别？

同上

## 为什么要private？

有些数据和操作要保护起来

## 如果全是public会怎么样？

可能会产生数据或操作冲突

## 类是否占空间？

不占



# 类和对象_强化题

## 成员函数属于对象吗？占用对象内存吗？

成员函数不是对象，不占用成员内存

**修正：**

- 成员函数属于类
- 不存储在对象内部
- 所有对象共享同一份函数代码

成员函数代码在程序代码段（text segment），
 对象内只保存数据成员。

## 为什么多个对象可以共用一份成员函数代码

对象中存储的是成员函数的副本

**修正：**

​	对象中**没有函数副本**。

对象内只存数据。
 函数只有一份，在代码区。

调用时编译器会隐式传入一个参数：

```
this 指针
```

所以本质调用是：

```
square(&obj)
```

这就是为什么多个对象可以共用函数代码。

## 如果类只有成员函数没有成员变量，那么对象占用多少内存？

对象大小是类生成信息的大小

**修正：**

对象大小是 **1 字节**（通常）。

原因：

C++ 要保证不同对象有不同地址。
 即使没有成员变量，也会分配 1 字节。



## 构造函数能否是 virtual？为什么？

不能virtual，因为virtual的前提是已经有对象了，这个时候函数已经构造好了

## 析构函数为什么通常要写成 virtual？

析构函数是用于销毁对象的，所以要virtual

析构函数为什么通常要写成 virtual？

```c++
class Derived : public Base {
    int* data;
public:
    Derived() {
        data = new int[100];
    }

    ~Derived() {
        delete[] data;
    }
};
```

如果析构函数不执行：

- data 永远不会被释放
- 内存泄漏





# 注意细节

## 构造函数初始化列表

```c++
构造函数(...) : 成员1(参数), 成员2(参数) {}
```

在进入到构造函数体之前就已经将成员变量初始化了

## 常成员函数

```c++
int square() const {
    return chang * kuan;
}
```

限制 this 指针为 const 类型。承诺不会修改成员变量。

