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
        long long k;
        cin >> n >> k;

        vector<long long>
            a(n),
            c(n),
            pref(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            c[i] = a[i] - 1LL * i * k;
            pref[i + 1] = pref[i] + c[i];
        }

        vector<long long> neg(n);

        for (int i = 0; i < n; i++)
        {
            neg[i] = -c[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << 0 << " ";
                continue;
            }

            long long target = c[i - 1] - k;

            int r = lower_bound(neg.begin() + i + 1, neg.end(), -target) - neg.begin();

            long long cnt = r - i - 1;

            long long answer = pref[r] - pref[i + 1] - cnt * c[i - 1] + cnt * k;

            cout << answer << " ";
        }

        cout << endl;
    }

    return 0;
}