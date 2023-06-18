#include<iostream>


#pragma pack(push, 1)
struct s1 {
	uint32_t format:8;
	uint32_t len:24;
};

struct s2{
	uint8_t format;
	uint32_t len:24;

};

#pragma pack(pop)

int main(){
	struct s1
	std::cout << "sizeof s1 is "<<sizeof(struct s1);
	std::cout << "sizeof s2 is "<<sizeof(struct s2);
	return 0;
}