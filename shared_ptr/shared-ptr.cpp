#include<memory>
#include <string>
#include <iostream>
int main(){
	std::shared_ptr<std::string> sp1= std::make_shared<std::string>("this is test shared_ptr");
	std::cout << *sp1;
	//copy sp 
	auto sp2 = sp1;
	std::cout << "here is " << sp2.use_count() << std::endl;
	std::cout << "the sp1 is equal to sp2: " << (sp2 == sp1) ? "true" : "false" << std::endl;
	return 0;
}
