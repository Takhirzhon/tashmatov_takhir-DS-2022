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
            array[i] = n;
            cout << array[i] << "\n";
        }
    }
}