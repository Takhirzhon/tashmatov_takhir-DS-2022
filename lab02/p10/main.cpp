#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test;
    cin >> test;

    for (int i = 1; i <= test; i++)
    {

        int numOfWall;
        cin >> numOfWall; //считаю кол-во стен и
        int first;        //вводимое первое значени
        cin >> first;
        int low = 0, high = 0;

        while (--numOfWall != 0)
        { // буду инкементировать отталкиваясь от следующего вводимого числа
            int next;
            cin >> next;

            if (next > first)
                high++;
            else if (first > next)
                low++;

            first = next;
        }
        cout << "Case " << i << ": " << high << " " << low << "\n";
    }
}