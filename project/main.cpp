#include <iostream>
#include <string>
#include <vector>
#include <variant>

using namespace std;

// this struct allows for several types of menu items, dirnks, entrees, and sides
// to all be held under a single name, and spits out the total price of the order
// and which menu item was chosen
struct MenuResult {
    string menuItem;
    double total;
    double drinkPrice;
    double entreePrice;
    double sidePrice;
};


// this class gives each menu item its name and coresponding price and saves it into
// a vector that is a list of items order
class Ordering {
private:
    // vector to store ordered items and their prices
    vector<variant<string, double>> customerOrder;

public:
    double total = 0.0;
    // allows a string anf double to be added to the vector and pushes the items
    // back so that more than one can be stored
    void addToVector(const string& itemName, double itemPrice) {
        customerOrder.push_back(itemName);
        customerOrder.push_back(itemPrice);
        total += itemPrice;
    }
    //gets entree item and price and adds to total
        MenuResult choiceEntree(int option) {
        MenuResult result;

        if (option == 1) {
            result.menuItem = "Grilled Chicken Sandwich";
            result.total += 6.95;
            result.entreePrice = 6.95;
        } else if (option == 2) {
            result.menuItem = "Fried Chicken Sandwich";
            result.total += 5.45;
            result.entreePrice =5.45;
        } else if (option == 3) {
            result.menuItem= "6 Count Chicken Fingers";
            result.total += 6.50;
            result.entreePrice = 6.50;
        } else if (option == 4) {
            result.menuItem = "Chicken Noodle Soup";
            result.total += 4.99;
            result.entreePrice = 4.99;
        }

        addToVector(result.menuItem, result.entreePrice);
        return result;
    }
      //gets side item and price and adds to total
    MenuResult choiceSide(int option) {
        MenuResult result;
        if (option == 1) {
            result.menuItem = "Fries";
            result.total += 2.79;
            result.sidePrice = 2.79;
        } else if (option == 2) {
            result.menuItem = "Fruit";
            result.total += 3.75;
            result.sidePrice = 3.75;
        } else if (option == 3) {
            result.menuItem = "Mac and Cheese";
            result.total += 3.50;
            result.sidePrice = 3.5;
        } else if (option == 4) {
            result.menuItem = "Chips";
            result.total += 1.69;
            result.sidePrice = 1.69;
        }

        addToVector(result.menuItem, result.sidePrice);
        return result;
    }
   //gets drink item and price and adds to total
    MenuResult choiceDrink(int option) {
        MenuResult result;

        if (option == 1) {
            result.menuItem = "Water";
            result.total += 0.00;
            result.drinkPrice = 0.00;
        } else if (option == 2) {
            result.menuItem = "Lemonade";
            result.total += 2.75;
            result.drinkPrice = 2.75;
        } else if (option == 3) {
            result.menuItem = "Coke";
            result.total += 3.00;
            result.drinkPrice = 3.00;
        } else if (option == 4) {
            result.menuItem= "Sweet Tea";
            result.total += 2.75;
            result.drinkPrice = 2.75;
        }
        // places ordered item in vector that lists items ordered
        addToVector(result.menuItem, result.drinkPrice);
        return result;
    }
    //dislplays what item was just added to the order
    void displayOrder() const {
        cout << "Ordered Items:\n";
        for (size_t i = 0; i < customerOrder.size(); i += 2) {
            cout <<  get<string>(customerOrder[i]) << " - Price: $" << get<double>(customerOrder[i + 1]) << endl;
        }
        cout << "Total: $" << total << endl;
    }
};

int main() {
    Ordering start;
    int menu = 0;
// shows menu options
    while (menu != 3) {
        int menu;
        string decision;
        cout << "Select a menu category number" << std::endl;
        cout << "Menu:" << std::endl;
        cout << "1) Entrees" << std::endl;
        cout << "2) Sides" << std::endl;
        cout << "3) Drinks" << std::endl;
        cout << "Would you like to cancel or complete your order?" << std::endl;
        cout << "4) Complete and Place Order" << std::endl;
        cout << "5) Cancel Order" << std::endl;
        cin >> menu;
// checks for valid menu choice
        if (menu < 1 || menu > 5) {
            cout << std::endl;
            cout << "Please enter a valid selection: ";
            cin >> menu;
        }
// switch statement to open the correct sub menu
        switch (menu) {
            case 1: {
                int entreeChoice;
                cout << "Entrees:" << std::endl;
                cout << "1) Grilled Chicken Sandwich- $6.95" << std::endl;
                cout << "2) Fried Chicken Sandwich: $5.45" << std::endl;
                cout << "3) 6 Count Chicken Fingers: $6.50" << std::endl;
                cout << "4) Chicken Noodle Soup: $4.99" << std::endl;
                cin >> entreeChoice;
// checks for a correct choice
                if (entreeChoice < 1 || entreeChoice > 4) {
                    cout << std::endl;
                    cout << "Please enter a valid selection: ";
                    cin >> entreeChoice;
                }

                MenuResult entreeResult = start.choiceEntree(entreeChoice);
                cout << "Total cost after adding entree: $" << entreeResult.total << endl;
                cout << "Selected entree: " << entreeResult.menuItem << endl;
                break;
            }

            case 2: {
                int sideChoice;
                cout << "Sides:" << std::endl;
                cout << "1) Fries: $2.79" << std::endl;
                cout << "2) Fruit: $3.75" << std::endl;
                cout << "3) Mac and Cheese: $3.50" << std::endl;
                cout << "4) Chips: $1.69" << std::endl;
                cin >> sideChoice;
// checks for a correct choice
                if (sideChoice < 1 || sideChoice > 4) {
                    cout << std::endl;
                    cout << "Please enter a valid selection: ";
                    cin >> sideChoice;
                }

                MenuResult sideResult = start.choiceSide(sideChoice);
                cout << "Total cost after adding side: $" << sideResult.total << endl;
                cout << "Selected side: " << sideResult.menuItem << endl;
                break;
            }

            case 3: {
                int drinkChoice;
                cout << "Drinks:" << std::endl;
                cout << "1) Water: $0.00" << std::endl;
                cout << "2) Lemonade: $2.75" << std::endl;
                cout << "3) Coke: $3.00" << std::endl;
                cout << "4) Sweet Tea: $2.75" << std::endl;
                cin >> drinkChoice;
// checks for a correct choice
                if (drinkChoice < 1 || drinkChoice > 4) {
                    cout << std::endl;
                    cout << "Please enter a valid selection: ";
                    cin >> drinkChoice;
                }

                MenuResult drinkResult = start.choiceDrink(drinkChoice);
                cout << "Total cost after adding drink: $" << drinkResult.total << endl;
                cout << "Selected drink: " << drinkResult.menuItem << endl;

                break;
            }
// allows you to view your order, put in your delivery address, and complete order
            case 4: {
                string street, state, city, zip, response;
                cout << "Review Order: "<< endl;
                start.displayOrder();
                cout<< "Is this correct?" << endl;
                cin >> response;
                cout << "To complete your order, please enter your street address: " << endl;
                cin.ignore();
                getline(cin, street);

                cout << "Enter city: " << endl;
                getline(cin, city);

                cout << "Enter State: " << endl;
                getline(cin, state);

                cout << "Enter zip code: " << endl;
                getline(cin, zip);

                cout << "Please Confirm your address:" << endl;
                cout << street << endl;
                cout << city << ", " << state << ", " << zip << endl;
                cout << "Confirm  or  Change?"<< endl;
                cout << "Order placed, estimated delivery time: 30 minutes" << endl;
                // Assuming start and displayOrder() are properly defined
                start.displayOrder();
                cout << "Total cost: $" << start.total << endl; // Show total cost
                return 0;
                break;
            }
            // cancels order
            case 5: {
                cout<< "Order Canceled"<< endl;
                return 0;
                break;
            }
        }
    }

    return 0;
}
