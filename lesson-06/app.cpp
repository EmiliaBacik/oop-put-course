#include <iostream>
#include <memory>
#include <sstream>
#include <cassert>

class Sequence{
public:
    virtual int Length() = 0;
    class Fake;
};

class Sequence::Fake : public: Sequence{
    int Length(){return 100;};
};

class Gene{
private:
    string name_;
    shared_ptr<Sequence> sequence_;
public:
    Gene(string name, shared_ptr<Sequence> sequence)
    : name_(name), sequence_(sequence){};
    string JSON(){
        sttringstream ss;
        ss << "{";
        ss << " \"name\": \"" << name_ << "\",";
        ss << "\"lenght\": " << sequence_->Length();
        ss << "}";
        return ss.str();

    }
};

using namespace std;

int main()
{
    shared_ptr<Sequence> fakeSequence = make_shared<Sequence::Fake>();
    Gene gene(name: "Jota", sequence fakeSequence);
    cout << gene.JSON();
    assert(gene.JSON() == "To nie działa");

    return 0;
}

