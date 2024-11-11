#include <bits/stdc++.h>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// map data structure to store category-model as key and
// their price as value
map<string, map<string, double> > items;

// map data structure to store category-model in integer
// form as key and their model selected by the customer as
// value
map<pair<int, int>, string> names;

// Function to clear the screen (based on OS)
void clearScreen() {
#ifdef _WIN32
    system("CLS"); // for Windows
#else
    system("clear"); // for Linux and macOS
#endif
}

// a function to fill the product data into the data
// structure
void fillItems()
{
    items["Saree"]["FABIndia"] = 15000;
    items["Saree"]["Kalanjali"] = 12000;
    items["Saree"]["Sabyasachi"] = 100000;
    items["Kurti"]["Soch"] = 40000;
    items["Kurti"]["Biba"] = 35000;
    items["Kurti"]["Auralia"] = 250000;
    items["Sherwani"]["Manish Malhotra"] = 1000;
    items["Sherwani"]["Manyawar"] = 3000;
    items["Sherwani"]["SVA"] = 4000;
    items["Sherwani"]["Sabyasachi"] = 3500;

    names[{ 1, 1 }] = "FABIndia";
    names[{ 1, 2 }] = "Kalanjali";
    names[{ 1, 3 }] = "Sabyasachi";

    names[{ 2, 1 }] = "Soch";
    names[{ 2, 2 }] = "Biba";
    names[{ 2, 3 }] = "Auralia";

    names[{ 3, 1 }] = "Manish Malhotra";
    names[{ 3, 2 }] = "Manyawar";
    names[{ 3, 3 }] = "SVA";
    names[{ 3, 4 }] = "Sabyasachi";
}

// class customer to represent a real world entity, in our case - a customer
class customer {
    map<string, map<string, int> > selected_items;
    string name;

public:
    customer()
    {
        cout << "Enter your name: ";
        string customer_name;
        getline(cin, customer_name);
        name = customer_name;
        cout << "HI ";
        for (int i = 0; i < customer_name.length(); i++) {
            cout << char(toupper(customer_name[i]));
        }
        cout << "\n\n\n";
    }

    void addToCart(string a, string b)
    {
        selected_items[a][b]++;
    }

    void printBill()
    {
        int total_amount = 0;
        cout << left << setw(15) << "Category"
             << setw(20) << "Item"
             << setw(10) << "Quantity"
             << "Cost\n\n";

        map<string, map<string, int>>::iterator itr;
        map<string, int>::iterator ptr;
        for (itr = selected_items.begin(); itr != selected_items.end(); itr++) {
            for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
                string category = itr->first;
                string model = ptr->first;
                int quantity = ptr->second;
                int temp = quantity * items[category][model];

                cout << left << setw(15) << category
                     << setw(20) << model
                     << setw(10) << quantity
                     << temp << endl;

                total_amount += temp;
            }
        }

        cout << "----------------------------------------------------\n";
        cout << setw(45) << "Total amount:" << total_amount << endl;
        cout << "----------------------------------------------------\n";
        cout << "***** THANK YOU & HAPPY ONLINE SHOPPING *****" << endl;
    }
};

// class shop to represent a real world entity - in our case a shop
class shop {
public:
    shop() {}

    virtual void show()
    {
        // this will be overridden
    }
    virtual void select(customer& obj)
    {
        // this will be overridden
    }

    void showMenu()
    {
        cout << "                 Menu\n";
        cout << " -----------------------------------------\n";
        cout << "1.Saree\n2.Kurti\n3.Sherwani\n4.Checkout\n\n";
        cout << " -----------------------------------------\n";
    }
};

class saree : public shop {
public:
    void show()
    {
        cout << "- - - - - - - - - - - - -\nItem    Cost\n";
        int cnt = 1;
        for (auto& it : items["Saree"]) {
            cout << cnt++ << ". " << it.first << " --- Rs."
                 << it.second << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n\n";
    }

    void select(customer& obj)
    {
        cout << "These are the Saree categories we have....\n";
        int num;
        cout << "Enter your selection\n";
        cin >> num;
        if (num < 1 || num > 3) {
            cout << "Wrong Input\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! ";
        cout << names[{ 1, num }]
             << " IS ADDED TO THE CART\n\n";
        obj.addToCart("Saree", names[{ 1, num }]);
    }
};

class kurti : public shop {
public:
    void show()
    {
        cout << "- - - - - - - - - - - - -\nItem    Cost\n";
        int cnt = 1;
        for (auto& it : items["Kurti"]) {
            cout << cnt++ << ". " << it.first << " --- Rs."
                 << it.second << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n";
    }
    void select(customer& obj)
    {
        cout << "These are the kurti categories we have....\n";
        int num;
        cout << "Enter your selection\n";
        cin >> num;
        if (num < 1 || num > 3) {
            cout << "Wrong Input\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! ";
        cout << names[{ 2, num }]
             << " IS ADDED TO THE CART\n\n";
        obj.addToCart("Kurti", names[{ 2, num }]);
    }
};

class sherwani : public shop {
public:
    void show()
    {
        cout << "- - - - - - - - - - - - -\nItem    Cost\n";
        int cnt = 1;
        for (auto& it : items["Sherwani"]) {
            cout << cnt++ << ". " << it.first << " --- Rs."
                 << it.second << "/-\n";
        }
        cout << "- - - - - - - - - - - - -\n";
    }
    void select(customer& obj)
    {
        cout << "These are the sherwani categories we have....\n";
        int num;
        cout << "Enter your selection\n";
        cin >> num;
        if (num < 1 || num > 4) {
            cout << "Wrong Input\n";
            return;
        }
        cout << "\n\nPURCHASE SUCCESSFUL!! ";
        cout << names[{ 3, num }]
             << " IS ADDED TO THE CART\n\n";
        obj.addToCart("Sherwani", names[{ 3, num }]);
    }
};

int main()
{
    fillItems();
    cout << "WELCOME TO OUR SHOP. WE ARE DELIGHTED THAT YOU ARE HERE.\n";
    customer c;
    shop* s;

    while (1) {
        clearScreen();
        s->showMenu();
        cout << "Please select an option to proceed further.\n";
        int val;
        cin >> val;

        if (val == 1) {
            saree sa;
            s = &sa;
            s->show();
            s->select(c);
        }
        else if (val == 2) {
            kurti k;
            s = &k;
            s->show();
            s->select(c);
        }
        else if (val == 3) {
            sherwani sh;
            s = &sh;
            sh.show();
            sh.select(c);
        }
        else if (val == 4) {
            c.printBill();
            break;
        }
        else {
            cout << "Please enter a valid option!\n";
        }

        sleep_for(seconds(2));
    }
}
