#include <iostream>

// Interface for Shape
class Shape {
public:
    virtual double calculateArea() const = 0;
};

// Rectangle class, implements Shape
class Rectangle : public Shape {
protected:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }

    // Getter methods
    double getLength() const { return length; }
    double getWidth() const { return width; }
};

// Box class, inherits from Rectangle
class Box : public Rectangle {
protected:
    double height;
public:
    Box(double l, double w, double h) : Rectangle(l, w), height(h) {}

    double calculateVolume() const {
        return length * width * height;
    }

    // Getter method
    double getHeight() const { return height; }
};

int main() {
    // Rectangle example
    Rectangle rectangle(5, 5);
    std::cout << "Superclass Persegi Panjang" << std::endl;
    std::cout << "Panjang: " << rectangle.getLength() << std::endl;
    std::cout << "Lebar: " << rectangle.getWidth() << std::endl;
    std::cout << "Luas: " << rectangle.calculateArea() << std::endl;

    // Box example
    Box box(4, 3, 5);
    std::cout << "\nSubclass Balok" << std::endl;
    std::cout << "Panjang: " << box.getLength() << std::endl;
    std::cout << "Lebar: " << box.getWidth() << std::endl;
    std::cout << "Tinggi: " << box.getHeight() << std::endl;
    std::cout << "Volume: " << box.calculateVolume() << std::endl;

    return 0;
}
