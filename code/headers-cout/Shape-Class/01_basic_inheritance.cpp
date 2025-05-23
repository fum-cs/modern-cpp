#include <iostream>
using namespace std;

// Base class
class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      
      void display() {
         cout << "Width: " << width << ", Height: " << height << endl;
      }
};

// Derived class
class Rectangle: public Shape {
   public:
      Rectangle(int a = 0, int b = 0): Shape(a, b) { }
      
      int area() {
         return (width * height);
      }
};

// Another derived class
class Triangle: public Shape {
   public:
      Triangle(int a = 0, int b = 0): Shape(a, b) { }
      
      int area() {
         return (width * height / 2);
      }
};

int main() {
   Rectangle rect(5, 7);
   Triangle tri(5, 7);
   
   // Access base class method
   cout << "Rectangle dimensions:" << endl;
   rect.display();
   cout << "Rectangle area: " << rect.area() << endl;
   
   cout << "\nTriangle dimensions:" << endl;
   tri.display();
   cout << "Triangle area: " << tri.area() << endl;
   
   return 0;
}