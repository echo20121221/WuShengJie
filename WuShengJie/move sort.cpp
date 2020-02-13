#include<iostream>
using namespace std;

class a_1
{
	int *mptr;
public:
	a_1() :mptr(new int(0))
	{

	}
	a_1(a_1&&a_2):mptr(a_2.mptr)
	{
		a_2.mptr = nullptr;
	}	
	~a_1()
	{
		delete mptr;
	}
};
a_1 getmptr(bool flag)
{
	a_1 a;
	a_1 b;
	if (flag)
		return a;
	else
		return b;
}
int main()
{
	a_1 a_2 = getmptr(false);
	return 0;
}