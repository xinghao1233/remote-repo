#include <iostream>
#include <functional>
#include <string>
using namespace std;


template<typename T>
inline void hash_combine(size_t& seed, const T& val){
        seed ^= std::hash<T>()(val) + 0x9e3779b9
            +(seed<<6) + (seed>>2);
}

//  auxiliary generic function
template<typename T>
inline void hash_val(size_t& seed,
            const T& val){
    hash_combine(seed,val);
}


template <typename T, typename... Types>
inline void hash_val(size_t& seed,
            const T& val, const Types&... args){
    hash_combine(seed,val);
    hash_val(seed, args...);
}

//  auxiliary generic function
template <typename... Types>
inline size_t hash_val(const Types&... args){
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer
{
    public:
        string fname;
        string lname;
        int no;
        void setFname(string fname);
        void setLname(string lname);
        void setNo(int no);
        string getFname(void);
        string getLname(void);
        int getNo(void);
};
void Customer::setFname(string fname){
    this->fname = fname;
}
void Customer::setLname(string lname){
    this->lname = lname;
}
void Customer::setNo(int no){
    this->no = no;
}
string Customer::getFname(){
    return this->fname;
}
string Customer::getLname(){
    return this->lname;
}
int Customer::getNo(){
    return this->no;
}



class CustomerHash{
    public:
    size_t operator()(const Customer& c)const{
        return hash_val(c.fname, c.lname, c.no);
    }
};

int main(){
    Customer c;
    c.setFname("John");
    c.setLname("Doe");
    c.setNo(123);
    cout << c.getFname() << endl;
    cout << c.getLname() << endl;
    cout << c.getNo() << endl;
    CustomerHash ch;
    cout << ch.operator()(c) << endl;
    return 0;
}

