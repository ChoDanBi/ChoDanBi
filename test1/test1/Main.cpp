#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct StudentScore
{
	char* Name;
	int Kor;
	int Eng;
	int Math;
};



int main(void)
{
	char _name1[8] = "ȫ�浿";
	StudentScore stu1{ _name1,1,2,3 };

	char _name2[8] = "�Ӳ���";
	StudentScore stu2{ _name2,10,20,30 };

	char _name3[8] = "�̸���";
	StudentScore stu3{ _name3,100,200,300 };

	//===================================
	list<StudentScore*> StudentScoreList;

	StudentScoreList.push_back(&stu1);
	StudentScoreList.push_back(&stu2);
	StudentScoreList.push_back(&stu3);

	for (list<StudentScore*>::iterator iter = StudentScoreList.begin();
		iter != StudentScoreList.end(); ++iter)
	{
		cout << (*iter)->Name << endl;
		cout << endl;
		cout << "�������� : " << (*iter)->Kor << endl;
		cout << "�������� : " << (*iter)->Eng << endl;
		cout << "�������� : " << (*iter)->Math << endl;
	}

	return 0;
}