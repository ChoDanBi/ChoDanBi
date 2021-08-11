#include <iostream>

using namespace std;

class Object
{
private:
	string Key;
public:
	void Initialize() { Key = "Player"; }
	void Output() { cout << Key << endl; }
public:
	Object() {}
	~Object() {}
};

int main(void)
{



	return 0;
}