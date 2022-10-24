#include <boost/ref.hpp>  
#include <boost/thread/thread.hpp>  
    #include <string>  
    using namespace boost;  
      
    int g_num = 10;      //全域性變數，寫者改變該全域性變數，讀者讀該全域性變數  
    shared_mutex s_mu;   //全域性shared_mutex物件  
      
    //寫執行緒  
    void read_(std::string &str)  
    {  
        const char* c = str.c_str();  
        while (1)  
        {  
            {  
                shared_lock<shared_mutex> m(s_mu);    //讀鎖定，shared_lock  
                printf("執行緒%s進入臨界區，global_num = %d\n", c, g_num);  
                boost::this_thread::sleep(boost::posix_time::seconds(1));    //sleep 1秒，給足夠的時間看其他執行緒是否能進入臨界區  
                printf("執行緒%s離開臨界區...\n", c);  
            }  
            boost::this_thread::sleep(boost::posix_time::seconds(1));   //讀執行緒離開後再slpp 1秒（改變這個值可以看到不一樣的效果）  
        }  
    }  
      
    //讀執行緒  
    void writer_(std::string &str)  
    {  
        const char* c = str.c_str();  
        while (1)  
        {  
            {  
                unique_lock<shared_mutex> m(s_mu);    //寫鎖定，unique_lock  
                ++g_num;  
                printf("執行緒%s進入臨界區，global_num = %d\n", c, g_num);  
                boost::this_thread::sleep(boost::posix_time::seconds(1));    //sleep 1秒，讓其他執行緒有時間進入臨界區  
                printf("執行緒%s離開臨界區...\n", c);  
            }  
            boost::this_thread::sleep(boost::posix_time::seconds(2));   //寫執行緒離開後再slpp 2秒，這裡比讀執行緒多一秒是因為如果這裡也是1秒，那兩個寫執行緒一起請求鎖時會讓讀執行緒飢餓  
        }  
    }  
    int main()  
    {  
        std::string r1 = "read_1";  
        std::string r2 = "read_2";  
        std::string w1 = "writer_1";  
        std::string w2 = "writer_2";  
      
        boost::thread_group tg;  
        tg.create_thread(bind(read_, boost::ref(r1)));   //兩個讀者  
        tg.create_thread(bind(read_, boost::ref(r2)));  
      
        tg.create_thread(bind(writer_, boost::ref(w1)));  //兩個寫者  
        tg.create_thread(bind(writer_, boost::ref(w2)));  
        tg.join_all();  
      
        return 0;  
    }  
