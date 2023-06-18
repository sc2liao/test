#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
using people = std::pair<std::string, int>;
bool inline decrase(const people &p1, const people &p2){
	if(p1.second > p2.second)
		return true;
	else if(p1.second == p2.second)
		return true;
	else
		return false;
}

bool inline increase(const people &p1, const people &p2){
	if(p1.second < p2.second)
		return true;
	else if(p1.second == p2.second)
		return true;
	else
		return false;
}

void inline printname(std::vector<people> per){
	for(auto it : per)
	std::cout << "name is :" <<it.first<<std::endl;
}

int main(){
	
	std::vector<people> pelples;
	pelples.push_back(std::make_pair("denny", 182));
	pelples.push_back(std::make_pair("liu", 166));
	pelples.push_back(std::make_pair("fufu", 100));
	printname(pelples);
	std::sort(pelples.begin(), pelples.end(), increase);
	printname(pelples);
	std::sort(pelples.begin(), pelples.end(), decrase);
	printname(pelples);
	std::sort(pelples.begin(), pelples.end(), [](const people &p1, const people &p2) {
		if(p1.second < p2.second)
		return true;
	else if(p1.second == p2.second)
		return true;
	else
		return false;
	} );
	printname(pelples);
}