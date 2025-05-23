#include <iostream>
using namespace std;

class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      
      // Virtual function
      virtual void display() {
         cout << "Shape with width: " << width << ", height: " << height << endl;
      }
      
      virtual int area() {
         cout << "Parent class area: 0" << endl;
         return 0;
      }
};

class Rectangle: public Shape {
   public:
      Rectangle(int a = 0, int b = 0): Shape(a, b) { }
      
      void display() override {
         cout << "Rectangle with width: " << width << ", height: " << height << endl;
      }
      
      int area() override {
         cout << "Rectangle class area: " << width * height << endl;
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      Triangle(int a = 0, int b = 0): Shape(a, b) { }
      
      void display() override {
         cout << "Triangle with width: " << width << ", height: " << height << endl;
      }
      
      int area() override {
         cout << "Triangle class area: " << (width * height)/2 << endl;
         return (width * height / 2);
      }
};

int main() {
   Shape *shape;
   Rectangle rec(10, 5);
   Triangle tri(10, 5);

   // Store the address of Rectangle
   shape = &rec;
   
   // Call Rectangle's display and area methods through Shape pointer
   shape->display();
   shape->area();

   // Store the address of Triangle
   shape = &tri;
   
   // Call Triangle's display and area methods through Shape pointer
   shape->display();
   shape->area();
   
   // Polymorphism with array of pointers
   cout << "\nPolymorphism with array of pointers:" << endl;
   Shape *shapes[2] = {&rec, &tri};
   
   for(int i = 0; i < 2; i++) {
      shapes[i]->display();
      shapes[i]->area();
   }

   return 0;
}