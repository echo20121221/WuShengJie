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
	strcpy(dl.str, "Îäºº¼ÓÓÍ£¡");
	school *p = new school();
	p->str = "Ð»Ð»";
	delete p;
	
	return 0;
}