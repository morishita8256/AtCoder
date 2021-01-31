#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e+10;

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  vector<ll> v(N);
  fill(v.begin(), v.end(), INF);
  for (int i = N - 1; i >= 0; i--) {
    *lower_bound(v.begin(), v.end(), A.at(i) + 1) = A.at(i);
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (v.at(i) < INF)
      ans++;
    else
      break;
  }
  cout << ans << endl;
}