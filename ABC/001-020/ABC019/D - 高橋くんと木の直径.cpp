#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((ll)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int ask(int a, int b) {
  a++, b++;
  int dist;
  cout << "? " << a << " " << b << endl;
  cin >> dist;
  return dist;
}

void answer(int d) {
  cout << "! " << d << endl;
}

int main() {
  int N;
  cin >> N;

  int s;
  int max_dist = 0;
  repp(i, 1, N - 1) {
    int temp = ask(0, i);
    if (chmax(max_dist, temp))
      s = i;
  }

  rep(i, N) {
    if (i == s)
      continue;
    chmax(max_dist, ask(s, i));
  }

  answer(max_dist);
}