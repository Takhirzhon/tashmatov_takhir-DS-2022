#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <vector>
#include <utility>
#include <iomanip>

#include "../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

// bool isEven(int n)
// {
//     return n % 2 == 0;
// }

// This is functor
struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};

void p0101()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << "not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << "not found\n";
            }
        }
    }
}
void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << "not found\n";
            }
        }
    }
}

void p0201()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    auto it = find_if(begin(a), end(a), IsEven());
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << *it << "No even numbers are found\n";
    }
}
void p0202()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    auto it = find_if(begin(a), end(a),
                      [](int n)
                      { return n % 2 == 0; });
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << *it << "No even numbers are found\n";
    }
}

struct GreaterThan
{
    int mX;
    GreaterThan(int x) : mX(x){};
    bool operator()(int n) const
    {
        return n > mX;
    }
};
void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    cout << "Enter x: ";
    int x;
    cin >> x;

    auto it = find_if(begin(a), end(a),
                      [x](int n)
                      { return n > x; });
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << *it << "No even numbers are found\n";
    }
}

void p06()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    // sorting by Name
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    cout << " - - - " << endl;
    cout << fixed << showpoint << setprecision(2);
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    // sorting by GPA
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });
    cout << " - - - " << endl;
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

int main()
{
    // p0101();
    // p0102();

    // p0201();
    // p0202();
    // p06();
    p03();
}