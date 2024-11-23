#include <iostream>
#include <mutex>
#include <thread>

class Singleton
{
private:
// Prevent any other ways of creation
Singleton(const Singleton &);
Singleton& operator=(const Singleton &);
Singleton(std::string& name_) : name(name_)
{
    
}
// Note : this mutex object has to be "static" as well
static std::mutex mt;

static Singleton* pInstance;

public:
std::string name;
static Singleton* GetInstance(std::string name_)
{
    // Double check lock, locks are expensive, this is the way to avoid locks 
    // for the calls after creation.
    if (!pInstance) 
    {
        std::lock_guard<std::mutex> lock(mt);
        if(!pInstance)
        {
            pInstance = new Singleton(name_);
        }
    return pInstance;
    }
}

};

void threadT1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(999));
    auto x = Singleton::GetInstance("FOO");
    std::cout << x->name;
}

void threadT2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto x = Singleton::GetInstance("BAR");
    std::cout << x->name;
}


//This is important, static members need to be initialized.
// Note that these members are private, but can be initialized using the scope operator
// as these are static. i.e they do not need reference to "this" 
// To initialize them
//1. Use scope operator
//2. do not use static specifier during initialization 

Singleton* Singleton::pInstance = nullptr;
std::mutex Singleton::mt;
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro\n";
    std::thread t1(threadT1);
    std::thread t2(threadT2);

    t1.join();
    t2.join();
    

    return 0;
}
