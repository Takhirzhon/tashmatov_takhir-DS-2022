#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    long long test, war;
    cin >> test;

    for (int i = 1; i <= test; i++)
    {
        cin >> war;

        int counter;
        counter = (sqrt(1 + 4 * 2 * war) - 1) / 2;

        cout << counter << "\n";
    }
}