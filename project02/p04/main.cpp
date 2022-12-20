#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string str;
    int inversions;
};

int main()
{
    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<SpecialString> strings;
        strings.reserve(m);
        for (int j = 0; j < m; j++)
        {
            SpecialString s;
            cin >> s.str;
            s.inversions = 0;
            for (int k = 0; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (s.str[k] > s.str[l])
                    {
                        s.inversions++;
                    }
                }
            }
            strings.push_back(s);
        }

        stable_sort(strings.begin(), strings.end(), [](const SpecialString &s1, const SpecialString &s2)
                    { return s1.inversions < s2.inversions; });

        for (const SpecialString &s : strings)
        {
            cout << s.str << '\n';
        }

        if (i < M - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}
