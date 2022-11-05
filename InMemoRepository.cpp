#include "InMemoRepository.h"

Repository::ElectricInMemoRepo::ElectricInMemoRepo() {
    this->cars = {};
    this->fav_cars = {};
}

vector<Domain::Elektroauto> Repository::ElectricInMemoRepo::get_cars() {
    return this->cars;
}

vector<Domain::Elektroauto> Repository::ElectricInMemoRepo::get_fav_cars() {
    return this->fav_cars;
}

void Repository::ElectricInMemoRepo::add_car_manager(string brand, string model, int year_of_registration, float price, float loading_time, float range) {
    this->cars.emplace_back(Domain::Elektroauto(brand, model, year_of_registration, price, loading_time, range));
}

void Repository::ElectricInMemoRepo::delete_car_manager(int id) {
    auto itr = std::remove_if(this->cars.begin(), this->cars.end(),
                              [id](Domain::Elektroauto car) {
                                  return car.getId() == id;
                              });

    this->cars.erase(itr);
}

void Repository::ElectricInMemoRepo::modify_car_manager(int id, float kilometer, float price, float loading_time, float range) {
    for(Domain::Elektroauto &car : this->cars){
        if( car.getId() == id){
            car.setKilometer(kilometer);
            car.setPrice(price);
            car.setLoadingTime(loading_time);
            car.setRange(range);
        }
    }
}

void Repository::ElectricInMemoRepo::add_car_client(int id, string kunde) {
    string brand,model;
    int year_of_registration;
    float price,loading_time,range;
    for(Domain::Elektroauto car : this->get_cars())
        if(car.getId() == id){
            brand = car.getBrand();
            model = car.getModel();
            year_of_registration = car.getYearOfRegistration();
            price = car.getPrice();
            loading_time = car.getLoadingTime();
            range = car.getRange();
        }
    this->fav_cars.emplace_back(Domain::Elektroauto(brand, model, year_of_registration,price,loading_time,range));
}

void Repository::ElectricInMemoRepo::delete_car_client(int id, string kunde) {
    auto itr = std::remove_if(this->fav_cars.begin(), this->fav_cars.end(),
                              [id](Domain::Elektroauto car) {
                                  return car.getId() == id;
                              });

    this->fav_cars.erase(itr);
}

void Repository::ElectricInMemoRepo::read_manager() {

}

void Repository::ElectricInMemoRepo::read_client(string kunde) {

}
