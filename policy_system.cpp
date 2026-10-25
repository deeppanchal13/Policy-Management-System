
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Customer {
    int id;
    string name;
    int age;
    string phone;
};

struct Policy {
    int policyId;
    int customerId;
    string type;
    double amount;
    int duration;
    double premium;
};

Customer customers[100];
Policy policies[100];

int customerCount = 0;
int policyCount = 0;

// Add Customer
void addCustomer() {
    if (customerCount >= 100) {
        cout << "Customer limit reached!\n";
        return;
    }

    Customer c;
    c.id = customerCount + 1;

    cout << "Enter customer name: ";
    cin >> ws;
    getline(cin, c.name);

    cout << "Enter age: ";
    cin >> c.age;

    cout << "Enter phone number: ";
    cin >> c.phone;

    customers[customerCount] = c;
    customerCount++;

    ofstream file("customers.txt", ios::app);
    file << c.id << "|" << c.name << "|"
         << c.age << "|" << c.phone << "\n";
    file.close();

    cout << "Customer added successfully!\n";
    cout << "Customer ID: " << c.id << "\n";
}

// View Customers
void viewCustomers() {
    if (customerCount == 0) {
        cout << "No customers available.\n";
        return;
    }

    for (int i = 0; i < customerCount; i++) {
        cout << "\nCustomer ID: " << customers[i].id;
        cout << "\nName: " << customers[i].name;
        cout << "\nAge: " << customers[i].age;
        cout << "\nPhone: " << customers[i].phone << "\n";
    }
}

// Calculate Premium
double calculatePremium(double amount, string type,
                        int duration) {
    double rate;

    if (type == "Life")
        rate = 0.03;
    else if (type == "Health")
        rate = 0.05;
    else if (type == "Vehicle")
        rate = 0.04;
    else if (type == "Property")
        rate = 0.02;
    else
        return -1;

    return amount * rate * duration;
}

// Create Policy
void createPolicy() {
    if (policyCount >= 100) {
        cout << "Policy limit reached!\n";
        return;
    }

    if (customerCount == 0) {
        cout << "Add a customer first!\n";
        return;
    }

    Policy p;
    p.policyId = policyCount + 1;

    cout << "Enter customer ID: ";
    cin >> p.customerId;

    bool found = false;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == p.customerId) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Customer not found!\n";
        return;
    }

    cout << "Policy types: Life, Health, Vehicle, Property\n";
    cout << "Enter policy type: ";
    cin >> p.type;

    cout << "Enter coverage amount: ";
    cin >> p.amount;

    cout << "Enter duration in years: ";
    cin >> p.duration;

    if (p.amount <= 0 || p.duration <= 0) {
        cout << "Amount and duration must be positive!\n";
        return;
    }

    p.premium = calculatePremium(
        p.amount, p.type, p.duration
    );

    if (p.premium < 0) {
        cout << "Invalid policy type!\n";
        return;
    }

    policies[policyCount] = p;
    policyCount++;

    ofstream file("policies.txt", ios::app);
    file << p.policyId << "|" << p.customerId << "|"
         << p.type << "|" << p.amount << "|"
         << p.duration << "|" << p.premium << "\n";
    file.close();

    cout << "\nPolicy created successfully!\n";
    cout << "Policy ID: " << p.policyId << "\n";
    cout << "Total premium: " << p.premium << "\n";
}

// View Policies
void viewPolicies() {
    if (policyCount == 0) {
        cout << "No policies available.\n";
        return;
    }

    for (int i = 0; i < policyCount; i++) {
        cout << "\nPolicy ID: " << policies[i].policyId;
        cout << "\nCustomer ID: " << policies[i].customerId;
        cout << "\nType: " << policies[i].type;
        cout << "\nCoverage: " << policies[i].amount;
        cout << "\nDuration: " << policies[i].duration
             << " years";
        cout << "\nTotal premium: " << policies[i].premium
             << "\n";
    }
}

// Search Policy
void searchPolicy() {
    int id;
    cout << "Enter policy ID: ";
    cin >> id;

    for (int i = 0; i < policyCount; i++) {
        if (policies[i].policyId == id) {
            cout << "\nPolicy found!\n";
            cout << "Customer ID: "
                 << policies[i].customerId << "\n";
            cout << "Type: " << policies[i].type << "\n";
            cout << "Coverage: " << policies[i].amount << "\n";
            cout << "Duration: " << policies[i].duration
                 << " years\n";
            cout << "Premium: " << policies[i].premium << "\n";
            return;
        }
    }

    cout << "Policy not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== INSURANCE POLICY MANAGEMENT =====\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Create Policy\n";
        cout << "4. View Policies\n";
        cout << "5. Search Policy\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                createPolicy();
                break;
            case 4:
                viewPolicies();
                break;
            case 5:
                searchPolicy();
                break;
            case 0:
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}






































// #include <iostream>
// using namespace std;

// int name[100], city[100];
// char gender[100];

// void Customer_Management()
// {

// }

// void Policy_Management()
// {

// }



// int main()
// {
//     int choice;

//     cout << "-------------------------------------\n";
//     cout << "-                                   -\n";
//     cout << "-   WELCOME TO POLICY MANAGEMENT    -\n";
//     cout << "-                                   -\n";
//     cout << "-------------------------------------\n";

//     while (true)
//     {
//         cout << "\n1. Customer Management\n";
//         cout << "2. Policy Management\n";
//         cout << "3. Billing\n";
//         cout << "4. Exit\n";
//         cout << "Enter your choice : ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:

//             break;
//         case 2:

//             break;
//         case 3:

//             break;

//         case 4:
//             cout << "-------------------------------------\n";
//             cout << "-       THANKS FOR VISITING         -\n";
//             cout << "-------------------------------------\n";
//             return 0;

//         default:
//             cout << "INVALID NUMBER\n";
//         }
//     }
// }