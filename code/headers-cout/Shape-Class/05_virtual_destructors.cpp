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
      
      // Virtual destructor
      virtual ~Shape() {
         cout << "Shape destructor called" << endl;
      }
      
      virtual int area() = 0;
};

class Rectangle: public Shape {
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
};

class Triangle: public Shape {
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
};

int main() {
   cout << "Creating a Rectangle object:" << endl;
   Shape *shape1 = new Rectangle(10, 5);
   cout << "Area: " << shape1->area() << endl;
   
   cout << "\nCreating a Triangle object:" << endl;
   Shape *shape2 = new Triangle(10, 5);
   cout << "Area: " << shape2->area() << endl;
   
   cout << "\nDeleting objects:" << endl;
   delete shape1;  // Calls both Rectangle and Shape destructors due to virtual destructor
   delete shape2;  // Calls both Triangle and Shape destructors due to virtual destructor
   
   return 0;
}