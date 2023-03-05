#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
 
using namespace std;
 
class Point {
private:
    double x;
    double y;
 
public:
    Point() {
        x = 0;
        y = 0;
    }
 
    Point(double argx, double argy) {
        x = argx;
        y = argy;
    }
 
    double getX() const {
        return x;
    }
 
    double getY() const {
        return y;
    }
 
    void setX(double argx) {
        x = argx;
    }
 
    void setY(double y) {
        this->y = y;
    }
 
    Point operator-(const Point& point) const {
        Point result(abs(x - point.x), abs(y - point.y));
        return result;
    }
};
 
class Shape {
protected:
    Point mFirst;
    Point mSecond;
    string mName;
 
public:
    Shape() {
        mFirst = Point(0, 0);
        mSecond = Point(0, 0);
        mName = "Unknown";
    }
 
    Shape(Point argmFirst, Point argmSecond) {
        mFirst = argmFirst;
        mSecond = argmSecond;
    }
 
    Point getFirst() const {
        return mFirst;
    }
 
    Point getSecond() const {
        return mSecond;
    }
 
    string getName() const {
        return mName;
    }
 
    void setFirst(Point argmFirst) {
        mFirst = argmFirst;
    }
 
    void setSecond(Point argmSecond) {
        mSecond = argmSecond;
    }
 
    void setName(string argmName) {
        mName = argmName;
    }
 
    virtual double getPerimeter() const = 0;
 
    virtual double getArea() const = 0;
};
 
class Quadrilateral : public Shape {
public:
    Quadrilateral() : Shape() {}
 
    Quadrilateral(Point argmFirst, Point argmSecond, string argmName) : Shape(argmFirst, argmSecond) {
        mName = argmName;
    }
 
    double getLength() const {
        Point dimensiuni = mFirst - mSecond;
        return dimensiuni.getX();
    }
 
    double getWidth() const {
        Point dimensiuni = mFirst - mSecond;
        return dimensiuni.getY();
    }
 
    double getPerimeter() const {
        return 2 * getLength() + 2 * getWidth();
    }
 
    double getArea() const {
        return getLength() * getWidth();
    }
};
 
class Circle : public Shape {
private:
    double mRadius;
 
public:
    Circle() : Shape() {
        this->mRadius = 0;
    }
 
    Circle(Point argcenter, double argmRadius) : Shape(argcenter, Point()) {
        mRadius = argmRadius;
        mName = "cerc";
    }
 
    double getPerimeter() const {
        return 2 * M_PI * mRadius;
    }
 
    double getArea() const {
        return M_PI * mRadius * mRadius;
    }
 
    double getRadius() const {
        return mRadius;
    }
 
    void setRadius(double argmRadius) {
        mRadius = argmRadius;
    }
};
 
bool comparator(Shape* s1, Shape* s2)
{
    if (s1->getArea() == s2->getArea())
    {
        return s1->getPerimeter() < s2->getPerimeter();
    }
    else return s1->getArea() < s2->getArea();
}
int main() {
    int n;
    double min;
    double max;
    vector<Shape*> shapes;
 
    cin >> n >> min >> max;
    for (int i = 0; i < n; i++) {
        string nume;
        cin >> nume;
        if (nume == "cerc") {
            double x;
            double y;
            double raza;
            cin >> x >> y >> raza;
            shapes.push_back(new Circle(Point(x, y), raza));
        }
        else if (nume == "patrat" || nume == "dreptunghi") {
            double x1;
            double y1;
            double x2;
            double y2;
            cin >> x1 >> y1 >> x2 >> y2;
            shapes.push_back(new Quadrilateral(Point(x1, y1), Point(x2, y2), nume));
        }
    }
 
    sort(shapes.begin(), shapes.end(), comparator);
 
    for (Shape* shape : shapes) {
        printf("%s %.6lf %.6lf\n", shape->getName().c_str(), shape->getArea(), shape->getPerimeter());
    }
 
    return 0;
}