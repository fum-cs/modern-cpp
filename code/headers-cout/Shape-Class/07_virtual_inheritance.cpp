#include <iostream>
using namespace std;

// Base class
class Shape {
   protected:
      int id;

   public:
      Shape(int i = 0) {
         id = i;
         cout << "Shape constructor called with id " << id << endl;
      }
      
      virtual ~Shape() {
         cout << "Shape destructor called with id " << id << endl;
      }
      
      void setId(int i) {
         id = i;
      }
      
      int getId() {
         return id;
      }
};

// First level derived classes with virtual inheritance
class TwoDimensional: virtual public Shape {
   protected:
      int width, height;

   public:
      TwoDimensional(int w = 0, int h = 0, int i = 0): Shape(i) {
         width = w;
         height = h;
         cout << "TwoDimensional constructor called" << endl;
      }
      
      ~TwoDimensional() {
         cout << "TwoDimensional destructor called" << endl;
      }
      
      virtual int area() = 0;
};

// Another first level derived class with virtual inheritance
class Colored: virtual public Shape {
   protected:
      string color;

   public:
      Colored(string c = "white", int i = 0): Shape(i) {
         color = c;
         cout << "Colored constructor called" << endl;
      }
      
      ~Colored() {
         cout << "Colored destructor called" << endl;
      }
      
      void setColor(string c) {
         color = c;
      }
      
      string getColor() {
         return color;
      }
};

// Multiple inheritance from virtual base classes
class Rectangle: public TwoDimensional, public Colored {
   public:
      Rectangle(int w = 0, int h = 0, string c = "white", int i = 0)
         : Shape(i), TwoDimensional(w, h), Colored(c) {
         cout << "Rectangle constructor called" << endl;
      }
      
      ~Rectangle() {
         cout << "Rectangle destructor called" << endl;
      }
      
      int area() override {
         return (width * height);
      }
      
      void display() {
         cout << "Rectangle ID: " << getId() << endl;
         cout << "Width: " << width << ", Height: " << height << endl;
         cout << "Color: " << color << endl;
         cout << "Area: " << area() << endl;
      }
};

int main() {
   cout << "Creating a Rectangle object:" << endl;
   Rectangle rect(10, 5, "blue", 1);
   
   cout << "\nRectangle details:" << endl;
   rect.display();
   
   cout << "\nChanging Rectangle properties:" << endl;
   rect.setId(100);
   rect.setColor("red");
   rect.display();
   
   return 0;
}