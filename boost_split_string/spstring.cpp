#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace boost;

int main(int argc, char**argv) {
    std::string res;
    std::getline(cin, res);
    std::vector<std::string> details;
    boost::split(details, res, boost::is_any_of(","));
    // If I iterate through the vector there is only one element "John" and not all ?
    for (std::vector<std::string>::iterator pos = details.begin(); pos != details.end(); ++pos) {
        cout << *pos << endl;
    }

    return 0;
}
