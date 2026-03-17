[toc]

# 类和对象

## 封装

- 属性和行为作为一个整体
- 属性和行为加以权限控制

```c++
const double PI = 3.14;

class circle {
public:
	
	double calculate() {
		return 2 * PI * r;
	}
	int r;
	int total;
};
int main() {
	circle c1;
	c1.r = 10;

	cout << "" << c1.calculate() << endl;
	system("pause");
	return 0;
}
```



作业：学生类，可以给学生的姓名和学号赋值，显示学生的姓名和学号；

```c++
class student {
public:
	//构造函数

	//姓名学号
	void setName(string name) {
		m_name = name;
	}

	void setID(int id) {
		ID = id;
	}

	void display() {
		cout << "name:" << m_name << "ID:" << ID << endl;
	}
private:
	string m_name;
	int ID = 1;
};


int main() {
	circle c1;
	c1.r = 10;
	cout << "" << c1.calculate() << endl;


	student s1;
	s1.setName("Gdy");
	s1.setID(1);
	s1.display();
	system("pause");
	return 0;
}
```

## 访问权限

1. 公告权限public
2. 保护权限protect 可以继承
3. 私有权限private 不可以继承

```c++
class person
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_PassWord;
public:
	void func() {
		m_Name = "gdy";
		m_Car = "benchi";
		m_PassWord = 1;
	}
};

int main() {
	person p1;
	p1.m_Name = "lisa";
	p1.func();
	system("pause");
	return 0;
}
```

### class 与struct的区别

struct 默认为公共权限

class  默认为私有权限

### 成员属性设置为私有

对于写权限可以检测数据的有效性

```c++
class person
{
public:
	void setName(string name) {
		m_Name = name;
	}

	string getName() {
		return m_Name;
	}

	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "请输入正确的年纪" << endl;
			return;
		}
		else {
			m_Age = age;
		}
	}

	int getAge() {
		return m_Age;
	}

	void setIdol(string idol) {
		m_Idol = idol;
	}

	string getIdol() {
		return m_Idol;
	}

private:
	string m_Name;//wtrite read

	int m_Age;//read

	string m_Idol;//write
};

int main() {
	person p1;
	p1.setName("高德源");
	p1.setAge(151);
	p1.setIdol("黄琳雨");
	cout << "他的年龄是：" << p1.getAge() << endl;
	cout << "他的名字是:" << p1.getName() << endl;
	cout << "他的偶像是：" << p1.getIdol() << endl;
	system("pause");
	return 0;
}
```

