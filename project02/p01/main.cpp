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
        }
        sort(array.begin(), array.end(), [&n, &m](int a, int b)
             {
            if (a % m < b % m)
            {
                return true;
            }

            else
            {
            if (abs(a) % 2 == 0 && (b) % 2 == 0)
            {
                return true;
            }
            
            else if (abs(a) % 2 == 1 && abs(b) % 2 == 1)
            {
                return a > b;
            }
            else if (abs(a) % 2 == 0 && abs(b) % 2 == 0)
            {
                return b > a;
            }
            else {
                return false;
            } } });

        cout << n << " " << m << endl;

        for (int x : array)
        {
            cout << x << endl;
        }
    }
}