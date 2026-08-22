#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s = ""; 
    const char* x = s.c_str();
    int z = strlen(x);
    std::cout << z;
    return 0;
}

    
