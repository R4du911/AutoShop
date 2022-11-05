#pragma once
#include "Domain.h"
#include "CRUDRepository.h"
#include <vector>
#include <algorithm>
#include <numeric>

namespace Repository{

    //general class for InMemo
    class ElectricInMemoRepo : public CrudRepository{
    private:
        vector<Domain::Elektroauto> cars;
        vector<Domain::Elektroauto> fav_cars;

    public:

        //constructor
        ElectricInMemoRepo();

        //getter for array of cars
        vector<Domain::Elektroauto> get_cars();

        vector<Domain::Elektroauto> get_fav_cars();

        //add a car to the array
        void add_car_manager(string brand, string model, int year_of_registration, float price, float loading_time, float range) ;

        //remove a car from the array
        void delete_car_manager(int id);

        //modify a car from the array
        void modify_car_manager(int id, float kilometer, float price, float loading_time, float range);

        //add a car to favourites
        void add_car_client(int id, string kunde) ;

        //delete a car from favourites
        void delete_car_client(int id, string kunde);

        void read_manager();

        void read_client(string kunde);

    };
}
