#include<iostream>
#include<string>
using std::string;

class Vehicle
{
protected:
    string menufacturer;
    int year;
    string color;

public:
    string getMenufacturer(){
        return menufacturer;
    }

    void setMenufacturer(string value)
    {
        menufacturer = value;
    }

    int getYear()
    {
        return year;
    }

    void setYear(int value){
        year = value;
    }

    string getColor(){
        return this->color;
    }

    void setColor(string value)
    {
        this->color = value;
    }

    Vehicle()
    {
        std::cout << "\nAn instance object has been derived from vehicle"<< std::endl;
    }

    Vehicle(string menufacturer, int year, string color): Vehicle()
    {
        std::cout << "\nAn instance object with full parameters has been derived from Vehicle"<< std::endl;
        this->menufacturer = menufacturer;
        this->year = year;
        this->color = color;
    }

    virtual void start()
    {
        std::cout << "Vehicle has been started." << std::endl;
    }

    virtual void stop()
    {
        std::cout << "Vehicle has been stopped." << std::endl;
    }

    virtual void drive()
    {
        std::cout << "Vehicle is being driven." << std::endl;
    }
    virtual string toString()
    {
        return menufacturer + " - " + std::to_string(year) + " - " + color; 
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
         std::cout << "\nAn instance object has been derived from Car"<< std::endl;
    }
    Car(string menufacturer, int year, string color)
        :Vehicle(menufacturer, year, color)
    {
         std::cout << "\nAn instance object with full paramaters has been derived from Car"<< std::endl;
    }
    void openSunroof()
    {
        std::cout << "Sunroof has been opened." << std::endl;
    }
    void drive() override
    {
        std::cout << "The car manufacturer by "<< this->menufacturer << " is being driven." <<std::endl;
    }
};

class Bus : public Vehicle{
public:
    Bus(string menufacturer, int year, string color)
    : Vehicle(menufacturer, year, color)
    {
        std::cout << "\nAn instance object with full parameters has been derived from Bus"<< std::endl;
    }
    void scheduling(){
        std::cout<< "Scheduled." << std::endl;
    }
    void drive() override
    {
        std::cout << "The bus manufacturer by "<< this->menufacturer << " is being driven." <<std::endl;
    }
};

class SchoolBus : public Bus
{
public:
    SchoolBus(string menufacturer, int year, string color)
    : Bus(menufacturer, year, color)
    {
        std::cout << "\nAn instance object with full parameters has been derived from SchoolBus"<< std::endl;
    }

    void getFare()
    {
        std::cout << "\ngetFare() has been called\n";
    }
    void drive() override
    {
        std::cout << "The SchoolBus manufacturer by "<< this->menufacturer << " is being driven." <<std::endl;
    }
};


int main(){
    Vehicle item2 = Vehicle("Skoda", 1995, "red");
    std::cout << item2.toString() <<std::endl;
    
    Car item1 = Car();
    item1.setMenufacturer("TOGG");
    item1.setYear(2023);
    item1.setColor("Red");
    std::cout<< item1.toString() <<std::endl;
    item1.openSunroof();

    Car item3 = Car("Prol", 2020, "white");
    std::cout<< item3.toString() <<std::endl;
    item3.openSunroof();

    Bus item4 = Bus("Anadolu Isuzu", 2016, "Black");
    std::cout<< item4.toString() <<std::endl;
    item4.scheduling();

    SchoolBus item5 = SchoolBus("Isuzu", 2015, "Yellow");
    std::cout << item5.toString() <<std::endl;
    item5.scheduling();
    item5.getFare();

    item1.drive();
    item3.drive();
    item4.drive();
    item5.drive();
      
    return 0;
}