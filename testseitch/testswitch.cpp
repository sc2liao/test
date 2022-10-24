#include<iostream>

int main()
{
	int count=0;
	while(true)
	{
		count++;
		std::cout<<count<<std::endl;
		switch(count)
		{
			case 1:
				continue;
				std::cout<<"this is 1";
			case 2:
				break;
				std::cout<<"this is 2";
			case 10:
				break;
			case 100:
				return 0;
		}

	}
	return 0;
}
