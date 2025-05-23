#include <iostream>
using namespace std;

// Abstract class with pure virtual function
class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      
      // Pure virtual function makes this an abstract class
      virtual int area() = 0;
      
      // Regular virtual function
      virtual void display() {
         cout << "Shape dimensions - Width: " << width << ", Height: " << height << endl;
      }
};

class Rectangle: public Shape {
   public:
      Rectangle(int a = 0, int b = 0): Shape(a, b) { }
      
      // Must implement pure virtual function
      int area() override {
         cout << "Rectangle class area: " << width * height << endl;
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      Triangle(int a = 0, int b = 0): Shape(a, b) { }
      
      // Must implement pure virtual function
      int area() override {
         cout << "Triangle class area: " << (width * height)/2 << endl;
         return (width * height / 2);
      }
      
      // Override regular virtual function
      void display() override {
         cout << "Triangle dimensions - Base: " << width << ", Height: " << height << endl;
      }
};

class Circle: public Shape {
   public:
      Circle(int r = 0): Shape(r, 0) { }
      
      // Must implement pure virtual function
      int area() override {
         cout << "Circle class area: " << 3.14 * width * width << endl;
         return (3.14 * width * width);
      }
      
      // Override regular virtual function
      void display() override {
         cout << "Circle dimensions - Radius: " << width << endl;
      }
};

int main() {
   // Shape shape;  // Error: cannot instantiate abstract class
   
   Rectangle rec(10, 5);
   Triangle tri(10, 5);
   Circle cir(7);
   
   // Array of pointers to Shape
   Shape *shapes[3] = {&rec, &tri, &cir};
   
   for(int i = 0; i < 3; i++) {
      shapes[i]->display();
      shapes[i]->area();
      cout << endl;
   }

   return 0;
}