#include <iostream>
using namespace std;

class Shape {
   private:
      int id;
   
   protected:
      int width, height;
   
   public:
      Shape(int a = 0, int b = 0, int i = 0) {
         width = a;
         height = b;
         id = i;
      }
      
      int getId() { return id; }
      
      void display() {
         cout << "ID: " << id << ", Width: " << width << ", Height: " << height << endl;
      }
};

// Public inheritance
class Rectangle: public Shape {
   public:
      Rectangle(int a = 0, int b = 0, int i = 0): Shape(a, b, i) { }
      
      void accessDemo() {
         // Can access protected members
         cout << "Protected members width: " << width << ", height: " << height << endl;
         
         // Cannot access private members directly
         // cout << "Private member id: " << id << endl; // This would cause error
         
         // Can access public members
         cout << "Public method getId(): " << getId() << endl;
      }
};

// Protected inheritance
class Circle: protected Shape {
   public:
      Circle(int r = 0, int i = 0): Shape(r, r, i) { }
      
      void accessDemo() {
         // Can access protected members
         cout << "Protected members width: " << width << ", height: " << height << endl;
         
         // Can access public members (now protected in Circle)
         cout << "Protected method getId(): " << getId() << endl;
      }
      
      // Need to provide public methods to access inherited public methods
      void displayCircle() {
         display();
      }
};

// Private inheritance
class Square: private Shape {
   public:
      Square(int a = 0, int i = 0): Shape(a, a, i) { }
      
      void accessDemo() {
         // Can access protected members (now private in Square)
         cout << "Private members width: " << width << ", height: " << height << endl;
         
         // Can access public members (now private in Square)
         cout << "Private method getId(): " << getId() << endl;
      }
      
      // Need to provide public methods to access inherited methods
      void displaySquare() {
         display();
      }
};

int main() {
   Rectangle rect(5, 7, 1);
   Circle circle(5, 2);
   Square square(5, 3);
   
   cout << "Rectangle:" << endl;
   rect.display();  // Public method from Shape is accessible
   rect.accessDemo();
   
   cout << "\nCircle:" << endl;
   // circle.display();  // Error: protected inheritance makes public methods protected
   circle.displayCircle();  // Need to use wrapper method
   circle.accessDemo();
   
   cout << "\nSquare:" << endl;
   // square.display();  // Error: private inheritance makes public methods private
   square.displaySquare();  // Need to use wrapper method
   square.accessDemo();
   
   return 0;
}