#include<iostream>
#include<string>
#include<filesystem>

namespace fs = std::filesystem;

class basefile {
    fs::path p;
    public:
    virtual bool fileexit();
    std::string abspath();
    virtual void testbasefile();
    void testfunction2();
};

bool basefile::fileexit() {
        if(fs::exists(p))
            return true;
        else
            return false;
    }
std::string basefile::abspath() {
    return fs::absolute(p);
}
void basefile::testbasefile() {
    std::cout << "this is basefile" << std::endl;
}
void basefile::testfunction2(){
    std::cout <<"this is testfunction in base obj" << std::endl;
}

class txtfile : basefile {
    public:
    virtual void testbasefile();
    void testfunction2();
};
void txtfile::testbasefile() {
        std::cout << "this is txtfile" << std::endl;
    }
void txtfile::testfunction2() {
        std::cout <<"this is testfunction in txtfile" << std::endl;
    }
class vediofile : basefile {
    public:
    virtual void testbasefile();
    //void testfunction2();
};
/*void vediofile::testbasefile(){
	std::cout << "this is vedio file testbase"<<std::endl;
}*/
int main(){
    basefile bf;
    txtfile tf;
    tf.testbasefile();
    tf.testfunction2();
    vediofile vf;
    vf.testbasefile();
    //vf.testfunction2();
    return 0;
}
