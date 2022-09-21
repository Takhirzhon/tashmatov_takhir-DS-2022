#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(int a, int b)
{
    if (a > b)
    {
        swap(a, b);
    }

    int count = 0;
    for (int i = a; i <= b; i++)
    {
        int curr = i;
        int length = 1;
        while (curr != 1)
        {
            length++;
            curr = curr % 2 == 0 ? curr / 2 : curr * 3 + 1;
        }
        count = max(length, count);
    }

    return count;
}

int main()
{
    iostream::sync_with_stdio(false);

    for (int a, b; cin >> a >> b;)
    {
        cout << a << " " << b << " " << solve(a, b) << "\n";
    }
}