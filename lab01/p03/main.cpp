#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    for (string name; cin >> name;)
    {
        int nGrades = 0;
        double sum = 0;
        for (int grade; cin >> grade;)
        {
            ++nGrades;
            sum += grade;
        }

        cout << setfill('.') << fixed << setprecision(2);
        if (nGrades != 0)
        {
            cout << left << setw(30) << name << "|" << right << setw(30) << sum / nGrades << "\n";
        }
        else
        {
            cout << left << setw(30) << name << "|" << right << setw(30) << "no data\n";
        }
        cin.clear();
    }
}