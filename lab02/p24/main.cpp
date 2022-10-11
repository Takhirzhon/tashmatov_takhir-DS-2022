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
        int arrayNum;
        cin >> arrayNum;
        vector<int> array(arrayNum);
        long long sum = 0;

        for (int i = 0; i < arrayNum; i++)
            cin >> array[i];
        sort(array.begin(), array.end());

        int relatives = 0;

        if (arrayNum % 2)
        {
            relatives = array[arrayNum / 2];
        }
        else
            relatives = (array[(arrayNum / 2) - 1] + array[arrayNum / 2]) / 2;

        for (int i = 0; i < arrayNum; i++)
            sum += abs(array[i] - relatives);
        cout << sum << "\n";
    }
}
