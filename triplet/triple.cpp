#include<iostream>
#include<vector>
#include<algorithm>
int arithmeticTriplets(std::vector<int>& nums, int diff) {
        int total = 0;
        for(int i = nums.size() - 1; i >= 2; i--){
            std::vector<int>::iterator it;
            int begin = nums[i];
            bool hastriple = true;
            for(int j = 0; j < 2; j++){
                it =std::find(nums.begin(), nums.end(), begin -= diff);
                std::cout << "begin is "<< begin << std::endl;
				std::cout << "it is end" << (it == nums.end()) << std::endl;
                if(it == nums.end()){
                    hastriple = false;
                    break;
                }
            }
            if(hastriple)
                total++;
        }
        return total;
}

int main(){
	std::vector<int> testnum = {4,7,10};
	std::cout << arithmeticTriplets(testnum, 3);
	return 0;
}