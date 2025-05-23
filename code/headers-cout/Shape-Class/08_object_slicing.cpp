#include <iostream>
#include <vector>
using namespace std;

class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      
      virtual void display() const {
         cout << "Shape with width: " << width << ", height: " << height << endl;
      }
      
      virtual int area() const {
         return 0;
      }
};

class Rectangle: public Shape {
   public:
      Rectangle(int a = 0, int b = 0): Shape(a, b) { }
      
      void display() const override {
         cout << "Rectangle with width: " << width << ", height: " << height << endl;
      }
      
      int area() const override {
         return (width * height);
      }
};

class Triangle: public Shape {
   public:
      Triangle(int a = 0, int b = 0): Shape(a, b) { }
      
      void display() const override {
         cout << "Triangle with base: " << width << ", height: " << height << endl;
      }
      
      int area() const override {
         return (width * height / 2);
      }
};

// Function demonstrating object slicing
void demonstrateSlicing(Shape shape) {
   shape.display();  // Always calls Shape::display, not derived class version
   cout << "Area: " << shape.area() << endl;
}

// Function using reference to avoid slicing
void usingReference(const Shape& shape) {
   shape.display();  // Calls appropriate derived class version
   cout << "Area: " << shape.area() << endl;
}

int main() {
   Rectangle rect(10, 5);
   Triangle tri(10, 5);
   
   cout << "Original objects:" << endl;
   rect.display();
   cout << "Area: " << rect.area() << endl;
   tri.display();
   cout << "Area: " << tri.area() << endl;
   
   cout << "\nObject slicing when passing by value:" << endl;
   demonstrateSlicing(rect);  // Rectangle sliced to Shape
   demonstrateSlicing(tri);   // Triangle sliced to Shape
   
   cout << "\nNo slicing when passing by reference:" << endl;
   usingReference(rect);  // Calls Rectangle::display and Rectangle::area
   usingReference(tri);   // Calls Triangle::display and Triangle::area
   
   cout << "\nObject slicing in containers:" << endl;
   vector<Shape> shapes;
   shapes.push_back(rect);  // Rectangle sliced to Shape
   shapes.push_back(tri);   // Triangle sliced to Shape
   
   for(const auto& shape : shapes) {
      shape.display();  // Always calls Shape::display
      cout << "Area: " << shape.area() << endl;
   }
   
   cout << "\nNo slicing with pointers in containers:" << endl;
   vector<Shape*> shapePointers;
   shapePointers.push_back(&rect);
   shapePointers.push_back(&tri);
   
   for(const auto& shapePtr : shapePointers) {
      shapePtr->display();  // Calls appropriate derived class version
      cout << "Area: " << shapePtr->area() << endl;
   }
   
   return 0;
}