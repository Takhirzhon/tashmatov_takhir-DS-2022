#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    char letter;
    int count;
};

int main()
{

    int X;
    cin >> X;

    for (int i = 0; i < X; i++)
    {
        int R, C, M, N;
        cin >> R >> C >> M >> N;

        vector<Freq> frequency;
        for (int j = 0; j < 26; j++)
        {
            Freq eachFreq;
            eachFreq.letter = 'A' + j;
            eachFreq.count = 0;
            frequency.push_back(eachFreq);
        }

        for (int j = 0; j < R; j++)
        {
            string line;
            cin >> line;
            for (int k = 0; k < C; k++)
            {
                frequency[line[k] - 'A'].count++;
            }
        }

        sort(frequency.begin(), frequency.end(), [](Freq a, Freq b)
             { return a.count > b.count; });

        int size = 0;
        for (int j = 0; j < 26; j++)
        {
            size += frequency[j].count * ((j == 0) ? M : N);
        }

        cout << "Case " << i << ": " << size << endl;
    }

    return 0;
}