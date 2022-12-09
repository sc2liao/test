#include<filesystem>

#ifdef CXX17 // if this is C++17
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

int main(){
	fs::path testpath("/home/denny/test");
	if(!fs::exits(testpath))
		return 1;
	fs::
}
