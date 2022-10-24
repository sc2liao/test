#include<iostream>

//void test(const std::int64_t);
void test(const std::int64_t &testsize)
{
    std::cout<<"test size is "<<testsize<<std::endl;
}
int main()
{
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
std::uint64_t x=10;
test(x);
test(-x);
return 0;
}
/*void test(const std::int64_t &testsize)
{
	std::cout<<"test size is "<<testsize<<std::endl;
}*/

