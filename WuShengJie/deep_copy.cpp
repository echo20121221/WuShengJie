#include<iostream>
#include<vector>
using namespace std;

class school
{
public:
	char* str;
	school(){
		str = new char[strlen(this->str) + 1];
	};
	school(char *str)
	{
		str = new char[strlen(this->str) + 1];
	}
	~school()
	{
		if (str)   delete[]   str;
	}
	
	
};

int main()
{
	school dl;
	dl.str = new char[32];
	strcpy(dl.str, "�人���ͣ�");
	school *p = new school();
	p->str = "лл";
	delete p;
	
	return 0;
}