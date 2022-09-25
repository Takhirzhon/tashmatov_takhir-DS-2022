#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test, num;
    int store;

    cin >> test;

    while (test--)
    {
        cin >> store;

        int max = 99;
        int min = 0;

        for (int i = 0; i < store; i++)
        {
            cin >> num;

            if (num > min)
                min = num;
            if (num < max)
                max = num;
        }

        cout << ((min - max) * 2) << "\n";
    }
}