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
	cout << "欢迎使用学生成绩管理系统" << endl;
	cout << "==========================" << endl;
	cout << "请选择操作：" << endl;
	cout << "1.记录学生成绩" << endl;
	cout << "2.查询学生成绩" << endl;
	cout << "3.统计课程成绩" << endl;
	cout << "4.退出系统" << endl;
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

//记录学生成绩
void record_std_grade()
{
	Info newgrade;
	cout << "====记录学生成绩====" << endl;
	cout << "请输入学生姓名:";
	cin >> newgrade.name;
	cout << "请输入学生学号：";
	cin >> newgrade.id;
	if (id_duplication(newgrade.id))
	{
		cout << "错误，该学号已存在！" << endl;
		return;
	}
	cout << "请输入课程名称：";
	cin >> newgrade.cource;
	cout << "请输入成绩（0-100）：";
	cin >> newgrade.grade;
	if (newgrade.grade < 0 || newgrade.grade > 100)
	{
		cout << "输入错误，成绩应为0-100！" << endl;
		return;
	}
	Std_Infos.push_back(newgrade);
	cout << "成绩已成功记录！" << endl;
}

//查询学生成绩
void check_std_grade()
{
	cout << "====查询学生成绩====" << endl;
	cout << "请选择查询方式" << endl;
	cout << "1.按学生姓名查询" << endl;
	cout << "2.按学生学号查询" << endl;
	cout << "3.按课程名称查询" << endl;
	
	int choice;
	string information;
	cout << "请输入选项序号：";
	cin >> choice;
	
	bool found = false;
	switch (choice)
	{
	case 1:
		cout << "请输入学生姓名：";
		cin >> information;
		break;
	case 2:
		cout << "请输入学生学号：";
		cin >> information;
		break;
	case 3:
		cout << "按课程名称查询：";
		cin >> information;
		break;
	}
	for (auto& record : Std_Infos)
	{
		if ((choice == 1 && record.name == information) || (choice == 2 && record.id == information) || (choice == 3 && record.cource == information))
		{
			cout << "姓名：" << record.name << "，学号：" << record.id << "，课程：" << record.cource << "，成绩：" << record.grade << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "未找到匹配的记录！" << endl;
	}
}

//查统计课程成绩
void statistics_source_grade()
{
	cout << "====统计课程成绩=====" << endl;
	cout << "请输入课程名称：";
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
		cout << "未找到该课程" << endl;
		return;
	}
	cout << "课程：" << course_Name << endl;
	cout << "平均分：" << total / count << endl;
	cout << "最高分：" << max_score << endl;
	cout << "最低分：" << min_score << endl;
}

int main()
{
	int choice;
	do
	{
		DisplayMenu();
		cout << "请输入选项序号：";
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
			cout << "感谢使用学生成绩管理系统，再见！" << endl;
			break;
		}
	} while (choice != 4);

	return 0; 
}