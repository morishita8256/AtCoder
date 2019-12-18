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

template <typename T>
struct Compress {
  vector<T> xs;
  Compress() = default;
  Compress(const vector<T>& vs) {
    add(vs);
  }
  Compress(const initializer_list<vector<T>>& vs) {
    for (auto& p : vs)
      add(p);
  }
  void add(const vector<T>& vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }
  void add(const T& x) {
    xs.emplace_back(x);
  }
  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }
  vector<int> get(const vector<T>& vs) const {
    vector<int> ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T& x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }
  int get(const T& x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }
  const T& operator[](int k) const {
    return xs[k];
  }
};

int main() {
  int N;
  cin >> N;
  vector<int> R(N), H(N);
  rep(i, N) {
    cin >> R[i] >> H[i];
    H[i]--;
  }

  Compress<int> C(R);
  C.build();
  R = C.get(R);

  int Rmax = 0;
  rep(i, N) {
    chmax(Rmax, R[i]);
  }

  vector<int> rate(Rmax + 1);
  rep(i, N) {
    rate[R[i]]++;
  }

  vector<int> LL(Rmax + 2);
  rep(i, Rmax + 1) {
    LL[i + 1] = LL[i] + rate[i];
  }

  vector<int> RR(Rmax + 2);
  repr(i, Rmax + 1, 1) {
    RR[i - 1] = RR[i] + rate[i - 1];
  }

  vector<vector<int>> hand(Rmax + 1, vector<int>(3));
  rep(i, N) {
    hand[R[i]][H[i]]++;
  }

  // rep(i, sz(LL)) {
  //   cout << LL[i] << ((i == sz(LL) - 1) ? "\n" : " ");
  // }
  // rep(i, sz(RR)) {
  //   cout << RR[i] << ((i == sz(RR) - 1) ? "\n" : " ");
  // }
  // rep(i, sz(hand)) {
  //   rep(j, sz(hand[i])) {
  //     cout << hand[i][j];

  //     cout << (j == sz(hand[i]) - 1 ? "\n" : " ");
  //   }
  // }

  rep(i, N) {
    int Rnow = R[i];
    int Hnow = H[i];
    int win = LL[Rnow] + hand[Rnow][(Hnow + 1) % 3];
    int lose = RR[Rnow + 1] + hand[Rnow][(Hnow + 2) % 3];
    int even = hand[Rnow][Hnow] - 1;
    cout << win << ' ' << lose << ' ' << even << endl;
  }
}