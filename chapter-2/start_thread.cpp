
#include <iostream>
#include <thread>

class background_task
{
public:
    void operator()() const
    {
        do_something();
        do_something_else();
    }

private:
    void do_something() const
    {
        std::cout << "do something " << std::endl;
    }
    void do_something_else() const
    {
        std::cout << "do something else " << std::endl;
    }
};

int main()
{
	//background_task bt;	
    // 所提供的函数对象被复制（copied）到新线程的存储器中 
    //std::thread t(bt);
    std::thread t{background_task()}; 	// 与传入函数的方式一样  
    t.join();
    return 0;
}

