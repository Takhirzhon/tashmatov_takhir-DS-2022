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
                else if (a % m > b % m) {
                    return false;
                }

                if (a % 2 == 1 && b % 2 == 0) {
                    return true;
                } 
                 else if (a % 2 == 0 && b % 2 == 1) {
                        return false;
                 } 
                if ( a % 2== 1 && b % 2 == 1)
                {
                    return a > b;}
                if ( a % 2 == 0 && b % 2 == 0) {
                return b > a;
                } });
    }
}