#include <iostream>
#include <iomanip>
using namespace std;



class Product
{
public:
    string id;
    string name;
    int price;
    int qty;
};



class storage
{
public:

    Product prod[40];
    int count = 0;
    int revenue = 0;


    void add()
    {
        string id;
        string name;
        int price;
        int qty;

        cout << "Enter ID: ";
        cin >> id;

        for(int i = 0; i < count; i++)
        {
            if(prod[i].id == id)
            {
                cout << "Product ID already exists\n";
                return;
            }
        }

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> qty;

        prod[count].id = id;
        prod[count].name = name;
        prod[count].price = price;
        prod[count].qty = qty;

        count++;

        cout << "Product added.\n";
    }

    void restock()
    {
        string id;
        int qty;

        cout << "Enter Product ID: ";
        cin >> id;

        for(int i = 0; i < count; i++)
        {
            if(prod[i].id == id)
            {
                cout << "Quantity to add: ";
                cin >> qty;

                prod[i].qty += qty;

                cout << "Product Restocked.\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }



    void sell()
    {
        string id;
        int qty;

        cout << "Enter Product ID: ";
        cin >> id;

        for(int i = 0; i < count; i++)
        {
            if(prod[i].id == id)
            {
                cout << "Quantity to sell: ";
                cin >> qty;

                if(qty > prod[i].qty)
                {
                    cout << "Not enough stock\n";
                    return;
                }

                prod[i].qty -= qty;

                double amount = prod[i].price * qty;

                revenue += amount;

                cout << fixed << setprecision(2);
                cout << "Sold. Revenue: " << amount << endl;

                return;
            }
        }

        cout << "Product not found.\n";
    }



    void lowStock()
    {
        bool found = false;

        for(int i = 0; i < count; i++)
        {
            if(prod[i].qty < 5)
            {
                cout << prod[i].id << " "
                     << prod[i].name << " "
                     << prod[i].qty << endl;

                found = true;
            }
        }

        if(found == false)
        {
            cout << "No low-stock products\n";
        }
    }



    void showRevenue()
    {
        cout << fixed << setprecision(2);
        cout << "Total Revenue: " << revenue << endl;
    }



    void display()
    {
        for(int i = 0; i < count; i++)
        {
            cout << "\nID: " << prod[i].id << endl;
            cout << "Name: " << prod[i].name << endl;
            cout << "Price: " << prod[i].price << endl;
            cout << "Quantity: " << prod[i].qty << endl;
        }
    }


    void menu()
    {
        int choice;

        do
        {
            cout << "\n------ Inventory Tracker ------\n";
            cout << "1. Add Product\n";
            cout << "2. Restock Product\n";
            cout << "3. Sell Product\n";
            cout << "4. Low Stock\n";
            cout << "5. Revenue\n";
            cout << "6. Display All\n";
            cout << "7. Exit\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    add();
                    break;

                case 2:
                    restock();
                    break;

                case 3:
                    sell();
                    break;

                case 4:
                    lowStock();
                    break;

                case 5:
                    showRevenue();
                    break;

                case 6:
                    display();
                    break;

                case 7:
                    cout << "Exit\n";
                    break;

                default:
                    cout << "Invalid choice\n";
            }

        }while(choice != 7);

    }
};


int main()
{
    storage s;

    s.menu();

    return 0;
}
