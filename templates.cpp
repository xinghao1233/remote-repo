#include <iostream>
#include <bitset>
using namespace std;
void print()
{

}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
    cout << sizeof...(args) << endl;
    print(args...);
}
int main(){
    print(7.5, "hello",bitset<16>(377),42);
}

template<typename... Types>
void print(const Types&... args)
{
    cout << count << endl;
}