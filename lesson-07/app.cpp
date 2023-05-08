#include <iostream>
#include <cmath>

class Logarithm {
 public:
  Logarithm(double base, double argument) {
    base_ = base;
    argument_ = argument;
  }

  double Calculate() const {
    double result=std::log(argument_) / std::log(base_);
    if (base_<=0)
        throw std::invalid_argument("Base must be positive");
    if (base_==1)
        throw std::invalid_argument("Base cannot be 1");
    if (argument_<=0)
        throw std::invalid_argument("Argument must be positive");
    return result;
  }

 private:
  double base_;
  double argument_;
};


int main()
{
    std::cout << "Test 1: " << std::endl;
    try
    {
        Logarithm Uno(2.0, 3.0);
        double result = Uno.Calculate();
        std::cout << "result: " << result << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Cought an exception: " << e.what() << std::endl;
    }

    std::cout << "Test 2: " << std::endl;
    try
    {
        Logarithm Dos(1.0, 3.0);
        double result = Dos.Calculate();
        std::cout << "result: " << result << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Cought an exception: " << e.what() << std::endl;
    }

    std::cout << "Test 3: " << std::endl;
    try
    {
        Logarithm Dos(5.0, -8.0);
        double result = Dos.Calculate();
        std::cout << "result: " << result << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Cought an exception: " << e.what() << std::endl;
    }
    return 0;
}
