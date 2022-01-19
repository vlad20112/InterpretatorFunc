#include <iostream>
using namespace std;
class Lolkek
{
private:
    int a;

public:
    Lolkek(int some) : a(some) {}
    friend ostream &operator<<(ostream &out, const Lolkek &obj)
    {
        out << "LOLKEK - " << obj.a;
        return out;
    }
};

int main()
{
    Lolkek ret(3);
    cout << ret << endl;
    return 0;
}