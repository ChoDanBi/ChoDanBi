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
	char _name1[8] = "홍길동";
	StudentScore stu1{ _name1,1,2,3 };

	char _name2[8] = "임꺽정";
	StudentScore stu2{ _name2,10,20,30 };

	char _name3[8] = "이몽룡";
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
		cout << "국어점수 : " << (*iter)->Kor << endl;
		cout << "영어점수 : " << (*iter)->Eng << endl;
		cout << "수학점수 : " << (*iter)->Math << endl;
	}

	return 0;
}