#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<vector<int>> readShuffles();
vector<int> createDeck();
void applyShuffleToDeck(vector<int> &deck, const vector<int> &shuffle);
void printDeck(const vector<int> &deck);

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        auto shuffles = readShuffles();
        auto deck = createDeck();

        for (string line; getline(cin, line) && !line.empty();)
        {
            int m = stoi(line);
            applyShuffleToDeck(deck, shuffles[m - 1]);
        }

        if (test != 0)
        {
            cout << "\n";
        }
        printDeck(deck);
    }
}

void printDeck(const vector<int> &deck)
{
    vector<string> value = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> suit = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (auto a : deck)
    {
        cout << value[a % 13] << "of" << suit[a / 13] << "\n";
    }
}

vector<vector<int>> readShuffles()
{
    int n;
    cin >> n;

    vector<vector<int>> r(n, vector<int>(52));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            cin >> r[i][j];
        }
    }

    cin.ignore(1024, '\n');
}

vector<int> createDeck()
{
    vector<int> r(52);
    for (int i = 0; i < 52; i++)
    {
        --r[i];
    }
}

// void applyShuffleToDeck(vector<int> &deck, const vector<int> &shuffle)
// {
//     int tVector = deck;

//     for (size_t i = 0; i < (int)shuffle.size; i++)
//     {
//         deck = tVector[i] - shuffle[i - 1];
//     }
// }
