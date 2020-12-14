#include <iostream>
using namespace std;

class CCar 
{
private:
    bool onoff;
    int price;
    int speed;

public:
    CCar(int p) : onoff(false), price(p), speed(0) {}
    void printspeed() { cout << "current speed : " << speed << endl; }

    friend class CController;
};

class CController 
{
private:
    int price;

public:
    CController(int p) : price(p) {}
    void turnon(CCar& car) { car.onoff = true; }
    void turnoff(CCar& car) { car.onoff = false; }
    void speedchange(CCar& car, int v) { car.speed += v; }  
};

int main()
{
    CCar mycar(100);
    CController mycontroller(10);

    mycontroller.turnon(mycar);
    mycontroller.speedchange(mycar, 5);
    mycar.printspeed();
    mycontroller.turnoff(mycar);
    
    return 0;
}