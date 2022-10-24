#include <iostream>
#include <mutex>
#include <thread>

int kData=0;

std::mutex kMutex;

namespace myspace{
	template<typename T> class my_lock_guard{
	public:
		my_lock_guard(T& mutex) :mutex_(mutex){
		mutex_.lock();
		}

		~my_lock_guard(){
		mutex_.unlock();
		}
	private:
		my_lock_guard(my_lock_guard const&)=delete;
		my_lock_guard& operator=(my_lock_guard const&)=delete;
		T& mutex_;
	};
};
void increment(){
	
	for(int i=0;i<1000;i++)
	{
	//myspace::my_lock_guard<std::mutex> lock(kMutex);
		std::cout <<std::this_thread::get_id()
				<<":"<<kData++<<std::endl;
	}
}
int main()
{
std::cout<<__FUNCTION__<<";"<<kData<<std::endl;
std::thread t1(increment);
std::thread t2(increment);

std::thread t3(increment);
t1.join();
t2.join();
t3.join();
std::cout<<"kData is "<<kData<<std::endl;
getchar();
return 0;
}
