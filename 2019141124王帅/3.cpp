#include <iostream>

using namespace std;

class Shape
{
public:
    Shape(int height = 0, int width = 0): height_(height), width_(width) {}

    virtual int Area() = 0;

protected:
    int height_, width_;
};

int Shape::Area()
{
    return height_ * width_;
}

class Rectangle: public Shape
{
public:
    Rectangle(int height = 0, int width = 0): Shape(height, width) {}
    int Area() override
    {
        return height_ * width_;
    }

};

class Triangle: public Shape
{
public:
    Triangle(int height = 0, int width = 0): Shape(height, width) {}
    int Area() override
    {
        return height_ * width_ / 2;
    }

};

int main(void)
{

    return 0;
}
