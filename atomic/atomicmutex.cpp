// g++ std-atomic2.cpp -o a.out -std=c++11 -pthread
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

long cnt = 0;
std::mutex mtx;

void counter()
{
    for (int i = 0; i < 100000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        //std::cout << std::this_thread::get_id() << ": " << cnt << '\n';
        //mtx.lock();
        cnt += 1;
        //mtx.unlock();
    }
}

int main(int argc, char* argv[])
{
    auto t1 = std::chrono::high_resolution_clock::now();
    std::thread threads[100];
    for (int i = 0; i != 100; i++)
    {
        threads[i] = std::thread(counter);
    }
    for (auto &th : threads)
        th.join();

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = t2 - t1;
    std::cout << "result: " << cnt << std::endl;
    std::cout << "duration: " << elapsed.count() << " ms" << std::endl;
    return 0;
}
