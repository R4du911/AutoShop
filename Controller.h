#pragma once
#include "InMemoRepository.h"
#include "CSVRepository.h"
#include <memory>

namespace Controller{

    //general class
    class ElectricController{
    private:
        shared_ptr<Repository::CrudRepository> repo;

    public:

        //constructor
        ElectricController(shared_ptr<Repository::CrudRepository> &repo);

        //getter for array of cars
        vector<Domain::Elektroauto> get_cars();

        vector<Domain::Elektroauto> get_fav_cars();

        //controller for adding a car
        void add_car_manager(string brand, string model, int year_of_registration, float price, float loading_time, float range);

        //controller for deleting a car
        void delete_car_manager(int id);

        //controller for modifying a car
        void modify_car_manager(int id, float kilometer, float price, float loading_time, float range);

        //add a car to favourites
        void add_car_client(int id, string kunde) ;

        //delete a car from favourites
        void delete_car_client(int id, string kunde);

        //filter cars by brand or by model
        virtual vector<Domain::Elektroauto> filter_brand_model(int option, string filter_by);

        //filter by year of registration
        virtual vector<Domain::Elektroauto> filter_by_age(int year_of_registration);

        //filter by kilometer
        virtual vector<Domain::Elektroauto> filter_by_kilometer(float kilometer);

        //sort by price
        virtual vector<Domain::Elektroauto> sort_by_price();
    };

}