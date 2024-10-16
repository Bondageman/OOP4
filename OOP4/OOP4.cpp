#include <iostream>
#include <fstream>
#include <cmath>
#include <Windows.h>

using namespace std;

class Circle {
protected:
    double radius; 
public:
    float PInumber = 3.1415;
    
    Circle(double r = 0) : radius(r) {}

    
    double getArea() const {
        return PInumber * radius * radius;
    }

    
    double getCircumference() const {
        return 2 * PInumber * radius;
    }

    void printInfo(ostream& out) const {
        out << "Circle:\n";
        out << "Radius: " << radius << "\n";
        out << "Area: " << getArea() << "\n";
        out << "Circumference: " << getCircumference() << "\n";
    }
};

class Rhombus {
protected:
    double diagonal1, diagonal2; 
public:
    Rhombus(double d1 = 0, double d2 = 0) : diagonal1(d1), diagonal2(d2) {}

    double getArea() const {
        return (diagonal1 * diagonal2) / 2;
    }

    void printInfo(ostream& out) const {
        out << "Rhombus:\n";
        out << "Diagonal 1: " << diagonal1 << "\n";
        out << "Diagonal 2: " << diagonal2 << "\n";
        out << "Area: " << getArea() << "\n";
    }
};

class CircleInRhombus : public Circle, public Rhombus {
public:
    CircleInRhombus(double r, double d1, double d2) : Circle(r), Rhombus(d1, d2) {}

    void printInfo(ostream& out) const {
        out << "Circle in Rhombus:\n";
        Circle::printInfo(out);
        Rhombus::printInfo(out);
    }
};

int main() {
    SetConsoleOutputCP(1251);

    double radius, d1, d2;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Enter the first diagonal of the rhombus: ";
    cin >> d1;
    cout << "Enter the second diagonal of the rhombus: ";
    cin >> d2;

    CircleInRhombus cirInRh(radius, d1, d2);

    cirInRh.printInfo(cout);

    ofstream outFile("JaZertva.txt");
    if (outFile.is_open()) {
        cirInRh.printInfo(outFile);
        outFile.close();
        cout << "Information saved to JaZertva.txt\n";
    }
    else {
        cout << "Error opening file!\n";
    }

    return 0;
}
