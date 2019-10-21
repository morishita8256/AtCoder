#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s.at(i);
    }

    cin >> M;
    vector<string> t(M);
    for (int i = 0; i < M; i++)
    {
        cin >> t.at(i);
    }

    int benefit = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        string test = s.at(i);
        for (int j = 0; j < N; j++)
        {
            if (test == s.at(j))
                sum++;
        }
        for (int j = 0; j < M; j++)
        {
            if (test == t.at(j))
                sum--;
        }
        benefit = max(benefit, sum);
    }
    cout << benefit << endl;
}
