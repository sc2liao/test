#include <iostream> 
using namespace std; 

int main() { 
    int x = 10;

    auto f = [&]() mutable -> void {
        int x = 20;
        cout << x << endl;
    };

    f(); // 顯示 20
    cout << x << endl; // 顯示 10

    return 0; 
}
