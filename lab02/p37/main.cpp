#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    char string1[102];
    char string2[102];

    while (cin >> string1 >> string2)
    {
        bool check = true;
        int alphabet1[26] = {0};
        int alphabet2[26] = {0};

        for (int i = 0; i < int(strlen(string1)); i++)
        {
            alphabet1[string1[i] - 'A']++;
            alphabet2[string2[i] - 'A']++;
        }

        sort(alphabet1, alphabet1 + 26);
        sort(alphabet2, alphabet2 + 26);

        for (int i = 0; i < 26; i++)
        {
            if (alphabet1[i] != alphabet2[i])
            {
                check = false;
                break;
            }
        }

        if (check == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}