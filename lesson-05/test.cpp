#include <iostream>
#include <map>

class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;

  virtual double Rate(const std::string& abbreviation) const = 0;
};

class FakeUsdCantor : public Cantor {
 public:
  FakeUsdCantor() {
    // rates_ map with values for ten most popular currencies relative to USD
    rates_ = {
      {"EUR", 0.85},
      {"JPY", 110.66},
      {"GBP", 0.73},
      {"CHF", 0.91},
      {"CAD", 1.25},
      {"AUD", 1.34},
      {"CNY", 6.47},
      {"HKD", 7.78},
      {"NZD", 1.44},
      {"KRW", 1153.89}
    };
  }

  double Rate(const std::string& abbreviation) const override {
    auto it = rates_.find(abbreviation);
    if (it != rates_.end()) {
      return it->second;
    }
    // Handle error case when currency abbreviation is not found
    return 0.0;
  }

 private:
  std::map<std::string, double> rates_;
};

class Currency {
 public:
  Currency() = default;
  virtual ~Currency() = default;

  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual std::string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};

class Euro : public Currency
{
private:
    std::string abbreviation;
    double amount;

public:
Euro(std::string ab, double am)
{
    abbreviation = ab;
    amount = am;
}
double ConvertedToDollars(const Cantor& cantor) const override
{
    double i=amount/cantor.Rate(this->abbreviation);
    return i;
}
std::string Abbreviation() const override
{
    return abbreviation;
}
double Amount() const override
{
    return amount;
}
};

class JPY : public Currency
{
private:
    std::string abbreviation;
    double amount;

public:
JPY(std::string ab, double am)
{
    abbreviation = ab;
    amount = am;
}
double ConvertedToDollars(const Cantor& cantor) const override
{
    double i=amount/cantor.Rate(this->abbreviation);
    return i;
}
std::string Abbreviation() const override
{
    return abbreviation;
}
double Amount() const override
{
    return amount;
}
};






int main() {
    FakeUsdCantor cantor;
    Euro one("EUR", 100.0);
    double x =one.ConvertedToDollars(cantor);
    std::cout << "Euro " << one.Amount() << std::endl << "In dollars: " <<x << std::endl;
    Euro two("EUR", 50.5);
    std::cout << "Euro " << two.Amount() << std::endl << "In dollars: " << two.ConvertedToDollars(cantor) << std::endl;
    JPY three("JPY", 100.0);
    std::cout << "Japan " << one.Amount() << std::endl << "In dollars: " << three.ConvertedToDollars(cantor) << std::endl;
  return 0;
}
