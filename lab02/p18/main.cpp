#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int num; cin >> num && num != 0;)
    {
        int numOfCategories;
        cin >> numOfCategories;

        vector<int> courses(num);
        for (auto &course : courses)
        {
            cin >> course;
        }

        bool passed = true;

        for (int i = 0; i < numOfCategories; i++)
        {
            int courseInCategory;
            cin >> courseInCategory;
            int minReq;
            cin >> minReq;

            vector<int> categoryCourses(courseInCategory);
            for (auto &course : categoryCourses)
            {
                cin >> course;
            }

            sort(categoryCourses.begin(), categoryCourses.end());

            int numTaken = 0;
            for (auto course : courses)
            {
                numTaken += binary_search(categoryCourses.begin(), categoryCourses.end(), course);
            }

            if (numTaken < minReq)
            {
                passed = false;
            }
        }
        cout << (passed ? "yes\n" : "no\n");
    }
}