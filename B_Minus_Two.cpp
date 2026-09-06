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

        int odd = 0;
        int even1 = 0;
        int even2 = 0;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;

            if (x % 2 == 1)
            {
                odd++;
            }
            else if ((x / 2) % 2 == 1)
            {
                even1++;
            }
            else
            {
                even2++;
            }
        }

        int answer = odd;

        if (even1 > answer)
        {
            answer = even1;
        }

        if (even2 > answer)
        {
            answer = even2;
        }

        cout << answer << endl;
    }

    return 0;
}