#include <iostream>
#include <string>
#include <vector>
#include <optional>


class Book
{
private:
    std::string title;
    std::string author;
public:
    Book NamedBook(std::string new_title, std::string new_author);
    std::string CurrentTitle();
    std::string CurrentAuthor();
};


class User
{
private:
    std::string login;
    std::string password;
    std::optional<std::vector<Book>> borrowed_book;
public:
    void NewUser(std::string new_login, std::string new_password);
    void BorrowBook(const Book &book);
    Book GiveBackBook();
    std::string CurrentLogin();
};


void User::NewUser(std::string new_login, std::string new_password)
{
    this->login = std::move(new_login);
    this->password = std::move(new_password);
}

void User::BorrowBook(const Book &book)
{
    this->borrowed_book->push_back(book);
}

Book User::GiveBackBook()
{
    Book gived_back_book = this->borrowed_book->back();
    this->borrowed_book->pop_back();
    return gived_back_book;
}

std::string User::CurrentLogin()
{
    return this->login;
}

Book Book::NamedBook(std::string new_title, std::string new_author)
{
    this->title =std::move(new_title);
    this->author =std::move(new_author);
    return *this;
}

std::string Book::CurrentTitle()
{
    return this->title;
}

std::string Book::CurrentAuthor()
{
    return this->author;
}


int main()
{
    User a1, a2;
    a1.NewUser("Maja", "123456");
    a2.NewUser("Hubert03", "password");
    Book fantasy_1, fantasy_2;
    fantasy_1.NamedBook("Lord of the Rings", "Tolkien");
    fantasy_2.NamedBook("Rangers", "Flanagan");
    a1.BorrowBook(fantasy_1);
    a2.BorrowBook(fantasy_2);
    Book example_book = a2.GiveBackBook();
    std::cout << "Title: " << example_book.CurrentTitle() << std::endl;
    std::cout << "Author: " << example_book.CurrentAuthor();


    return 0;
}
