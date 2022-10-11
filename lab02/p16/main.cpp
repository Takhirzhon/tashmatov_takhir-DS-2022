#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    vector<string> people;
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        string name;
        cin >> name;
        people.push_back(name);
    }

    for (int i = 1, k = 0; i <= 2; i++)
    {
        for (int j = 0; j < 16; j++, k++)
        {
            if (k == num)
            {
                k -= num;
            }
            cout << people[k] << ": " << song[j] << endl;
        }
    }
}