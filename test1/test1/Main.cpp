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

// ** 이름 셋팅
char* SetName();

// ** 생성
StudentScore* CreateStudent();

// ** 초기화
void Initialize(StudentScore* _pStudent);

// ** 리스트에 추가
void AddStudent(map<string, list<StudentScore*>>* _pStudentScoreList, string _strKey);

// ** 출력
void Output(map<string, list<StudentScore*>>* _pStudentScoreList);


// ** 메인
int main(void)
{
	//** <Key, Value>
	map<string, list<StudentScore*>> StudentScoreList;

	//[S 학교] : [S길동][S꺽정][S몽룡]
	//[G 학교] : [G길동][G꺽정][G몽룡]
	//[A 학교] : [A길동][A꺽정][A몽룡]

	list<StudentScore*> Temp;
	Temp.push_back(new StudentScore((char*)"S길동", 1, 2, 3));
	Temp.push_back(new StudentScore((char*)"S꺽정", 4, 5, 6));
	Temp.push_back(new StudentScore((char*)"S몽룡", 7, 8, 9));
	StudentScoreList["S 학교"] = Temp;
	Temp.clear();

	Temp.push_back(new StudentScore((char*)"G길동", 10, 20, 30));
	Temp.push_back(new StudentScore((char*)"G꺽정", 40, 50, 60));
	Temp.push_back(new StudentScore((char*)"G몽룡", 70, 80, 90));
	StudentScoreList["G 학교"] = Temp;
	Temp.clear();

	Temp.push_back(new StudentScore((char*)"A길동", 100, 200, 300));
	Temp.push_back(new StudentScore((char*)"A꺽정", 400, 500, 600));
	Temp.push_back(new StudentScore((char*)"A몽룡", 700, 800, 900));
	StudentScoreList["A 학교"] = Temp;

	// ** 출력
	Output(&StudentScoreList);

	return 0;
}


char* SetName()
{
	char Buffer[1024] = "";

	cout << "이름 입력 : ";	cin >> Buffer;

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

	cout << "국어 점수 입력 : "; cin >> _pStudent->Kor;
	cout << "영어 점수 입력 : "; cin >> _pStudent->Eng;
	cout << "수학 점수 입력 : "; cin >> _pStudent->Math;
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


// ** 숙제 : map 안의  list 내용을 출력
void Output(map<string, list<StudentScore*>>* _pStudentScoreList)
{
	for (map < string, list<StudentScore*>>::iterator iter = _pStudentScoreList->begin();
		iter != _pStudentScoreList->end(); ++iter)
	{
		for (list<StudentScore*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << "이름 : " << (*iter2).second->Name << endl;
			cout << "국어 점수 : " << (*iter2).second->Kor << endl;
			cout << "영어 점수 : " << (*iter2).second->Eng << endl;
			cout << "수학 점수 : " << (*iter2).second->Math << endl << endl;
		}
	}
}