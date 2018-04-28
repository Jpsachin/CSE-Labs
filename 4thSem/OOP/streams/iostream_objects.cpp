// https://stackoverflow.com/questions/10071760/why-cant-we-create-our-own-ostream-object

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ostream c(cout.rdbuf());
    c<<"OSTREAM";
    

    string ss;
    istream cp(cin.rdbuf()); 
    cp>>ss;   
    c<<ss;
}