#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> ones;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] == 1)
            {
                ones.push_back(i);
            }
        }

        int left = -1;
        int right = -1;
        int best = 0;

        if (ones.empty())
        {
            int first = -1;
            int last = -1;

            for (int i = 0; i < n; i++)
            {
                if (a[i] == -1)
                {
                    if (first == -1)
                    {
                        first = i;
                    }
                    last = i;
                }
            }

            if (first != -1)
            {
                left = first;
                right = last;
                best = right - left + 1;
            }
        }
        else
        {
            for (int i = 1; i < ones.size(); i++)
            {
                int length = ones[i] - ones[i - 1] + 1;

                if (length > best)
                {
                    best = length;
                    left = ones[i - 1];
                    right = ones[i];
                }
            }

            int first_one = ones[0];
            int last_one = ones[ones.size() - 1];

            for (int i = 0; i < first_one; i++)
            {
                if (a[i] == -1)
                {
                    int length = first_one - i + 1;

                    if (length > best)
                    {
                        best = length;
                        left = i;
                        right = first_one;
                    }

                    break;
                }
            }

            for (int i = n - 1; i > last_one; i--)
            {
                if (a[i] == -1)
                {
                    int length = i - last_one + 1;

                    if (length > best)
                    {
                        best = length;
                        left = last_one;
                        right = i;
                    }

                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                a[i] = 0;
            }
        }

        if (left != -1)
        {
            a[left] = 1;
            a[right] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}