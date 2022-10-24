#include <stdlib.h>
#include <string>
#include <iostream>
 
#include <boost/filesystem.hpp>
namespace BFS = boost::filesystem;

int main()
{
	std::cout<<"current path is "<<BFS::current_path();
	return 0;
}
