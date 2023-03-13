/*
    In this example code, we have two classes Point and Vector, both of which overload the + operator. 
    The Point class represents a point on a 2D plane, while the Vector class represents a vector with 
    a starting point and an ending point.

    In the Point class, the + operator is overloaded to add two Point objects together, resulting in a 
    new Point object whose x and y values are the sum of the corresponding values of the two Point objects.

    In the Vector class, the + operator is overloaded to add two Vector objects together, resulting in a 
    new Vector object whose starting point is the sum of the starting points of the two Vector objects, 
    and whose ending point is the sum of the ending points of the two Vector objects.

    In the main function, we create two Point objects p1 and p2, and two Vector objects v1 and v2, and add 
    them together using the + operator. We then display the resulting Vector object v3 and Point object p3 
    using their display member function.
*/

#include <iostream>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        /* Init value */
        Point() { x = 0; y = 0; }
        Point(int _x, int _y) { this->x = _x; this->y = _y;  }
        
        /* Kendi tipinde parametre alan operator function */
        Point operator+(const Point& p) {
            Point sum;
            sum.x = this->x + p.x;
            sum.y = this->y + p.y;
            return sum;
        }
    
        void display() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
        
};

class Vector {
    private:
        /* Point sınıfı tipinde oluşturulan start ve end değişkenleri */
        Point start, end;
    public:
        /* Init value */
        Vector() { start = Point(); end = Point(); }
        Vector(Point start, Point end) { this->start = start; this->end = end; }
        
        /* Vector sınıfının operator function */
        Vector operator+(const Vector& v) {
            Vector sum;
            sum.start = this->start + v.start;
            sum.end = this->end + v.end;
            return sum;
        }
        
        void display() {
            cout << "Start point: ";
            start.display();
            cout << "End point: ";
            end.display();
        }
};

int main() {
    Point p1(2, 3), p2(4, 5);
    
    Vector v1(p1, p2), v2(p2, p1);
    
    Vector v3 = v1 + v2; // operator+ overloaded for Vector class
    v3.display();
    
    Point p3 = p1 + p2; // operator+ overloaded for Point class
    p3.display();
    
    return 0;
}