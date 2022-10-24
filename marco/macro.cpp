#include<iostream>


void testmarco();
int main()
{
	#define test 1
	//const int test = 1;
	testmarco();
	return 0;
}
void testmarco()
{
    std::cout<<test;
}
