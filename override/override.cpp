#include<iostream>
using namespace std;
class CA
{
public:
CA()
{
  cout<<"constructer in CA"<<endl;
}
virtual void func1(int)
{
cout <<"func1 in CA"<< endl;
}
};
/*class CB : public CA
{
public:
void func1(int) const override
{
std::cout << “func1 in CB" << std::endl;
}
};*/
int main()
{
  cout <<"main"<<endl;
  CA *ca=new CA();
  ca->func1(1);
  return 0;
}
