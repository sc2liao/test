#include<iostream>

const int& function1(const int& i1, const int& i2){
    return i1 >= i2 ? i1 : i2;
};

int function2(const int& i1, const int& i2){
    return i1 >= i2 ? i1 : i2;
};

const int function3(const int& i1, const int& i2){
    return i1 >= i2 ? i1 : i2;
};

// int& function4(const int& i1, const int& i2){
//     return i1 >= i2 ? i1 : i2;
// };
// can not transfer const int& to int &

int& tranfer(const int& i1){
    return const_cast<int&>(i1);
};

const int f2(int& i1){
    return i1;
};

// int& function4(const int& i1, const int& i2){
//     return i1 >= i2 ? i1 : i2;
// };

int main(){
	int t1 = 0;
	int *const pt1 = &t1;
	const int t2 = 1;
	
	const int *pl1 = &t2;
	const int &rl1 = t2; // const in reference types is always low-level

	const int *const ptl1 = pt1; //is top level and low level

	t1 = t2; // is ok 
	pl1 = ptl1;// ok: p2 has the same low-level const qualification as ptl1

	//int *p = pl1; // error: pl1 has a low-level const but p doesn’t
	pl1 = &t1; // ok: we can convert int* to const int*
	pl1 = &t2;
	int x = *pl1; // ok *pl1 is pointer to top level const t2

	//int &r1 = t2; // error: can’t bind an ordinary int& to a const int object
	const int &r2 = t1; // ok: can bind const int& to plain int
	int y = rl1; //ok rl1 is reference to t2

	const int z = 2;
	const int *pz = &z;
	const int **ppz = &pz;
	int k = 3;
	int *pk = &k;
	int **ppk = &pk;
	//int const **ppt4 = &pt3;
	int const **ppz2 = &pz;
	const int *const* ppz3 = &pz;
	const int ** const ppz4 = &pz;

	const int tran = 10;
	int after_tran = tranfer(tran);
	std::cout << tran << "addr is "<< &tran<<std::endl;
	std::cout << after_tran << "addr is "<< &after_tran<<std::endl;

	after_tran = 20;
	std::cout << tran << "addr is "<< &tran<<std::endl;
	std::cout << after_tran << "addr is "<< &after_tran<<std::endl;

	int const *g =0;
	g = &k;
	//*g = 50;

	//*ppx = pl1;
	//**ppt3 = 10;

	return 0;
}