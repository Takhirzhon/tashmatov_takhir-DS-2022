#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int road, num, i = 1;
    cin >> road >> num;

    while (road != 0 && num != 0)
    {
        int count = 0;
        if (road - num * 27 > 0)
        {
            printf("Case %d: impossible\n", i++);
            cin >> road >> num;

            continue;
        }
        while (road > 0)
        {
            road -= num;
            count++;
        }
        printf("Case %d: %d\n", i++, count - 1);
        cin >> road >> num;
    }
}