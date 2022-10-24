#include<vector>
#include<iostream>

int bisearch(std::string text,char goal)
{
	auto beg = text.begin();
	auto end = text.end();
	auto mid = beg + (end - beg)/2;
	
	while(mid != end && *mid!=goal)
	{
		if(goal<*mid)
			end = mid;
		else
			beg = mid +1;
		mid = beg + (end - beg)/2;
	}
	return mid==end ? -1 :mid-text.begin();
}
int main(int argc,char *argv[])
{
	std::string temp="abcdefghijk";
	char undf = 't';
	char* undfptr = &undf;
	char** test = &undfptr;
	int result = bisearch(temp,*argv[1]);
	std::cout << "undf is " << test<<std::endl;
	std::cout << "test is " << *test<<std::endl;
	std::cout << "test is " << **test<<std::endl;
	std::cout << "argv[1] is " << argv[1]<<std::endl;
	std::cout << "argv[1] is " << *argv[1]<<std::endl;
	std::cout << "find in pos "<<result<<std::endl;
}
