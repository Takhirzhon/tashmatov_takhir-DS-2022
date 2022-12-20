#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int m, n;
    string word;

    vector<pair<string, int>> points;
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; i++)
        {
            int dollar;
            cin >> word >> dollar;
            points.push_back({word, dollar});
        }

        int salary = 0;
        while (cin >> word, word != ".")
        {
            // Find the index of the pair object that contains the word
            int index = -1;
            for (int i = 0; i < sz(points); i++)
            {
                if (points[i].first == word)
                {
                    index = i;
                    break;
                }
            }

            // If the word is found, add its value to the salary
            if (index != -1)
            {
                salary += points[index].second;
            }
            cout << salary << endl;
        }
    }
}