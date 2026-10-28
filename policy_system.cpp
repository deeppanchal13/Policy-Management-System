#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Customer
{
public:
    int id, age;
    string name, phone;

    void addCustomer()
    {
        cout << "Enter customer name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter phone: ";
        cin >> phone;
    }

    void display()
    {
        cout << "\nCustomer ID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nPhone: " << phone << "\n";
    }

    void save()
    {
        ofstream file("customers.txt", ios::app);
        file << id << "|" << name << "|"
             << age << "|" << phone << "\n";
        file.close();
    }
};

class Policy
{
public:
    int id, customerId, duration;
    string type;
    double amount, premium;

    bool create()
    {
        cout << "Enter customer ID: ";
        cin >> customerId;

        cout << "Enter policy type (Life/Health/Vehicle/Property): ";
        cin >> type;

        cout << "Enter coverage amount: ";
        cin >> amount;

        cout << "Enter duration in years: ";
        cin >> duration;

        if (amount <= 0 || duration <= 0)
        {
            cout << "Invalid amount or duration!\n";
            return false;
        }

        double rate = 0;

        if (type == "Life")
            rate = 0.03;
        else if (type == "Health")
            rate = 0.05;
        else if (type == "Vehicle")
            rate = 0.04;
        else if (type == "Property")
            rate = 0.02;

        if (rate == 0)
        {
            cout << "Invalid policy type!\n";
            return false;
        }

        premium = amount * rate * duration;
        cout << "Premium: " << premium << "\n";

        return true;
    }

    void display()
    {
        cout << "\nPolicy ID: " << id;
        cout << "\nCustomer ID: " << customerId;
        cout << "\nType: " << type;
        cout << "\nCoverage: " << amount;
        cout << "\nDuration: " << duration << " years";
        cout << "\nPremium: " << premium << "\n";
    }

    void save()
    {
        ofstream file("policies.txt", ios::app);
        file << id << "|" << customerId << "|"
             << type << "|" << amount << "|"
             << duration << "|" << premium << "\n";
        file.close();
    }
};

Customer customers[100];
Policy policies[100];

int customerCount = 0;
int policyCount = 0;

// Add Customer
void addCustomer()
{
    if (customerCount >= 100)
    {
        cout << "Customer limit reached!\n";
        return;
    }

    customers[customerCount].id = customerCount + 1;
    customers[customerCount].addCustomer();
    customers[customerCount].save();

    cout << "Customer added successfully!\n";
    customerCount++;
}

// View Customers - while loop
void viewCustomers()
{
    if (customerCount == 0)
    {
        cout << "No customers found!\n";
        return;
    }

    int i = 0;

    while (i < customerCount)
    {
        customers[i].display();
        i++;
    }
}

// Create Policy - for loop
void addPolicy()
{
    if (customerCount == 0)
    {
        cout << "Add a customer first!\n";
        return;
    }

    if (policyCount >= 100)
    {
        cout << "Policy limit reached!\n";
        return;
    }

    policies[policyCount].id = policyCount + 1;

    if (!policies[policyCount].create())
        return;

    bool found = false;

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].id == policies[policyCount].customerId)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Customer not found!\n";
        return;
    }

    policies[policyCount].save();
    cout << "Policy created successfully!\n";
    cout << "Policy ID: " << policies[policyCount].id << "\n";

    policyCount++;
}

// View Policies - for loop
void viewPolicies()
{
    if (policyCount == 0)
    {
        cout << "No policies found!\n";
        return;
    }

    for (int i = 0; i < policyCount; i++)
    {
        policies[i].display();
    }
}

// Search Policy - while loop
void searchPolicy()
{
    int id;

    cout << "Enter policy ID: ";
    cin >> id;

    int i = 0;

    while (i < policyCount && policies[i].id != id)
    {
        i++;
    }

    if (i == policyCount)
        cout << "Policy not found!\n";
    else
        policies[i].display();
}

int main()
{
    int choice = -1;

    while (choice != 0)
    {
        cout << "\n===== INSURANCE MANAGEMENT =====\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Create Policy\n";
        cout << "4. View Policies\n";
        cout << "5. Search Policy\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addCustomer();
            break;

        case 2:
            viewCustomers();
            break;

        case 3:
            addPolicy();
            break;

        case 4:
            viewPolicies();
            break;

        case 5:
            searchPolicy();
            break;

        case 0:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

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