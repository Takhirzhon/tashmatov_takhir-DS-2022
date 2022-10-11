#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test;
    cin >> test;

    while (test--)
    {
        int sizeofArray;
        cin >> sizeofArray;

        vector<int> numOfSales(sizeofArray);

        for (int j = 0; j < sizeofArray; j++)
        {
            cin >> numOfSales[j];
        }

        int sum = 0;
        for (int k = 1; k < sizeofArray; k++)
        {
            for (int i = 0; i < k; i++)
            {
                if (numOfSales[i] <= numOfSales[k])
                {
                    sum++;
                }
            }
        }
        cout << sum << "\n";
    }
}