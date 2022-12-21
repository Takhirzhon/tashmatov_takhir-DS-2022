#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int num;
    cin >> num;

    vector<pair<int, string>> cups;

    cups.resize(num);

    for (int i = 0; i < num; ++i)
    {
        string raduis;
        string diametr;

        cin >> raduis >> diametr;

        int a;
        if (isdigit(raduis[0]))
        {
            a = stoi(raduis);
            a /= 2;
            cups.push_back(make_pair(a, diametr));
        }
        else
        {
            a = stoi(diametr);
            cups.push_back(make_pair(a, raduis));
        }
    }

    sort(cups.begin(), cups.end(), [](const pair<int, string> &l, const pair<int, string> &r)
         { return l.first > r.first; });

    for (int i = num - 1; i >= 0; i--)
    {
        cout << cups[i].second << endl;
    }
}