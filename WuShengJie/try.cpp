#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	try{
		for (int i = 0; i < 6; i++)
		{
			cout << arr.at(i);
		}
		throw;
	}
	catch (out_of_range)
	{
		cout << "hh";
	}
	catch(...)
	{

	}
	
	return 0;
}