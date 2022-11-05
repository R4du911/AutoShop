#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace Domain{
    class Elektroauto{
    private:
        static int count;
        int id;
        string brand;
        string model;
        int year_of_registration;
        float kilometer;
        float price;
        float loading_time;
        float range;

    public:

        //constructor for electric auto
        Elektroauto(string brand, string model, int year_of_registration, float price, float loading_time, float range);

        //setters and getters
        int getId() const;

        string getBrand() const;

        void setBrand(string brand);

        string getModel() const;

        void setModel(string model);

        int getYearOfRegistration() const;

        void setYearOfRegistration(int yearOfRegistration);

        float getKilometer() const;

        void setKilometer(float kilometer);

        float getPrice() const;

        void setPrice(float price);

        float getLoadingTime() const;

        void setLoadingTime(float loadingTime);

        float getRange() const;

        void setRange(float range);

        //print a car
        void print_car();
    };
}