#include<iostream>
#include<string>
#include<filesystem>
namespace fs = std::filesystem;
class basefile {
	fs::path p;
	pubilc:
	bool fileexit() {
		if(fs::exists(p))
			return true;
		else
			return false;
	}
	std::string abspath() {
		return fs::absolute(p);	
	}
	std::
};

class txtfile : basefile {
	
};
class vediofile : basefile {
}
int main(){
	
}
