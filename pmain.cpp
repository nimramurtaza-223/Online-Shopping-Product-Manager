#include <iostream>
#include <limits>
#include "ProductList.h"

using namespace std;

int main()
{
    ProductList products;

    int choice, id, index, firstIndex, secondIndex;
    string name;
    double price;

    products.InsertAt(CreateProduct(203, "Keyboard", 2500), 0);
    products.InsertAt(CreateProduct(201, "Mouse", 1200), 1);
    products.InsertAt(CreateProduct(205, "Headphones", 3500), 2);
    products.InsertAt(CreateProduct(202, "USB Drive", 1800), 3);
    products.InsertAt(CreateProduct(204, "Webcam", 4200), 4);

    do
    {
        cout << "\n===== ONLINE SHOPPING PRODUCT MANAGER =====\n";
        cout << "1. Display Products\n";
        cout << "2. Insert Product at Head\n";
        cout << "3. Remove Product from Head\n";
        cout << "4. Insert Product at Index\n";
        cout << "5. Remove Product at Index\n";
        cout << "6. Swap Products\n";
        cout << "7. Sort Products by ID\n";
        cout << "8. Reverse Product List\n";
        cout << "9. Check List Status\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            products.Print();
            break;

        case 2:
            cout << "Enter product ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter product name: ";
            getline(cin, name);

            cout << "Enter product price: ";
            cin >> price;

            products.Insert(CreateProduct(id, name, price));
            break;

        case 3:
        {
            ProductNode* removed = products.Remove();

            if (removed != nullptr)
            {
                cout << "Removed: " << removed->productName << endl;
                delete removed;
            }
            else
                cout << "Product list is empty.\n";

            break;
        }

        case 4:
            cout << "Enter product ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter product name: ";
            getline(cin, name);

            cout << "Enter product price: ";
            cin >> price;

            cout << "Enter index: ";
            cin >> index;

            products.InsertAt(CreateProduct(id, name, price), index);
            break;

        case 5:
        {
            cout << "Enter index: ";
            cin >> index;

            ProductNode* removed = products.RemoveAt(index);

            if (removed != nullptr)
            {
                cout << "Removed: " << removed->productName << endl;
                delete removed;
            }
            else
                cout << "Product list is empty.\n";

            break;
        }

        case 6:
            cout << "Enter first index: ";
            cin >> firstIndex;

            cout << "Enter second index: ";
            cin >> secondIndex;

            products.Swap(firstIndex, secondIndex);
            break;

        case 7:
            products.Sort();
            cout << "Products sorted by ID.\n";
            break;

        case 8:
            products.Reverse();
            cout << "Product list reversed.\n";
            break;

        case 9:
            if (products.IsEmpty())
                cout << "Product list is empty.\n";
            else
                cout << "Product list is not empty.\n";

            break;

        case 10:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}