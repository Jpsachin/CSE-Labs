#include<bits/stdc++.h>

using namespace std;

// Person class
class Person {

    string name;
    int age;
    
    public:
    
        Person() {

        }
    
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
        
        int getAge() {
            return this->age;
        }      
        
        string getName() {
            return this->name;
        }
        
        // operator > overloaded for comparing age
        bool operator>(Person p) {
            
            return (this->age > p.age)?1:0; 
        }
        
        // operator + overloaded for concatenating names
        string operator+(Person p) {
            
            string tmp;
            return tmp.append(this->name.append(p.name));
            
        }
        
        // int type casting operator overloaded to return age of a Person
        operator int(){
            return this->age;
        }

};




int main() {

    Person omkar("Omkar Prabhu", 19);
    Person dd("Dibyadarshan Hota", 32);
    
    cout <<(omkar > dd)<<endl;
    cout <<(omkar + dd)<<endl;
    cout <<int(omkar)<<endl;

    return 0;
}
