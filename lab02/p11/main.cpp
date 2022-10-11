#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

// int sumOfDigit(int)
int main()
{
    iostream::sync_with_stdio(false);

    vector<string> name(3);
    string word;

    for (decltype(name.size()) i = 1; i <= name.size(); i++)
    {
        cin >> word;
        name[i] = word;
        cout << name[i] << endl;
    }
}