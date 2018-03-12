// https://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function
// A class is abstract if it has at least one pure virtual function.

#include<iostream>
using namespace std;


class Shape {

    protected:
        int dim;

    public:
        Shape(int dim) {
            this->dim = dim;
        }

        virtual void calArea() = 0;

};

class Circle: public Shape {

    float area;

    public:

        Circle(int dim) : Shape(dim) {}

        void calArea() {
            this->area = 3.14*dim*dim;
            cout<<"Circle:::: Radius:"<<dim<<" Area:"<<area<<endl;
        }
};

class Square: public Shape {

    int area;

    public:

        Square(int dim) : Shape(dim) {}

        void calArea() {
            this->area = dim*dim;
            cout<<"Square:::: Side:"<<dim<<" Area:"<<area<<endl;
        }
};



int main() {

    Circle c(3);
    Square s(6);

    c.calArea();

    s.calArea();


  return 0;
}
