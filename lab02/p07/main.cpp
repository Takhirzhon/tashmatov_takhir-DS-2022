#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int num1, num2;

    while (cin >> num1 >> num2, num1 != -1)

    {
        if (num1 > num2)
        {
            swap(num1, num2);
        }

        cout << min(num2 - num1, num1 + 100 - num2) << "\n";
    }
}