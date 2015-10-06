//Testing passing of structs with pointers


#include <iostream>
using namespace std;

struct Test
{
	int *ptr1;
	int *ptr2;

	//Test(int x, int y);
	Test(int x, int y)
	{	
		cout << "reached constructor" << endl;
		ptr1 = new (nothrow) int(x);
		ptr2 = new (nothrow) int(x);
		cout << "creating struct with address " << this << ", " <<ptr1 << " and " << ptr2 << endl;
	};

	//Test(const int& x, const int& y) : *ptr1(x), *ptr2(y) {};

	~Test()
	{
		cout << "deleting struct with address " << this << ", " <<ptr1 << " and " << ptr2 << endl;

		delete ptr1;
		delete ptr2;
	};
};

/*Test::Test(int x, int y)
{	
	cout << "reached constructor" << endl;
	(*ptr1) = x;
	(*ptr2) = y;
	//cout << "creating struct with address " << this << ", " <<ptr1 << " and " << ptr2 << endl;
}*/

void increment(Test tester);

int main()
{
	Test first(3,4);

	//Test first();

	increment(first);

	return 0;
}

void increment(Test tester)
{
	(*(tester.ptr1))++;
	(*(tester.ptr2))++;

	cout << "modifying struct with address " << &tester << ", " << tester.ptr1 << " and " << tester.ptr2 << endl;
}