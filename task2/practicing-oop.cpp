#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {
        cout << "Point default constructor called." << endl;
    }

    Point(int m) : x(m), y(m) {
        cout << "Point one-parameter constructor called." << endl;
    }

    Point(int a, int b) : x(a), y(b) {
        cout << "Point two-parameter constructor called." << endl;
    }

    ~Point() {
        cout << "Point destructor called." << endl;
    }

    void operator()(int a, int b) {
        x = a;
        y = b;
    }

    void print() const {
        cout << "Point Data: x = " << x << ", y = " << y << endl;
    }

    void setX(int m) { x = m; }
    void setY(int n) { y = n; }
    void setXY(int m, int n) { x = m; y = n; }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Line {
private:
    Point start;
    Point end;

public:
    Line() : start(), end() {
        cout << "Line default constructor called." << endl;
    }

    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {
        cout << "Line four-parameter constructor called." << endl;
    }

    Line(const Point& p1, const Point& p2) : start(p1), end(p2) {
        cout << "Line two-point constructor called." << endl;
    }

    ~Line() {
        cout << "Line destructor called." << endl;
    }

    void print() const {
        cout << "Start: ";
        start.print();
        cout << "End: ";
        end.print();
    }
};

class Circle {
private:
    Point center;
    int radius;

public:
    Circle() : center(0), radius(0) {
        cout << "Circle default constructor called." << endl;
    }

    Circle(int x, int y, int r) : center(x, y), radius(r) {
        cout << "Circle three-parameter constructor called." << endl;
    }

    ~Circle() {
        cout << "Circle destructor called." << endl;
    }

    void print() const {
        cout << "Center: ";
        center.print();
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle {
private:
    Point upperLeft;
    Point lowerRight;

public:
    Rectangle() : upperLeft(), lowerRight() {
        cout << "Rectangle default constructor called." << endl;
    }

    Rectangle(int x1, int y1, int x2, int y2) : upperLeft(x1, y1), lowerRight(x2, y2) {
        cout << "Rectangle four-parameter constructor called." << endl;
    }

    Rectangle(const Point& p1, const Point& p2) : upperLeft(p1), lowerRight(p2) {
        cout << "Rectangle two-point constructor called." << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor called." << endl;
    }

    void print() const {
        cout << "Upper Left: ";
        upperLeft.print();
        cout << "Lower Right: ";
        lowerRight.print();
    }
};

class Picture {
private:
    int circleCount;
    int rectangleCount;
    int lineCount;
    Circle* circles;
    Rectangle* rectangles;
    Line* lines;

public:
    Picture() : circleCount(0), rectangleCount(0), lineCount(0), circles(nullptr), rectangles(nullptr), lines(nullptr) {}

    Picture(int cn, int rn, int ln, Circle* c, Rectangle* r, Line* l)
        : circleCount(cn), rectangleCount(rn), lineCount(ln), circles(c), rectangles(r), lines(l) {}

    void setCircles(int count, Circle* c) {
        circleCount = count;
        circles = c;
    }

    void setRectangles(int count, Rectangle* r) {
        rectangleCount = count;
        rectangles = r;
    }

    void setLines(int count, Line* l) {
        lineCount = count;
        lines = l;
    }

    void print() const {
        for (int i = 0; i < circleCount; i++) {
            circles[i].print();
        }
        for (int i = 0; i < rectangleCount; i++) {
            rectangles[i].print();
        }
        for (int i = 0; i < lineCount; i++) {
            lines[i].print();
        }
    }
};

int main() {
    Point p1(12, 20);
    p1.print();
    p1(-5, 132);
    p1.print();

    Circle c1(250, 150, 100);
    Rectangle r1(10, 100, 90, 350);
    Line l1(30, 100, 350, 400);

    c1.print();
    r1.print();
    l1.print();

    Picture myPicture;

    Circle circleArray[3] = { Circle(50, 50, 50), Circle(200, 100, 100), Circle(420, 50, 30) };
    Rectangle rectArray[2] = { Rectangle(30, 40, 170, 100), Rectangle(Point(420, 50), Point(500, 300)) };
    Line* lineArray = new Line[2] { Line(Point(420, 50), Point(300, 300)), Line(40, 500, 500, 400) };

    myPicture.setCircles(3, circleArray);
    myPicture.setRectangles(2, rectArray);
    myPicture.setLines(2, lineArray);

    myPicture.print();

    delete[] lineArray;

    return 0;
}