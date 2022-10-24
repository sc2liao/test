#include <iostream>
using namespace std;

void CallByAddress_Plus(int* addr)
{
    (*addr)++;
	cout << "address in function at  CallByAddress_Plus:" << &addr << endl;
}
void CallByReference_Plus(int& ref)
{
    ref++;
	cout << "address in function at CallByReference_Plus:" << &ref << endl;
}

int main()
{
	int a = 100;
	int ref = 1000;

	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;

	CallByAddress_Plus(&a);
	CallByReference_Plus(ref);
	//cout << "After CallByAddress_Plus(b), b in the main: " << b << endl;
	//cout << "After CallByReference_Plus(c), c in the main: " << c << endl;
	cout << "After CallByAddress_Plus, address  in the main: " << &a << endl;
	cout << "After CallByReference_Plus, address  in the main: " << &ref << endl;

	//system("");
	return 0;
}
