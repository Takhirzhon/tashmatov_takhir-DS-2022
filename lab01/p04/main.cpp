#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (string line; getline(cin, line);)
    {
        string buff;
        for (auto c : line)
        {
            if (isalpha(c))
            {
                buff += tolower(c);
            }
        }

        string copy = buff;
        reverse(copy.begin(), copy.end());

        cout << (copy == buff ? "Palindrome\n" : "Not a Palindrome\n");
    }
}