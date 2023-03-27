#include <iostream>
#include <string>

class Guitar
{
private:
    int name;
    int price;
public:
    Guitar(int polish_price, int i)
    {
        this->name=i;
        this->price=polish_price;
    }
    /*void Euro()
    {
        price=price/4.68;
    }
    void Dolars()
    {
        price=price/4.34;
    } */
    Guitar(float polish_price, int i) : Guitar(static_cast<int>(polish_price), i) {};
    Guitar(double polish_price, int i) : Guitar(static_cast<int>(polish_price), i) {};
    Guitar(long polish_price, int i) : Guitar(static_cast<int>(polish_price), i) {};
    int Price() {return this->price;}
};

int main()
{
    int x;
    int polish_price, american_price, euro_price;
    std::cout << "Choose country of guitar: 1-America, 2-Euro, 3-Poland" << std::endl;
    std::cin >> x;
    if (x==1)
    {
        /*std::cin >> american_price;
        Guitar AmericanGuitar(american_price, 1);
        AmericanGuitar.Dolars();
        std::cout << AmericanGuitar.Price(); */
    }
    else if (x==2)
    {
        /*std::cin >> euro_price;
        Guitar EuroGuitar(euro_price, 2);
        EuroGuitar.Euro();
        std::cout << EuroGuitar.Price();*/
        
    }
    else if (x==3)
    {
        std::cin >> polish_price;
        Guitar PolishGuitar(polish_price, 3);
        int z=PolishGuitar.Price();
        std::cout << z;
    }

    return 0;
}
