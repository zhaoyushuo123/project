#include<iostream>
#include<string>

using namespace std;

#define MAX 1000
#define PASSWD shuoshuo1zhi
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;

};
//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;

};

//1,添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;

		while (true)
		{
			//输入1或2可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;

		}
		//年龄
		cout << "请输入年龄：  " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;


		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		
		//住址
		cout << "请输入家庭地址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作

	}
}

void showPerson(Addressbooks* abs)
{
	cout << "姓名\t" << "电话\t" << "年龄\t" <<"性别\t"<<"地址\t"<< endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << abs->personArray[i].m_Name<<"\t"<< endl;
		cout << abs->personArray[i].m_Phone << "\t" << endl;
		cout << abs->personArray[i].m_Age << "\t" << endl;
		cout << abs->personArray[i].m_Sex << "\t" << endl;
		cout << abs->personArray[i].m_Addr << "\t" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void deletPerson(Addressbooks* abs)
{
	cout << "******************" << endl;
	cout << "请输入你的密码" << endl;
	cin >> PASSWD;

	cout << "请选择你想通过何种方式删除" << endl;
	cout << "1.按照名字删除" << endl;
	cout<<"2.按电话号删除"<<endl;
}
//封装菜单界面
void showMenu()
{

	cout << "请在中文全角半角模式下操作" << endl;
	cout << "**************************" << endl;
	cout << "*****  1,添加联系人  *****" << endl;
	cout << "*****  2,显示联系人  *****" << endl;
	cout << "*****  3,删除联系人  *****" << endl;
	cout << "*****  4,查找联系人  *****" << endl;
	cout << "*****  5,修改联系人  *****" << endl;
	cout << "*****  6,清空联系人  *****" << endl;
	cout << "*****  0,退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}



int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;


	int select = 0;//创建用户选择输入的变量

	while (true)
	{
		//调用菜单
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletPerson(&abs);
			break;
		case 4://查找联系人
			break;
		case 5://修改联系人
			break;
		case 6://清空联系人
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	
	system("pause");
	return 0;
}