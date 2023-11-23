#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ordering {
public:
    //int choice;

   int total = 0;

    int choiceEntree (int option){
        if (option == 1) {
            total = total + 6.95;

        }
        else if (option == 2) {
            total = total + 5.45;

        }
        else if (option == 3) {
            total = total + 6.50;

        }
        else if (option == 4) {
            total = total + 4.99;

        }
        return total;
    };
};

int main() {
    Ordering start;

    int menu = 0;

    vector<Ordering> customerOrder;
    while (menu != 3) {

        int menu;
        std::string decision;
        std::cout << "Select a menu category number" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Entrees" << std::endl;
        std::cout << "2) Sides" << std::endl;
        std::cout << "3) Drinks" << std::endl;
        std::cout << "Would you like to cancel or complete your order?" << std::endl;
        std::cout << "4) Place Order" << std::endl;
        std::cout << "5) Cancel Order" << std::endl;
        std::cin >> menu;
        //std:: cout << menu;

        if (menu < 1 || menu > 5) {
            std:: cout << std::endl;
           std:: cout <<  "Please enter a valid selection: ";
            std::cin >> menu;
        }

        switch (menu) {
            case 1: {
                int entreeChoice;
                std::cout << "Entrees:" << std::endl;
                std::cout << "1) Grilled Chicken Sandwich- $6.95" << std::endl;
                std::cout << "2) Fried Chicken Sandwich: $5.45" << std::endl;
                std::cout << "3) 6 Count Chicken Fingers: $6.50" << std::endl;
                std::cout << "4) Chicken Noodle Soup: $4.99" << std::endl;
                std::cin >> entreeChoice;
                start.choiceEntree(entreeChoice);
                break;
            };
                // Add cases for other menu options here.
            case 2: {

                break;
            }
            case 3: {

                break;
            }
            case 4: {
                std::cout << "Order placed" << std::endl;
                std::cout << start.choiceEntree();
                break;
            }
            case 5: {

                break;

            }
            if (menu == 5){
                std::cout << "Order placed" << std::endl;
            }
        }
    }


    return 0;
}
