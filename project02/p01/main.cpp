#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m)
    {
        vector<int> array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
            // cout << array[i] << "\n";
        }
        sort(
            array.begin(), array.end(), [&m](int a, int b)
            {
                // if(){}
            });
    }
}