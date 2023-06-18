#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    int maximumValue(std::vector<std::string>& strs) {
        int max_num = 0;
        
        for(auto str : strs){
            bool hasalpha = false;
			std::cout << "str is " <<str<<std::endl;
            for(char c : str){
                //max_num = str.size();
				std::cout << "c is " <<c<<std::endl;
                if(std::isalpha(c))
					std::cout << "c is isalpha" <<std::endl;
                    max_num = std::max((size_t)max_num, str.size());
                    hasalpha = true;
                    max_num = str.size();
                    break;
            }
            if(!hasalpha)
                max_num = std::max(max_num, std::stoi(str));
        }
        return max_num;
    }
};

int main(){
	Solution s;
	std::vector<std::string> testdata = {"1","01","001","0001"};
	int ans = s.maximumValue(testdata);
	std::cout << "ans is " << ans;
}