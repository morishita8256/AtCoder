#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            sum += a.at(N - 1 - i);
        else
            sum -= a.at(N - 1 - i);
    }
    cout << sum << endl;
}
