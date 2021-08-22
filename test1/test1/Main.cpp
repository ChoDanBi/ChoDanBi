#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;


struct StudentScore
{
	char* Name;
	int Kor;
	int Eng;
	int Math;

	StudentScore() : Kor(0), Eng(0), Math(0) {}

	StudentScore(char* _Name, int _Kor, int _Eng, int _Math)
		: Name(_Name), Kor(_Kor), Eng(_Eng), Math(_Math) { }
};

// ** �̸� ����
char* SetName();

// ** ����
StudentScore* CreateStudent();

// ** �ʱ�ȭ
void Initialize(StudentScore* _pStudent);

// ** ����Ʈ�� �߰�
void AddStudent(map<string, list<StudentScore*>>* _pStudentScoreList, string _strKey);

// ** ���
void Output(map<string, list<StudentScore*>>* _pStudentScoreList);


// ** ����
int main(void)
{
	//** <Key, Value>
	map<string, list<StudentScore*>> StudentScoreList;

	//[S �б�] : [S�浿][S����][S����]
	//[G �б�] : [G�浿][G����][G����]
	//[A �б�] : [A�浿][A����][A����]

	list<StudentScore*> Temp;
	Temp.push_back(new StudentScore((char*)"S�浿", 1, 2, 3));
	Temp.push_back(new StudentScore((char*)"S����", 4, 5, 6));
	Temp.push_back(new StudentScore((char*)"S����", 7, 8, 9));
	StudentScoreList["S �б�"] = Temp;
	Temp.clear();

	Temp.push_back(new StudentScore((char*)"G�浿", 10, 20, 30));
	Temp.push_back(new StudentScore((char*)"G����", 40, 50, 60));
	Temp.push_back(new StudentScore((char*)"G����", 70, 80, 90));
	StudentScoreList["G �б�"] = Temp;
	Temp.clear();

	Temp.push_back(new StudentScore((char*)"A�浿", 100, 200, 300));
	Temp.push_back(new StudentScore((char*)"A����", 400, 500, 600));
	Temp.push_back(new StudentScore((char*)"A����", 700, 800, 900));
	StudentScoreList["A �б�"] = Temp;


	// ** ���
	Output(&StudentScoreList);

	return 0;
}


char* SetName()
{
	char Buffer[1024] = "";

	cout << "�̸� �Է� : ";	cin >> Buffer;

	char* pName = new char[strlen(Buffer)];
	strcpy(pName, Buffer);

	return pName;
}

StudentScore* CreateStudent()
{
	StudentScore* pStudent = new StudentScore;

	Initialize(pStudent);

	return pStudent;
}

void Initialize(StudentScore* _pStudent)
{
	_pStudent->Name = SetName();

	cout << "���� ���� �Է� : "; cin >> _pStudent->Kor;
	cout << "���� ���� �Է� : "; cin >> _pStudent->Eng;
	cout << "���� ���� �Է� : "; cin >> _pStudent->Math;
}

void AddStudent(map<string, list<StudentScore*>>* _pStudentScoreList, string _strKey)
{
	map<string, list<StudentScore*>>::iterator iter = _pStudentScoreList->find(_strKey);

	if (iter == _pStudentScoreList->end())
	{
		list<StudentScore*> TempList;

		TempList.push_back(CreateStudent());

		_pStudentScoreList->insert(make_pair(_strKey, TempList));
	}
	else
	{
		iter->second.push_back(CreateStudent());
	}
}


// ** ���� : map ����  list ������ ���
void Output(map<string, list<StudentScore*>>* _pStudentScoreList)
{
	//	list<StudentScore*>::iterator iter = _pStudentScoreList;
	//map < string, list<StudentScore*>>::iterator iter = _pStudentScoreList->begin();
	for (map < string, list<StudentScore*>>::iterator iter = _pStudentScoreList->begin();
		iter != _pStudentScoreList->end(); ++iter)
	{
		cout << "�̸� : " << (*iter).second->Name << endl;
		cout << "���� ���� : " << (*iter).second->Kor << endl;
		cout << "���� ���� : " << (*iter).second->Eng << endl;
		cout << "���� ���� : " << (*iter).second->Math << endl << endl;
	}

}