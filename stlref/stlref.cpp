#include<vector>
#include<iostream>
inline void printvec(std::vector<int> v1){
	for(const auto v : v1){
		std::cout<<"print v is" << v <<std::endl;
	}
}
inline void addvec(std::vector<int> v1){
	for(auto v : v1){
		v++;
	}
}
int main(){
	std::vector<int> v1 = {1,2,3,4,5};
	for(auto v : v1){
		v++;
		std::cout<<"v is" << v <<std::endl;
	}
	for(auto &v : v1){
		std::cout<<"ori v is" << v <<std::endl;
		v++;
		std::cout<<"after v is" << v <<std::endl;
	}
	/*for(const auto v : v1){
		std::cout<<"const ori v is" << v <<std::endl;
		//v++;
		std::cout<<"const after v is" << v <<std::endl;
	}
	for(const auto &v : v1){
		std::cout<<"const ref ori v is" << v <<std::endl;
		//v++;
		std::cout<<"const ref after v is" << v <<std::endl;
	}*/
	/*for(const auto &&v : v1){
		std::cout<<"&& ori v is" << v <<std::endl;
		//v++;
		std::cout<<"&& after v is" << v <<std::endl;
	}*/
	addvec(v1);
	printvec(v1);

	return 0;
}