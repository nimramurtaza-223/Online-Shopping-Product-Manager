#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include <string>
using namespace std;

struct ProductNode
{
    int productID;
    string productName;
    double price;
    ProductNode* next;
};

class ProductList
{
private:
    ProductNode* head;
    int count;

    ProductNode* GetNodeAt(int index);
    void SwapProductData(ProductNode* a, ProductNode* b);

public:
    ProductList();
    ~ProductList();

    void Insert(ProductNode* product);
    ProductNode* Remove();
    bool IsEmpty();
    bool IsNotEmpty();
    void InsertAt(ProductNode* product, int index);
    ProductNode* RemoveAt(int index);
    void Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print();
};

ProductNode* CreateProduct(int id, string name, double price);

#endif