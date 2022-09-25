#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int caseTest;
    cin >> caseTest;
    int f, s, t;

    for (int i = 1; i <= caseTest; i++)
    {
        cin >> f;
        cin >> s;
        cin >> t;

        printf("Case %d: ", i);

        if ((f > s && f < t) || (f > t && f < s))
        {
            printf("%d\n", f);
        }
        else if ((s > f && s < t) || (s < f && s > t))
        {
            printf("%d\n", s);
        }
        else
        {
            printf("%d\n", t);
        }
    }
}
