#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, pair<int, int>> P;

int main()
{
  int N;
  cin >> N;

  vector<P> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i].first >> v[i].second.first;
    v[i].second.second = i + 1;
    v[i].second.first *= -1;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++)
  {
    cout << v[i].second.second << endl;
  }
}