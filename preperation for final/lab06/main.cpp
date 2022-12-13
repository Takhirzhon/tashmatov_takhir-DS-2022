#include <stdio.h>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "/home/tashmatov_t/tashmatov_takhir-DS-2022-2/preperation for final/au/algol.hpp"
#include "/home/tashmatov_t/tashmatov_takhir-DS-2022-2/preperation for final/au/algol.hpp"
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
struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};

void p0101()
{
    vector<int> vec = {3, 20, 100, -5, 4};
    {

        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : vec)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Index is " << (it - begin(a)) << endl;
            }
            else
            {
                cout << e << " Index not found " << endl;
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : vec)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Index is " << (it - begin(a)) << endl;
            }
            else
            {
                cout << e << " Index not found " << endl;
            }
        }
    }
}
void p0102()
{
    vector<int> vec = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : vec)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " Index of " << (it - begin(a)) << endl;
            }
            else
            {
                cout << e << "not found" << endl;
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
        cout << *it << " even. Index is " << it - begin(a) << endl;
    }
    else
    {
        cout << *it << " not found\n";
    }
}
void p0202()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    auto it = find_if(begin(a), end(a), [](int n)
                      { return n % 2 == 0; });
    if (it != end(a))
    {
        cout << *it << " found. Index " << it - begin(a) << endl;
    }
    else
    {
        cout << *it << "not found\n";
    }
}

struct GreaterThan
{
    int mx;
    GreaterThan(int x) : mx(x){};
    bool operator()(int n) const
    {
        return n > mx;
    }
};

void p03()
{
    printf("Enter number x: ");
    int x;
    cin >> x;

    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    auto it = find_if(begin(a), end(a), GreaterThan(x));
    if (it != end(a))
    {
        cout << *it << " greater. Index is " << it - begin(a) << endl;
    }
    else
    {
        cout << "not found\n";
    }

    auto it2 = auIfFind(begin(a), end(a), [x](int n)
                        { return n > x; });
    if (it2 != end(a))
    {
        cout << *it << " greater. Index is " << it - begin(a) << endl;
    }
    else
    {
        cout << "not found\n";
    }
}

void p04()
{
    vector<int> x;
    for (int a; cin >> a;)
    {
        x.push_back(a);
    }

    // auto it = min_element(begin(x), end(x));
    // if (it != end(x))
    // {
    //     cout << "minimum element " << *it << endl;
    // }
    // else
    // {
    //     cout << "not found\n";
    // }

    auto it2 = auMinElement(begin(x), end(x));
    if (it2 != end(x))
    {
        cout << "minimum element " << *it2 << endl;
    }
    else
    {
        cout << "not found\n";
    }
}

void p05()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    auto minGpa = auMinElement(begin(students), end(students), [](const Student &s1, const Student &s2)
                               { return s1.mGpa < s2.mGpa; });
    if (minGpa != end(students))
    {
        cout << "Student with min Gpa " << minGpa->mName << " " << minGpa->mGpa << endl;
    }
    else
    {
        cout << "not found\n";
    }

    auto iterToMinName = auMinElement(begin(students), end(students), [](const Student &s1, Student &s2)
                                      { return s1.mName < s2.mName; });
    if (iterToMinName != end(students))
    {
        cout << "Min Name " << iterToMinName->mName << " " << iterToMinName->mGpa << endl;
    }
    else
    {
        cout << "not found \n";
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

    // sort by Name
    printf("- - - NAME - - -\n");

    cout << fixed << setprecision(2);
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &e : students)
    {
        cout << e.mName << ", " << e.mGpa << endl;
    }

    // sort by GPA
    printf("- - - GPA - - -\n");
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });

    for (const auto &e : students)
    {
        cout << e.mName << ", " << e.mGpa << endl;
    }
}

void p07()
{
    vector<Student> students = {
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0},
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0},
        {"StudentR", 4.0},
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0}};

    printf("- - - sort Name - - -\n");
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &e : students)
    {
        cout << e.mName << " " << e.mGpa << endl;
    }

    printf("- - - sort GPA - - -\n");

    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });

    cout << fixed << setprecision(2);

    for (const auto &e : students)
    {
        cout << e.mName << " " << e.mGpa << endl;
    }

    printf("- - - STABLE NAME - - -\n");
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mName < s2.mName; });
    for (const auto &e : students)
    {
        cout << e.mName << " " << e.mGpa << endl;
    }

    printf("- - - STABLE GPA - - -\n");
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mGpa > s2.mGpa; });
    cout << fixed << setprecision(2);

    for (const auto &e : students)
    {
        cout << e.mName << " " << e.mGpa << endl;
    }
}

int main()
{
    // p0101();
    // p0102();
    // p0201();
    // p0202();
    // p03();
    // p04();
    // p05();
    // p06();
    // p07();
}