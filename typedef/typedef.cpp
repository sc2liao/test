#include<iostream>

//void show(const &int[]



int main(){
	typedef int arrT[10];
	using arrT1 = int[5];
	int ori[15] {0};
	for(int i = 0; i<10;i++){
		std::cout << ori[i]<<std::endl;
	}
	
	return 0;
}
