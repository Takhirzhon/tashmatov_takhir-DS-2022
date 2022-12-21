#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int cases;
    vector<string> students;
    string name;

    while (cin >> cases)
    {
        cin.ignore();

        for (int i = 0; i < cases; ++i)
        {
            cin >> name;
            students.push_back(name);
        }

        stable_sort(students.begin(), students.end(), [](const string &s1, const string &s2)
                    {
            if(s1[0] != s2[0])
            {
                return s1[0] < s2[0];
            }
            else
            {
                return s1[1] < s2[1];
            } });

        for (auto &c : students)
        {
            cout << c << endl;
        }
        students.clear();
    }
}