#include <fstream>
#include "test.cppT"

int Domain::Elektroauto::count = 0;

int main() {

    //tests
    using namespace main_test;
    main_test::main();

    //create InMemory
    shared_ptr<Repository::CrudRepository> repo_InMemo = make_shared<Repository::ElectricInMemoRepo>();
    shared_ptr<Controller::ElectricController> ctrl_InMemo = make_shared<Controller::ElectricController>(repo_InMemo);
    UI::ElectricUI ui_InMemo = UI::ElectricUI(ctrl_InMemo);

    //create CSV
    shared_ptr<Repository::CrudRepository> repo_CSV = make_shared<Repository::ElectricCSVRepo>();
    shared_ptr<Controller::ElectricController> ctrl_CSV = make_shared<Controller::ElectricController>(repo_CSV);
    UI::ElectricUI ui_CSV = UI::ElectricUI(ctrl_CSV);

    //add 10 cars to InMemory
    repo_InMemo->add_car_manager("Ford", "Focus", 2002, 1230, 20, 1000);
    repo_InMemo->add_car_manager("Dacia", "Logan", 1980, 20, 10, 10);
    repo_InMemo->add_car_manager("Tesla", "ModelX", 2020, 69000, 300, 900);
    repo_InMemo->add_car_manager("Porsche", "Taycan", 2019, 100000, 23, 870);
    repo_InMemo->add_car_manager("Porsche", "Taycan", 2020, 110000, 20, 900);
    repo_InMemo->add_car_manager("Tesla", "ModelX", 2017, 67000, 350, 800);
    repo_InMemo->add_car_manager("Volkswagen", "Golf", 1950, 10, 3000, 10);
    repo_InMemo->add_car_manager("Ford", "Fiesta", 2002, 2000, 130, 200);
    repo_InMemo->add_car_manager("Tesla", "ModelY", 2018, 49900, 200, 900);
    repo_InMemo->add_car_manager("Porsche", "Taycan Turbo S", 2022, 200000, 200, 1200);

    //save the cars from CSV
    repo_CSV->read_manager();

    //Choose saving type
    int save_typ;
    cout << "---Saving Menu---" << endl;
    cout << "Press 1 for volatile saving" << endl;
    cout << "Press 2 for persistent saving" << endl;
    cout << endl;
    cout << "Saving type:";
    cin >> save_typ;

    //Menu InMemory
    string kunde;
    if (save_typ == 1) {
        int option;
        do {
            cout << "======Main-Menu======" << endl;
            cout << "- Press 1 for Manager-Menu" << endl;
            cout << "- Press 2 for Kunde-Menu" << endl;
            cout << "- Press 0 to exit" << endl;

            cout << endl;
            cout << "Option:";
            cin >> option;

            if (option == 1)
                ui_InMemo.Manger_Menu();
            if (option == 2) {
                cout << "Name des Kundes:";
                cin >> kunde;
                ui_InMemo.Kunde_Menu(kunde);
            }

        } while (option != 0);
    }

    //Menu CSV
    if (save_typ == 2) {
        int option;
        do {
            cout << "======Main-Menu======" << endl;
            cout << "- Press 1 for Manager-Menu" << endl;
            cout << "- Press 2 for Kunde-Menu" << endl;
            cout << "- Press 0 to exit" << endl;

            cout << endl;
            cout << "Option:";
            cin >> option;

            if (option == 1)
                ui_CSV.Manger_Menu();
            if (option == 2) {
                cout << "Name des Kundes:";
                cin >> kunde;
                //save the cars from kunde in fav_cars
                repo_CSV->read_client(kunde);
                ui_CSV.Kunde_Menu(kunde);
            }

        } while (option != 0);
    }
}
