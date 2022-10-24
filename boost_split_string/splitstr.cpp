#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <vector>
#include <iostream>
int main()
{
	auto test = std::string("0~1080");
	std::vector<std::string> rsv;
	boost::split( rsv, test, boost::is_any_of("~"));
	for( std::vector<std::string>::iterator it = rsv.begin(); it != rsv.end(); ++ it )
    std::cout << *it << std::endl;
	return 0;
}
