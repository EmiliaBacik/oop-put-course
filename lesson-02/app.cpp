#include <iostream>
#include <string>
using namespace std;

class book
{
public:
    int id;
    string author;
    string title;
};

class author
{
public:
    string first_name;
    string last_name;
    int age;
    string country;
};

int main()
{
    class book lord_of_the_rings;
    lord_of_the_rings.id = 1;
    lord_of_the_rings.title = "Lord of the Rings";
    lord_of_the_rings.author = "Tolkien";
    class author flanagan;
    flanagan.first_name = "John";
    flanagan.last_name = "Flanagan";
    flanagan.age = 26;
    flanagan.country = "Australia";

    return 0;
}
