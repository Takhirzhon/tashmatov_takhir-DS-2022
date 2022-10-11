#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    char inputKey[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int leng = strlen(inputKey);

    for (string s; getline(cin, s);)
    {
        for (int i = 0; i < int(s.length()); i++)
        {
            if (s[i] == ' ')
                cout << " ";

            else
            {
                char ch = tolower(s[i]);

                for (int j = 0; j < leng; j++)
                {
                    if (ch == inputKey[j])
                    {
                        cout << inputKey[j - 2];
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}
