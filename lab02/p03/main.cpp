#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test, row, column;

    cin >> test;

    while (test--)
    {

        cin >> row >> column;
        int counter;
        counter = (row / 3) * (column / 3);
        cout << counter << endl;
    }
}