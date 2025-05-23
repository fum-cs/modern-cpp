#include <iostream>
using namespace std;

class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
         cout << "Shape constructor called" << endl;
      }
      
      virtual ~Shape() {
         cout << "Shape destructor called" << endl;
      }
      
      virtual int area() = 0;
};

class Printable {
   public:
      Printable() {
         cout << "Printable constructor called" << endl;
      }
      
      virtual ~Printable() {
         cout << "Printable destructor called" << endl;
      }
      
      virtual void print() = 0;
};

// Multiple inheritance
class Rectangle: public Shape, public Printable {
   public:
      Rectangle(int a = 0, int b = 0): Shape(a, b) {
         cout << "Rectangle constructor called" << endl;
      }
      
      ~Rectangle() {
         cout << "Rectangle destructor called" << endl;
      }
      
      int area() override {
         return (width * height);
      }
      
      void print() override {
         cout << "Rectangle with width " << width << " and height " << height << endl;
         cout << "Area: " << area() << endl;
      }
};

// Multiple inheritance
class Triangle: public Shape, public Printable {
   public:
      Triangle(int a = 0, int b = 0): Shape(a, b) {
         cout << "Triangle constructor called" << endl;
      }
      
      ~Triangle() {
         cout << "Triangle destructor called" << endl;
      }
      
      int area() override {
         return (width * height / 2);
      }
      
      void print() override {
         cout << "Triangle with base " << width << " and height " << height << endl;
         cout << "Area: " << area() << endl;
      }
};

int main() {
   cout << "Creating a Rectangle object:" << endl;
   Rectangle rect(10, 5);
   
   cout << "\nCreating a Triangle object:" << endl;
   Triangle tri(10, 5);
   
   cout << "\nPrinting objects:" << endl;
   rect.print();
   cout << endl;
   tri.print();
   
   cout << "\nPolymorphism with Printable interface:" << endl;
   Printable *printables[2] = {&rect, &tri};
   for(int i = 0; i < 2; i++) {
      printables[i]->print();
      cout << endl;
   }
   
   return 0;
}