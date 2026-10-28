#include <iostream>
#include <utility>
#include "ProductList.h"

using namespace std;

ProductList::ProductList()
{
    head = nullptr;
    count = 0;
}

ProductNode* ProductList::GetNodeAt(int index)
{
    ProductNode* current = head;

    for (int i = 0; i < index && current != nullptr; i++)
        current = current->next;

    return current;
}

void ProductList::SwapProductData(ProductNode* a, ProductNode* b)
{
    swap(a->productID, b->productID);
    swap(a->productName, b->productName);
    swap(a->price, b->price);
}

void ProductList::Insert(ProductNode* product)
{
    if (product == nullptr)
        return;

    product->next = head;
    head = product;
    count++;
}

ProductNode* ProductList::Remove()
{
    if (IsEmpty())
        return nullptr;

    ProductNode* product = head;
    head = head->next;
    product->next = nullptr;
    count--;

    return product;
}

bool ProductList::IsEmpty() const
{
    return head == nullptr;
}

bool ProductList::IsNotEmpty() const
{
    return head != nullptr;
}

void ProductList::InsertAt(ProductNode* product, int index)
{
    if (product == nullptr)
        return;

    if (index < 0)
        index = 0;

    if (index > count)
        index = count;

    if (index == 0)
    {
        Insert(product);
        return;
    }

    ProductNode* previous = GetNodeAt(index - 1);

    product->next = previous->next;
    previous->next = product;
    count++;
}

ProductNode* ProductList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index < 0)
        index = 0;

    if (index >= count)
        index = count - 1;

    if (index == 0)
        return Remove();

    ProductNode* previous = GetNodeAt(index - 1);
    ProductNode* product = previous->next;

    previous->next = product->next;
    product->next = nullptr;
    count--;

    return product;
}

void ProductList::Swap(int index1, int index2)
{
    if (index1 < 0 || index1 >= count ||
        index2 < 0 || index2 >= count)
        return;

    if (index1 == index2)
        return;

    SwapProductData(GetNodeAt(index1), GetNodeAt(index2));
}

void ProductList::Sort()
{
    for (ProductNode* i = head; i != nullptr; i = i->next)
    {
        for (ProductNode* j = i->next; j != nullptr; j = j->next)
        {
            if (i->productID > j->productID)
                SwapProductData(i, j);
        }
    }
}

void ProductList::Reverse()
{
    ProductNode* previous = nullptr;
    ProductNode* current = head;
    ProductNode* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

void ProductList::Print()
{
    ProductNode* current = head;
    int index = 0;

    cout << "\nIndex\tID\tProduct\tPrice\n";

    while (current != nullptr)
    {
        cout << index << "\t"
             << current->productID << "\t"
             << current->productName << "\t"
             << current->price << endl;

        current = current->next;
        index++;
    }

    cout << "Total products: " << count << endl;
}

ProductList::~ProductList()
{
    while (!IsEmpty())
        delete Remove();
}

ProductNode* CreateProduct(int id, string name, double price)
{
    ProductNode* product = new ProductNode;

    product->productID = id;
    product->productName = name;
    product->price = price;
    product->next = nullptr;

    return product;
}
