#include "Domain.h"

//constructor for electric auto
Domain::Elektroauto::Elektroauto(string brand, string model, int year_of_registration, float price, float loading_time,
                                 float range) {
    this->id = count;
    this->brand = brand;
    this->model = model;
    this->year_of_registration = year_of_registration;
    this->kilometer = 0;
    this->price = price;
    this->loading_time = loading_time;
    this->range = range;
    count++;
}

//setters and getters
int Domain::Elektroauto::getId() const {
    return this->id;
}

string Domain::Elektroauto::getBrand() const {
    return this->brand;
}

void Domain::Elektroauto::setBrand(string brand) {
    this->brand = brand;
}

string Domain::Elektroauto::getModel() const {
    return this->model;
}

void Domain::Elektroauto::setModel(string model) {
    this->model = model;
}

int Domain::Elektroauto::getYearOfRegistration() const {
    return this->year_of_registration;
}

void Domain::Elektroauto::setYearOfRegistration(int yearOfRegistration) {
    this->year_of_registration = yearOfRegistration;
}

float Domain::Elektroauto::getKilometer() const {
    return this->kilometer;
}

void Domain::Elektroauto::setKilometer(float kilometer) {
    this->kilometer = kilometer;
}

float Domain::Elektroauto::getPrice() const {
    return this->price;
}

void Domain::Elektroauto::setPrice(float price) {
    this->price = price;
}

float Domain::Elektroauto::getLoadingTime() const {
    return this->loading_time;
}

void Domain::Elektroauto::setLoadingTime(float loadingTime) {
    this->loading_time = loadingTime;
}

float Domain::Elektroauto::getRange() const {
    return this->range;
}

void Domain::Elektroauto::setRange(float range) {
    this->range = range;
}

void Domain::Elektroauto::print_car() {
    cout << "(" << "Id:"<<this->id<<" Brand:" << this->brand << ", Model:" << this->model << ", Year of Registration:"
         << this->year_of_registration << ", Kilometer:" << this->kilometer << ", Price:" << this->price
         << ", Loading time:" << this->loading_time << ", Range:" << this->range << ")" << endl;
}

