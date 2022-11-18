#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

template <typename T>
void auSwap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

// pass by value
void badSwap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

// pass by reference
void goodSwap01(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
// pass by pointer by value
void goodSwap02(int *pA, int *pB)
{
    int t = *pA;
    *pA = *pB;
    *pB = t;
}

int main()
{
    iostream::sync_with_stdio(false);

    cout << "1st int: ";

    int a;
    cin >> a;

    cout << "2nd int: ";
    int b;
    cin >> b;

    cout << "standard swap: " << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "badSwap: " << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    badSwap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "goodSwap01" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap01(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "goodSwap02" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap02(&a, &b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    double d1 = 1.6;
    double d2 = 3.14;
    cout << "general swap for doubles: " << endl;
    cout << "Before swap a = " << d1 << ", b = " << d2 << endl;
    auSwap(d1, d2);
    cout << "After swap a = " << d1 << ", b = " << d2 << endl;

    string s1 = "String number one";
    string s2 = "String number TWO";
    cout << "general swap for strings: " << endl;
    cout << "Before swap a = " << s1 << ", b = " << s2 << endl;
    auSwap(s1, s2);
    cout << "After swap a = " << s1 << ", b = " << s2 << endl;
}