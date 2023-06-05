#include <iostream>

using namespace std;

int numberP=0;
class Product
{
protected:
    string name;
    int price;
    int id;
public:
    Product(string n="something", int p=0)
    {
        name=n;
        price=p;
        id=numberP;
        numberP++;
    }
    ~Product() = default;
    int SeePrice()
    {
        return price;
    }
};

int numberC=0;
class Customer
{
    string name;
    string email;
    int id;
public:
    Customer(string n="somebody", string e="none")
    {
        name=n;
        email=e;
        id=numberC;
        numberC++;
    }
    ~Customer() = default;

};

int numberO=0;
class Order
{
    int id;
    class Customer person;
    class Product List[20];
    int i=0;
public:
    Order(class Customer c)
    {
        id=numberO;
        person=c;
        numberO++;
    }
    ~Order() = default;
    void AddProduct(class Product p)
    {
        List[i]=p;
        i++;
    }
    void CalculateCost()
    {
        int x=0;
        for(int j=0; j<=i; j++)
        {
            x=x+List[j].SeePrice();
        }
        cout << "Total cost of order " << id << " is " << x << endl;
    }
};


int main()
{
    Product one("apple", 20);
    Product two("banana", 40);
    Product three("tomato", 15);
    Customer ana("Ana", "Ana@onet.pl");
    Customer ben("Ben", "beniscool@gmail.com");
    Order may01(ben);
    Order may02(ana);
    Order may03(ben);
    may01.AddProduct(one);
    may01.AddProduct(three);
    may02.AddProduct(two);
    may02.AddProduct(two);
    may01.CalculateCost();
    may02.CalculateCost();
    may03.CalculateCost();
    return 0;
}
