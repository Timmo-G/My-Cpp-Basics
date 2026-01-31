#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//struct person
struct person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};

//struct address book
struct address_Book {
	struct person personArray[MAX];
	int m_size = 0;
};

//show the menu
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、删除联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、查找联系人  *****" << endl;
	cout << "*****  4、修改联系人  *****" << endl;
	cout << "*****  5、清空联系人  *****" << endl;
	cout << "*****  6、添加联系人  *****" << endl;//over
	cout << "*****  0、退出通讯录  *****" << endl;//over
	cout << "***************************" << endl;
	system("pause");
}

//add
void addPerson(address_Book* abs) {
	//full?
	if (abs->m_size >= MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//add

		//name
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		//gender
		int sex = -1;
		cout << "请输入性别： " << endl;
		cout << "0——男" << endl;
		cout << "1——女" << endl;
		while (1) {
			cin >> sex;
			if (sex == 0 || sex == 1) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入出错,请重新输入： " << endl;
			}
		}
		
		//age
		int age = 0;
		cout << "请输入年龄： " << endl;
		while(1){
			cin >> age;
			if (age <= MAX) {
				abs->personArray[abs->m_size].m_Age = age;
				break;
			}
			else {
				cout << "你这个魔丸！重新输入：" << endl;

			}
		}
		
		//phone
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		
		//address
		string address;
		cout << "请输入住址： " << endl;
		cin >> address;

	}
}

//delete
void deldtePerson(address_Book* abs) {

}

//show
void showPerson(address_Book* abs) {

}


//find
void findPerson(address_Book* abs) {

}

//modify	
void modifyPerson(address_Book* abs) {

}

//empty
void emptyPerson(address_Book* abs) {

}

int main() {
	int select = 0;
	address_Book abs;

	while (1) {
		//call the menu
		showMenu();
		//choose
		cin >> select;
		switch (select) {
		case 1://delete
			deldtePerson(&abs);
			break;
		case 2://show
			break;
		case 3://find
			break;
		case 4://modify
			break;
		case 5://empty
			break;
		case 6://add
			addPerson(&abs);
			break;
		case 0://exit
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

