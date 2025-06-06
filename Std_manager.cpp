#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef struct 
{
	string name;
	string id;
	string cource;
	int grade;
}Info;

void DisplayMenu()
{
	cout << "==========================" << endl;
	cout << "��ӭʹ��ѧ���ɼ�����ϵͳ" << endl;
	cout << "==========================" << endl;
	cout << "��ѡ�������" << endl;
	cout << "1.��¼ѧ���ɼ�" << endl;
	cout << "2.��ѯѧ���ɼ�" << endl;
	cout << "3.ͳ�ƿγ̳ɼ�" << endl;
	cout << "4.�˳�ϵͳ" << endl;
}

vector<Info>Std_Infos;

bool id_duplication(const string& id)
{
	for (auto& record : Std_Infos)
	{
		if (record.id == id)
		{
			return true;
		}
	}
	return false;
}

//��¼ѧ���ɼ�
void record_std_grade()
{
	Info newgrade;
	cout << "====��¼ѧ���ɼ�====" << endl;
	cout << "������ѧ������:";
	cin >> newgrade.name;
	cout << "������ѧ��ѧ�ţ�";
	cin >> newgrade.id;
	if (id_duplication(newgrade.id))
	{
		cout << "���󣬸�ѧ���Ѵ��ڣ�" << endl;
		return;
	}
	cout << "������γ����ƣ�";
	cin >> newgrade.cource;
	cout << "������ɼ���0-100����";
	cin >> newgrade.grade;
	if (newgrade.grade < 0 || newgrade.grade > 100)
	{
		cout << "������󣬳ɼ�ӦΪ0-100��" << endl;
		return;
	}
	Std_Infos.push_back(newgrade);
	cout << "�ɼ��ѳɹ���¼��" << endl;
}

//��ѯѧ���ɼ�
void check_std_grade()
{
	cout << "====��ѯѧ���ɼ�====" << endl;
	cout << "��ѡ���ѯ��ʽ" << endl;
	cout << "1.��ѧ��������ѯ" << endl;
	cout << "2.��ѧ��ѧ�Ų�ѯ" << endl;
	cout << "3.���γ����Ʋ�ѯ" << endl;
	
	int choice;
	string information;
	cout << "������ѡ����ţ�";
	cin >> choice;
	
	bool found = false;
	switch (choice)
	{
	case 1:
		cout << "������ѧ��������";
		cin >> information;
		break;
	case 2:
		cout << "������ѧ��ѧ�ţ�";
		cin >> information;
		break;
	case 3:
		cout << "���γ����Ʋ�ѯ��";
		cin >> information;
		break;
	}
	for (auto& record : Std_Infos)
	{
		if ((choice == 1 && record.name == information) || (choice == 2 && record.id == information) || (choice == 3 && record.cource == information))
		{
			cout << "������" << record.name << "��ѧ�ţ�" << record.id << "���γ̣�" << record.cource << "���ɼ���" << record.grade << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "δ�ҵ�ƥ��ļ�¼��" << endl;
	}
}

//��ͳ�ƿγ̳ɼ�
void statistics_source_grade()
{
	cout << "====ͳ�ƿγ̳ɼ�=====" << endl;
	cout << "������γ����ƣ�";
	string course_Name;
	cin >> course_Name;
	int count = 0;
	double total = 0;
	double max_score = 0;
	double min_score = 100;
	for (auto& record : Std_Infos)
	{
		if (record.cource == course_Name)
		{
			total += record.grade;
			count++;
			if (record.grade > max_score)
			{
				max_score = record.grade;
			}
			if (record.grade < min_score)
			{
				min_score = record.grade;
			}
		}
	}
	if (count == 0)
	{
		cout << "δ�ҵ��ÿγ�" << endl;
		return;
	}
	cout << "�γ̣�" << course_Name << endl;
	cout << "ƽ���֣�" << total / count << endl;
	cout << "��߷֣�" << max_score << endl;
	cout << "��ͷ֣�" << min_score << endl;
}

int main()
{
	int choice;
	do
	{
		DisplayMenu();
		cout << "������ѡ����ţ�";
		cin >> choice;
		switch (choice)
		{
		case 1:
			record_std_grade();
			break;
		case 2:
			check_std_grade();
			break;
		case 3:
			statistics_source_grade();
			break;
		case 4:
			cout << "��лʹ��ѧ���ɼ�����ϵͳ���ټ���" << endl;
			break;
		}
	} while (choice != 4);

	return 0; 
}