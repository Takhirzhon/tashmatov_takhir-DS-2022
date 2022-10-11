#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string str;
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        getline(cin, str);
        int i = 0;
        int contain1 = 0;
        int contain2 = 0;

        while (str[i] != '\0')
        {
            if (str[i] == 'F')
                contain1++;
            else if (str[i] == 'M')
                contain2++;
            i++;
        }
        if (contain2 == contain1 && contain1 + contain2 >= 4)
            cout << "LOOP" << endl;
        else
            cout << "NO LOOP" << endl;
    }
    return 0;
}
