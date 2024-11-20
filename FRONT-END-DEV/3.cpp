#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
    }
}

/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, y, d;
        cin >> x >> y >> d;

        int res = 0;

        if (x == y)
        {
            if (x%d==0) res += (x / d) * 2;
            else res+= (x/d + 1)*2;
        }
        else if (x > y)
        {
            if (x % d == 0)
                res += 2 * (x / d) - 1;
            else
                res += 2 * (x / d + 1) - 1;
        }
        else
        {
            if (y % d == 0)
                res += 2 * (y / d);
            else
                res += 2 * (y / d + 1);
        }
        cout << res << endl;
    }
}*/