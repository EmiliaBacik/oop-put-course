#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    virtual void FeedAnimal() = 0;
    virtual void CheckNameAnimal() = 0;
    virtual void CheckAgeAnimal() = 0;
};

class Dog: public Animal{
private:
    int age;
    string name;
    string breed;
public:
    Dog()   {this->age = 0; this->name="idk"; this->breed = "idk";};
    Dog(int ag, string nam, string bree) {this->age = ag; this->name=nam; this->breed = bree;};
    ~Dog();
    void FeedAnimal() override;
    void CheckNameAnimal() override;
    void CheckAgeAnimal() override;
};

class Cat: public Animal{
private:
    int age;
    string name;
    char sex;
public:
    Cat()   {this->age = 0; this->name="idk"; this->sex ='i';};
    Cat(int ag, string nam, char se) {this->age = ag; this->name=nam; this->sex =se;};
    ~Cat();
    void FeedAnimal() override;
    void CheckNameAnimal() override;
    void CheckAgeAnimal() override;
};

void Dog::CheckNameAnimal()
{
    cout << this->name << endl << "Breed: " << this->breed << endl;
}

void Cat::CheckNameAnimal()
{
    cout << this->name << endl << "Sex: " << this->sex << endl;
}

void Dog::CheckAgeAnimal()
{
    cout << this->age << endl;
}

void Cat::CheckAgeAnimal()
{
    cout << this->age << endl;
}

void Dog::FeedAnimal()
{
    cout << "You fed a dog!" << endl;
}

void Cat::FeedAnimal()
{
    cout << "You fed a cat!" << endl;
}


int main()
{
    Animal *kitty;
    kitty = new Cat(6, "Rita", 'F');
    Animal *doggi;
    doggi = new Dog(7, "Rex", "dachshund");
    kitty->CheckNameAnimal();
    kitty->CheckAgeAnimal();
    kitty->FeedAnimal();
    doggi->CheckNameAnimal();
    doggi->CheckAgeAnimal();
    doggi->FeedAnimal();

    delete kitty;
    delete doggi;
    return 0;
}
