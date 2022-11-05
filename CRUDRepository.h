#pragma once

#include <string>
#include <vector>

using namespace std;

namespace Repository {
    class CrudRepository {
    public:

        virtual vector<Domain::Elektroauto> get_cars() = 0;

        virtual vector<Domain::Elektroauto> get_fav_cars() = 0;

        virtual void add_car_manager(string brand, string model, int year_of_registration, float price, float loading_time, float range) = 0;

        virtual void delete_car_manager(int id) = 0;

        virtual void modify_car_manager(int id, float kilometer, float price, float loading_time, float range) = 0;

        virtual void add_car_client(int id, string kunde) = 0;

        virtual void delete_car_client(int id, string kunde) = 0;

        virtual void read_manager() = 0;

        virtual void read_client(string kunde) = 0;

        virtual ~CrudRepository(){};
    };
}
