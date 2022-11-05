#pragma once
#include "Controller.h"

namespace UI{
    class ElectricUI{
        private:
            shared_ptr<Controller::ElectricController> ctrl;

        public:

            //constructor
            ElectricUI(shared_ptr<Controller::ElectricController> &ctrl);

            //getter for Cotroller type object
            Controller::ElectricController get_ctrl();

            //Manager-Menu
            void Manger_Menu();

            //Kunde-Menu
            void Kunde_Menu(string kunde);
    };
}
