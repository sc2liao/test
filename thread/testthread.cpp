#include <iostream>
#include <thread>
#include <fstream>

using std::cout; using std::ofstream;
using std::endl; using std::string;
void writefile()
{
    string filename("tmp.txt");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
    for(int i=0;i<2000000;i++)
    	file_out << "Some random text to append." << endl;
}
void print()
{
	for(int i=0;i<10;i++)
	{
		cout<<"i is " << i<<endl;
	}
}
int main()
{
	std::thread t1(writefile);
	cout << "t1 detach" << endl;
	print();
	t1.join();
	cout << "Done !" << endl;

	return EXIT_SUCCESS;
}
