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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int farms = n / k;
        int answer = 0;

        for (int i = 0; i < farms; i++)
        {
            int found = 0;

            for (int j = i * k; j < (i + 1) * k; j++)
            {
                if (s[j] == '0')
                {
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                answer++;
            }
        }

        cout << answer << endl;
    }

    return 0;
}