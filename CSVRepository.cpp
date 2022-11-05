#include "CSVRepository.h"
#include <fstream>

Repository::ElectricCSVRepo::ElectricCSVRepo() {
    this->cars = {};
    this->fav_cars = {};
}

vector<Domain::Elektroauto> Repository::ElectricCSVRepo::get_cars() {
    return this->cars;
}

vector<Domain::Elektroauto> Repository::ElectricCSVRepo::get_fav_cars() {
    return this->fav_cars;
}

void Repository::ElectricCSVRepo::writeFavorites(const string &kunde) {
    ofstream client_file;
    client_file.open(kunde);
    client_file.clear();
    for (Domain::Elektroauto car: fav_cars)
        client_file << car.getBrand() << "," << car.getModel() << "," << car.getYearOfRegistration() << ","
                    << car.getPrice() << "," << car.getLoadingTime() << "," << car.getRange() << endl;
    client_file.close();
}

void Repository::ElectricCSVRepo::writeToFile() {
    ofstream manager_file;
    manager_file.open("manager.txt");
    manager_file.clear();
    for (Domain::Elektroauto car: cars)
        manager_file << car.getBrand() << "," << car.getModel() << "," << car.getYearOfRegistration() << ","
                     << car.getPrice() << "," << car.getLoadingTime() << "," << car.getRange() << endl;
    manager_file.close();
}

void Repository::ElectricCSVRepo::add_car_manager(string brand, string model, int year_of_registration, float price,
                                                  float loading_time, float range) {
    this->cars.emplace_back(Domain::Elektroauto(brand, model, year_of_registration, price, loading_time, range));
    writeToFile();
}

void Repository::ElectricCSVRepo::delete_car_manager(int id) {
    auto itr = std::remove_if(this->cars.begin(), this->cars.end(),
                              [id](Domain::Elektroauto car) {
                                  return car.getId() == id;
                              });

    this->cars.erase(itr);
    writeToFile();
}

void Repository::ElectricCSVRepo::modify_car_manager(int id, float kilometer,
                                                     float price, float loading_time, float range) {
    for (Domain::Elektroauto &car: this->cars) {
        if (car.getId() == id) {
            car.setKilometer(kilometer);
            car.setPrice(price);
            car.setLoadingTime(loading_time);
            car.setRange(range);
        }
    }
    writeToFile();
}

void Repository::ElectricCSVRepo::add_car_client(int id, string kunde) {
    string brand, model;
    int year_of_registration;
    float price, loading_time, range;
    for (Domain::Elektroauto car: this->get_cars())
        if (car.getId() == id) {
            brand = car.getBrand();
            model = car.getModel();
            year_of_registration = car.getYearOfRegistration();
            price = car.getPrice();
            loading_time = car.getLoadingTime();
            range = car.getRange();
        }
    this->fav_cars.emplace_back(Domain::Elektroauto(brand, model, year_of_registration, price, loading_time, range));
    writeFavorites(kunde);
}



void Repository::ElectricCSVRepo::delete_car_client(int id, string kunde) {
    auto itr = std::remove_if(this->fav_cars.begin(), this->fav_cars.end(),
                              [id](Domain::Elektroauto car) {
                                  return car.getId() == id;
                              });

    this->fav_cars.erase(itr);
    writeFavorites(kunde);
}

void Repository::ElectricCSVRepo::read_manager() {
    ifstream manager_file;
    string line;
    manager_file.open("manager.txt");
    while (getline(manager_file, line)) {
        vector<string> elements_of_car = {};
        size_t pos = 0;
        string token;
        while ((pos = line.find(',')) != std::string::npos) {
            token = line.substr(0, pos);
            elements_of_car.emplace_back(token);
            line.erase(0, pos + 1);
        }
        this->cars.emplace_back(Domain::Elektroauto(elements_of_car[0], elements_of_car[1], stoi(elements_of_car[2]),
                                                    stof(elements_of_car[3]), stof(elements_of_car[4]), stof(line)));
    }
    manager_file.close();
}

void Repository::ElectricCSVRepo::read_client(string kunde) {
    ifstream client_file;
    string line;
    client_file.open(kunde);
    while (getline(client_file, line)) {
        vector<string> elements_of_car = {};
        size_t pos = 0;
        string token;
        while ((pos = line.find(',')) != std::string::npos) {
            token = line.substr(0, pos);
            elements_of_car.emplace_back(token);
            line.erase(0, pos + 1);
        }
        this->fav_cars.emplace_back(Domain::Elektroauto(elements_of_car[0], elements_of_car[1], stoi(elements_of_car[2]),
                                                    stof(elements_of_car[3]), stof(elements_of_car[4]), stof(line)));
    }
    client_file.close();
}


