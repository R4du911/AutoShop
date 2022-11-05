#include "Controller.h"

Controller::ElectricController::ElectricController(shared_ptr<Repository::CrudRepository> &repo) : repo(repo) {}

void Controller::ElectricController::add_car_manager(string brand, string model, int year_of_registration, float price, float loading_time, float range) {
    if (year_of_registration < 1900)
        throw exception();
    else {
            this->repo->add_car_manager(brand, model, year_of_registration, price, loading_time, range);
    }
}

void Controller::ElectricController::delete_car_manager(int id) {
    bool found = false;
    for(Domain::Elektroauto car : this->repo->get_cars())
        if(car.getId() == id)
            found = true;

    if(!found)
        throw exception();
    else{
        this->repo->delete_car_manager(id);
    }
}

void Controller::ElectricController::modify_car_manager(int id, float kilometer,
                                                        float price, float loading_time, float range) {
    bool found = false;
    for (Domain::Elektroauto car: this->repo->get_cars())
        if (car.getId() == id)
            found = true;

    if (!found)
        throw exception();
    else {
        this->repo->modify_car_manager(id, kilometer, price, loading_time,
                                                  range);
    }
}

vector<Domain::Elektroauto> Controller::ElectricController::filter_brand_model(int option, string filter_by) {
    vector<Domain::Elektroauto> filter_cars = {};

    if (option == 1) {
        for (Domain::Elektroauto car: this->repo->get_cars())
            if (car.getBrand() == filter_by)
                filter_cars.emplace_back(car);
    }

    if (option == 2) {
        for (Domain::Elektroauto car: this->repo->get_cars())
            if (car.getModel() == filter_by)
                filter_cars.emplace_back(car);
    }

    return filter_cars;
}

vector<Domain::Elektroauto> Controller::ElectricController::sort_by_price() {
    vector<Domain::Elektroauto> filter_cars = {};

    for (Domain::Elektroauto car: this->repo->get_cars())
        filter_cars.emplace_back(car);

    std::sort(filter_cars.begin(), filter_cars.end(),
              [](Domain::Elektroauto &car1, Domain::Elektroauto &car2) { return car1.getPrice() < car2.getPrice(); });


    return filter_cars;
}

vector<Domain::Elektroauto> Controller::ElectricController::filter_by_age(int year_of_registration) {
    vector<Domain::Elektroauto> filter_cars = {};

    for (Domain::Elektroauto car: this->repo->get_cars())
        if (car.getYearOfRegistration() == year_of_registration)
            filter_cars.emplace_back(car);

    return filter_cars;
}

vector<Domain::Elektroauto> Controller::ElectricController::filter_by_kilometer(float kilometer) {
    vector<Domain::Elektroauto> filter_cars = {};

    for (Domain::Elektroauto car: this->repo->get_cars())
        if (car.getKilometer() <= kilometer)
            filter_cars.emplace_back(car);

    return filter_cars;
}

void Controller::ElectricController::add_car_client(int id, string kunde) {
    bool found = false;

    for (Domain::Elektroauto car: this->repo->get_cars())
        if (car.getId() == id)
            found = true;

    if (!found)
        throw exception();
    else {
        this->repo->add_car_client(id,kunde);
    }
}

void Controller::ElectricController::delete_car_client(int id, string kunde) {
    bool found = false;

    for (Domain::Elektroauto car: this->repo->get_fav_cars())
        if (car.getId() == id)
            found = true;

    if (!found)
        throw exception();
    else {
        this->repo->delete_car_client(id, kunde);
    }
}

vector<Domain::Elektroauto> Controller::ElectricController::get_cars() {
    return this->repo->get_cars();
}

vector<Domain::Elektroauto> Controller::ElectricController::get_fav_cars() {
    return this->repo->get_fav_cars();
}
