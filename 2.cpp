#include <iostream>

using namespace std;

class Building
{
protected:
    int id;
    int layers;
    int rooms;
    double area;
};

class Tech_Building: public Building
{

};

class Dorm_Building: public Building
{
private:
    int population;
};

int main(void)
{

    return 0;
}
