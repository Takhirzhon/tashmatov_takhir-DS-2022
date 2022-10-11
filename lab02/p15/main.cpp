#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<string> webpage;
    int test;
    cin >> test;

    for (int i = 1; i <= test; i++)
    {
        int max = -1;
        for (int j = 0; j < 10; j++)
        {
            string inpURL;
            cin >> inpURL;
            int relevance;
            cin >> relevance;

            if (relevance > max)
            {
                webpage.clear();
                webpage.push_back(inpURL);
                max = relevance;
            }
            else if (relevance == max)
            {
                webpage.push_back(inpURL);
            }
        }

        cout << "Case #" << i << ":" << endl;
        for (string URL : webpage)
        {
            cout << URL << "\n";
        }
    }
}
