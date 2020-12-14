#include <iostream>
using namespace std;

class CCar;

class CController 
{
private:
    int price;

public:
    CController(int p) : price(p) {}
    void turnon(CCar& car);
    void turnoff(CCar& car);
    void speedchange(CCar& car, int v);

    // friend class CCar;
};

class CCar 
{
private:
    bool onoff;
    int price;
    int speed;

public:
    CCar(int p) : onoff(false), price(p), speed(0) {}
    void printspeed() { cout << "current speed : " << speed << endl; }

    // void setprice(CController &controller, int p) { controller.price = p; }

    friend class CController;
};

void CController::turnon(CCar &car)
{
    car.onoff = true;
}

void CController::turnoff(CCar &car)
{
    car.onoff = false;
}

void CController::speedchange(CCar &car, int v)
{
    car.speed += v;
}

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