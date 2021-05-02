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
#define sz(x) ((int)(x).size())
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

int main() {
  int N, a;
  cin >> N >> a;
  a--;
  string k;
  cin >> k;
  vector<int> b(N);
  rep(i, N) {
    cin >> b[i];
    b[i]--;
  }

  if (sz(k) <= 6) {
    int K = stoi(k);
    int temp = a;
    while (K-- > 0) {
      temp = b[temp];
    }
    cout << temp + 1 << endl;
    return 0;
  }

  map<int, int> m;
  int temp = a;
  int cutoff;
  int mod;
  rep(i, N + 1) {
    if (m.find(temp) == m.end()) {
      m[temp] = i;
      temp = b[temp];
    } else {
      cutoff = m[temp];
      mod = i - m[temp];
      break;
    }
  }
  
  rep(i, mod - (cutoff % mod)) {
    temp = b[temp];
  }

  int ope = 0;
  rep(i, sz(k)) {
    int num = k[i] - '0';
    ope = (ope * 10 + num) % mod;
  }

  rep(i, ope) {
    temp = b[temp];
  }

  cout << temp + 1 << endl;
}