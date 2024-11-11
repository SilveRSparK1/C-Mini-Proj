#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Data structures to store items and their prices
map<string, map<string, double>> items;
map<pair<int, int>, string> names;

// Function to initialize items and names
void fillItems() {
    items["Saree"]["FABINDIA"] = 15000;
    items["Saree"]["Kalanjali"] = 12000;
    items["Saree"]["Sabyasachi"] = 10000;
    items["Kurti"]["Soch"] = 12000;
    items["Kurti"]["Biba"] = 15000;
    items["Kurti"]["AURELIA"] = 4500;
    items["Sherwani"]["Manyawar"] = 1000;
    items["Sherwani"]["Sabyasachi"] = 3000;
    items["Sherwani"]["SVA"] = 4000;
    items["Sherwani"]["Manish Malhotra"] = 3500;

    names[{1, 1}] = "FABINDIA";
    names[{1, 2}] = "Kalanjali";
    names[{1, 3}] = "Sabyasachi";
    names[{2, 1}] = "Soch";
    names[{2, 2}] = "BIBA";
    names[{2, 3}] = "Aurelia";
    names[{3, 1}] = "Manyavar";
    names[{3, 2}] = "Sabyasachi";
    names[{3, 3}] = "SVA";
    names[{3, 4}] = "Manish Malhotra";
}

class customer {
    map<string, map<string, int>> selected_items;
    string name;

public:
    customer() {
        cout << "Enter your name: ";
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        cout << "HI " << name << "\n\n\n";
    }

    void addToCart(string category, string model) {
        selected_items[category][model]++;
    }

    void printBill() {
        int total_amount = 0;
        cout << "Category\tItem\tQuantity\tCost\n";
        for (auto& category : selected_items) {
            for (auto& model : category.second) {
                int temp = model.second * items[category.first][model.first];
                cout << category.first << "\t\t" << model.first << "\t" << model.second << "\t\t" << temp << endl;
                total_amount += temp;
            }
        }
        cout << "-------------------------------\n";
        cout << "Total amount:\t\t" << total_amount << endl;
        cout << "-------------------------------\n";
        cout << "*****THANK YOU && HAPPY ONLINE SHOPPING*****\n";
    }
};

class shop {
public:
    virtual void show() {}
    virtual void select(customer& obj) {}

    static void showMenu() {
        cout << "Menu\n";
        cout << "1. Saree\n2. Kurti\n3. Sherwani\n4. Checkout\n";
    }
};

class mobile : public shop {
public:
    void show() override {
        cout << "Item\tCost\n";
        int cnt = 1;
        for (auto& it : items["Saree"]) {
            cout << cnt++ << ". " << it.first << " --- Rs." << it.second << "/-\n";
        }
    }

    void select(customer& obj) override {
        int num;
        cout << "Enter your selection\n";
        cin >> num;
        if (num >= 1 && num <= 3) {
            cout << "\n\nPURCHASE SUCCESSFUL! " << names[{1, num}] << " IS ADDED TO THE CART\n\n";
            obj.addToCart("Mobile", names[{1, num}]);
        } else {
            cout << "Wrong Input\n";
        }
    }
};

// Define laptop and courses similar to mobile ...

int main() {
    fillItems();
    cout << "WELCOME TO OUR SHOP!\n";
    customer c;

    while (true) {
        shop::showMenu();
        int val;
        if (!(cin >> val)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (val == 1) {
            mobile mb;
            mb.show();
            mb.select(c);
        }
        else if (val == 2) {
            // Instantiate laptop and show its items
        }
        else if (val == 3) {
            // Instantiate courses and show its items
        }
        else if (val == 4) {
            c.printBill();
            break;
        }
        else {
            cout << "Wrong Input.\n";
        }

        ::std::this_thread::sleep_for(::std::chrono::seconds(3));
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
    return 0;
}
