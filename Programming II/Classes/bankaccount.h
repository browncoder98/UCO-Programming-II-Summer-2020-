#include <string>
using namespace std;

class bankaccount
{
private:
    int id;
    string name;
    double balance;
    int n;

public:
    void set_id(int n);

    int get_id();

    double get_balance();

    void set_balance(double b);
};