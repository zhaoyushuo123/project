#include<iostream>
#include<string>

using namespace std;

#define MAX 1000
#define PASSWD shuoshuo1zhi
//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;

};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;

};

//1,�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����!" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����1��2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;

		}
		//����
		cout << "���������䣺  " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;


		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		
		//סַ
		cout << "�������ͥ��ַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//��������

	}
}

void showPerson(Addressbooks* abs)
{
	cout << "����\t" << "�绰\t" << "����\t" <<"�Ա�\t"<<"��ַ\t"<< endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << abs->personArray[i].m_Name<<"\t"<< endl;
		cout << abs->personArray[i].m_Phone << "\t" << endl;
		cout << abs->personArray[i].m_Age << "\t" << endl;
		cout << abs->personArray[i].m_Sex << "\t" << endl;
		cout << abs->personArray[i].m_Addr << "\t" << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

void deletPerson(Addressbooks* abs)
{
	cout << "******************" << endl;
	cout << "�������������" << endl;
	cin >> PASSWD;

	cout << "��ѡ������ͨ�����ַ�ʽɾ��" << endl;
	cout << "1.��������ɾ��" << endl;
	cout<<"2.���绰��ɾ��"<<endl;
}
//��װ�˵�����
void showMenu()
{

	cout << "��������ȫ�ǰ��ģʽ�²���" << endl;
	cout << "**************************" << endl;
	cout << "*****  1,�����ϵ��  *****" << endl;
	cout << "*****  2,��ʾ��ϵ��  *****" << endl;
	cout << "*****  3,ɾ����ϵ��  *****" << endl;
	cout << "*****  4,������ϵ��  *****" << endl;
	cout << "*****  5,�޸���ϵ��  *****" << endl;
	cout << "*****  6,�����ϵ��  *****" << endl;
	cout << "*****  0,�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}



int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;


	int select = 0;//�����û�ѡ������ı���

	while (true)
	{
		//���ò˵�
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletPerson(&abs);
			break;
		case 4://������ϵ��
			break;
		case 5://�޸���ϵ��
			break;
		case 6://�����ϵ��
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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