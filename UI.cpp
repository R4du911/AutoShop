#include "UI.h"
#include <fstream>

UI::ElectricUI::ElectricUI(shared_ptr<Controller::ElectricController> &ctrl) : ctrl(ctrl) {}

Controller::ElectricController UI::ElectricUI::get_ctrl() {
    return *this->ctrl;
}

void UI::ElectricUI::Manger_Menu() {
    cout << "======Manager-Menu======" << endl;
    cout << "- Press 1 to add a car" << endl;
    cout << "- Press 2 to remove a car" << endl;
    cout << "- Press 3 to modify a car" << endl;
    cout << "- Press 4 to search by brand" << endl;
    cout << "- Press 5 to search by model" << endl;
    cout << "- Press 6 to search by kilometer" << endl;
    cout << "- Press 7 to search by age" << endl;
    cout << "- Press 8 to sort by price" << endl;
    cout << "- Press 0 to return to Main-Menu" << endl;

    cout << endl;
    cout << "Option:";

    int option;
    cin >> option;

    vector<Domain::Elektroauto> cars = {};
    int id;
    string brand, model;
    int year_of_registration;
    float kilometer, price, loading_time, range;

    switch (option) {
        case 1:
            cout << "Brand:";
            cin >> brand;
            cout << "Model:";
            cin >> model;
            cout << "Year of registration:";
            cin >> year_of_registration;
            cout << "Price";
            cin >> price;
            cout << "Charging time:";
            cin >> loading_time;
            cout << "Range:";
            cin >> range;
            try {
                this->get_ctrl().add_car_manager(brand, model, year_of_registration, price, loading_time, range);
            }
            catch (exception &) {
                cout << "Wrong input data\n\n";
            }
            Manger_Menu();
        case 2:
            cout << "Id:";
            cin >> id;
            try {
                this->get_ctrl().delete_car_manager(id);
            }
            catch (exception &) {
                cout << "Wrong input data\n\n";
            }
            Manger_Menu();
        case 3:
            cout<<"Id:";
            cin>>id;
            cout << "Kilometer:";
            cin >> kilometer;
            cout << "Price:";
            cin >> price;
            cout << "Charging time:";
            cin >> loading_time;
            cout << "Range:";
            cin >> range;
            try {
                this->get_ctrl().modify_car_manager(id, kilometer, price, loading_time, range);
            }
            catch (exception &) {
                cout << "Wrong input data\n\n";
            }
            Manger_Menu();
        case 4:
            cout << "Brand:";
            cin >> brand;
            cars = this->get_ctrl().filter_brand_model(1, brand);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Manger_Menu();
        case 5:
            cout << "Model:";
            cin >> model;
            cars = this->get_ctrl().filter_brand_model(2, model);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Manger_Menu();
        case 6:
            cout << "Kilometer:";
            cin >> kilometer;
            cars = this->get_ctrl().filter_by_kilometer(kilometer);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Manger_Menu();
        case 7:
            cout << "Year of registration:";
            cin >> year_of_registration;
            cars = this->get_ctrl().filter_by_age(year_of_registration);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Manger_Menu();
        case 8:
            cars = this->get_ctrl().sort_by_price();
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Manger_Menu();
    }


}

void UI::ElectricUI::Kunde_Menu(string kunde) {
    cout << "======Kunde-Menu======" << endl;
    cout << "- Press 1 to add a car to favourites" << endl;
    cout << "- Press 2 to remove a car from favourites" << endl;
    cout << "- Press 3 to search by brand" << endl;
    cout << "- Press 4 to search by model" << endl;
    cout << "- Press 5 to search by kilometer" << endl;
    cout << "- Press 6 to search by age" << endl;
    cout << "- Press 7 to sort by price" << endl;
    cout << "- Press 8 to print list of favourites" << endl;
    cout << "- Press 0 to return to Main-Menu" << endl;

    cout << endl;
    cout << "Option:";

    int option;
    cin >> option;

    vector<Domain::Elektroauto> cars = {};
    int id;
    string brand, model;
    int year_of_registration;
    float kilometer, price, loading_time, range;

    switch (option) {
        case 1:
            cout << "Id:";
            cin >> id;
            try {
                this->get_ctrl().add_car_client(id,kunde);
            }
            catch (exception &) {
                cout << "Wrong input data\n\n";
            }
            Kunde_Menu(kunde);
        case 2:
            cout <<"Id:";
            cin>>id;
            try {
                this->get_ctrl().delete_car_client(id, kunde);
            }
            catch (exception &) {
                cout << "Wrong input data\n\n";
            }
            Kunde_Menu(kunde);
        case 3:
            cout << "Brand:";
            cin >> brand;
            cars = this->get_ctrl().filter_brand_model(1, brand);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Kunde_Menu(kunde);
        case 4:
            cout << "Model:";
            cin >> model;
            cars = this->get_ctrl().filter_brand_model(2, model);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Kunde_Menu(kunde);
        case 5:
            cout << "Kilometer:";
            cin >> kilometer;
            cars = this->get_ctrl().filter_by_kilometer(kilometer);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Kunde_Menu(kunde);
        case 6:
            cout << "Year of registration:";
            cin >> year_of_registration;
            cars = this->get_ctrl().filter_by_age(year_of_registration);
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Kunde_Menu(kunde);
        case 7:
            cars = this->get_ctrl().sort_by_price();
            for (Domain::Elektroauto car: cars)
                car.print_car();
            Kunde_Menu(kunde);
        case 8:
            cout<<kunde<<"'s Favourite list:"<<endl;

            for (Domain::Elektroauto car: this->get_ctrl().get_fav_cars())
                car.print_car();

            cout<<endl;
            Kunde_Menu(kunde);
    }
}