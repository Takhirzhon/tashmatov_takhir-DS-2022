#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int test;
    cin >> test;

    for (int i = 0; i < test; ++i)
    {
        vector<pair<string, string>> v;
        int n;
        cin >> n;

        for (int j = 0; j < n; ++j)
        {
            string name;
            cin >> name;
            name = name.substr(0, name.length() - 1);
            string class_name;
            cin >> class_name;
            string throw_away;
            cin >> throw_away;

            string class_value = "";
            istringstream ss(class_name);
            string role;
            while (getline(ss, role, '-'))
            {
                if (role == "upper")
                {
                    class_value += '3';
                }
                else if (role == "middle")
                {
                    class_value += '2';
                }
                else if (role == "lower")
                {
                    class_value += '1';
                }
            }
            reverse(class_value.begin(), class_value.end());
            while (class_value.length() < 10)
            {
                class_value += '2';
            }

            v.emplace_back(name, class_value);
        }

        stable_sort(v.begin(), v.end(),
                    [](const pair<string, string> &a, const pair<string, string> &b)
                    {
                        if (a.second != b.second)
                        {
                            return a.second > b.second;
                        }
                        else
                        {
                            return a.first < b.first;
                        }
                    });

        for (const auto &p : v)
        {
            const auto &name = p.first;
            cout << name << endl;
        }
        cout << "==============================" << endl;
    }
}
