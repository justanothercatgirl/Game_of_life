#include "GOL.hpp"
#include <thread>

#ifdef __RUN_EXAMPLE__
    #include <fstream>    
    #define __IDEV__ __INPUT__
#else //__RUN_EXAMPLE__
    #define __IDEV__ std::cin
#endif //__RUN_EXAMPLE__

int main()
{
#ifdef __RUN_EXAMPLE__

    std::ifstream __INPUT__("example.txt");
    if(!__INPUT__.is_open())
        __INPUT__ = std::ifstream("../../../example.txt");
    if(!__INPUT__.is_open())
        __INPUT__ = std::ifstream("D:/Programming/Git, cmake and linking/Game of life CA/example.txt");
    if(!__INPUT__.is_open())
    {
        std::cout << "COULDN'T OPEN AN EXAMPLE";
        std::cin.get();
        return 0;
    }
#else // __RUN_EXAMPLE__
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
#endif // __RUN_EXAMPLE__

    int h, w;
    std::cout << "enter height, width\n";
    __IDEV__ >> h >> w;

    setup:
    game* G = new game(h, w);
    G->print();
    std::cout << "\nenter amount of live cells\n";
    int amount; __IDEV__ >> amount;
    std::cout << "\nenter points\n";
    std::vector<point> points(amount);
    for(auto &x: points)
        __IDEV__ >> x.first >> x.second;
    // TODO: reimplement without try-catch block
    try
    {
        G->set_alive(points);
    }
    catch(std::out_of_range &e)
    {
        std::cout << "\npoint out of bounds!\n";
        delete G;
        goto setup;
    }
    std::cout << "\nsetup complete!\n";
    G->print();

#ifdef __RUN_EXAMPLE__
    std::cin.get();
#endif //__RUN_EXAMPLE__

    int i; 
    std::cout << "enter amont of iterations/n";
    
    for(__IDEV__ >> i; i; i--)
    {
        G->next_iteration();
        G->print();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    delete G;
    std::cin.get();
    return 0;
}



//following block is not used anywhere, just sort of "experiment"
#if defined WIN32 || _WIN64
#include <Windows.h>
void writech(const char* message, unsigned long len)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE) return;
    WriteConsoleA(h, message, len, &len, 0);
}
#endif //WIN32 || _WIN64
