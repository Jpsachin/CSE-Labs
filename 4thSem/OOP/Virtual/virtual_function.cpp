#include<iostream>
using namespace std;


class Book {

    protected:
        int isbn;

    public:

        Book(int isbn) {
            this->isbn = isbn;
        }
        virtual void display() {

            cout<<"ISBN: "<<isbn;
        }

};

class Audio: public Book {

    string name;
    string author;

    public:

        Audio(int isbn, string name, string author) : Book(isbn) {
            this->name = name;
            this->author = author;
        }

        void display() {
            cout<<"Audio Book:::: Name:"<<name<<" Author:"<<author<<" ISBN:"<<isbn<<endl;
        }
};

class Paper: public Book {
    string name;
    string author;

    public:

        Paper(int isbn, string name, string author) : Book(isbn) {
            this->name = name;
            this->author = author;
        }

        void display() {
            cout<<"Paper Book:::: Name:"<<name<<" Author:"<<author<<" ISBN:"<<isbn<<endl;
        }


};



int main() {

    Book *ptr;
    
    Audio ab(123, "Omkar", "Omkar Prabhu");
    Paper pb(113, "Prabhu", "Omkar Prabhu");

    ptr = &ab;
    ab.display();

    ptr = &pb;
    pb.display();


  return 0;
}
