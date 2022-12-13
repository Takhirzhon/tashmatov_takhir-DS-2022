#include "VecInt.hpp"
#include <stdexcept>

#include "/home/tashmatov_t/tashmatov_takhir-DS-2022-2/preperation for final/au/algol.hpp"

using namespace std;

void p01();
void p02();
void printVecInt(const VecInt &v);

int main()

try
{
    p01();
    p02();
}
catch (const std::exception &e)
{
    std::cerr << e.what() << endl;
}

void p01()
{
    cout << "Enter arrau's size ";

    int x;
    cin >> x;

    VecInt v(x);

    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }

    auReverce(v.begin(), v.end());
    printVecInt(v);
}

void p02()
{
    cout << " Enter Numbers: " << endl;
    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }
    printVecInt(v);
    auReverce(v.begin(), v.end());
    printVecInt(v);
}

void printVecInt(const VecInt &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}