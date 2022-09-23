#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    long long test;
    long long num;
    long long res;

    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> num;

        for (int j = 0; j < test; j++)
        {
            res = abs(((num * 567 / 9) + 7492) * 235 / 47 - 498) / 10 % 10;
        }
        cout << res << "\n";
    }
}