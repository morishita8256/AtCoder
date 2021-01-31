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
// 実数
using Real = double;

// 点を複素表示
// real(.), imag(.), norm(.)...2乗ノルム
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

// Realの等価判定
inline bool eq(Real a, Real b) {
  return fabs(b - a) < EPS;
}

// Point * Real
Point operator*(const Point& p, const Real& d) {
  return Point(real(p) * d, imag(p) * d);
}

// Point の Cin
istream& operator>>(istream& is, Point& p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}

// Point の Cout
ostream& operator<<(ostream& os, Point& p) {
  return os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

// 点 p を反時計回りに theta 回転
Point rotate(Real theta, const Point& p) {
  return Point(cos(theta) * p.real() - sin(theta) * p.imag(),
               sin(theta) * p.real() + cos(theta) * p.imag());
}

// ラジアン -> 度
Real radian_to_degree(Real r) {
  return (r * 180.0 / PI);
}

// 度 -> ラジアン
Real degree_to_radian(Real d) {
  return (d * PI / 180.0);
}

// a-b-c の角度のうち小さい方を返す
Real get_angle(const Point& a, const Point& b, const Point& c) {
  const Point v(b - a), w(c - b);
  Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
  if (alpha > beta)
    swap(alpha, beta);
  Real theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}


namespace std {
// 点の大小（実部優先。等しければ虚部を比較。）
bool operator<(const Point& a, const Point& b) {
  return !eq(a.real(), b.real()) ? a.real() < b.real() : a.imag() < b.imag();
}
}  // namespace std


// 直線
// 通る2点a, b, 方向ベクトル（点）dir
struct Line {
  Point a, b, dir;

  Line() = default;

  // 通る2点で初期化
  Line(Point a, Point b) : a(a), b(b) {
    dir = a - b;
  }

  // 式 Ax + By = C の係数で初期化
  Line(Real A, Real B, Real C) {
    if (eq(A, 0))
      a = Point(0, C / B), b = Point(1, C / B);
    else if (eq(B, 0))
      b = Point(C / A, 0), b = Point(C / A, 1);
    else
      a = Point(0, C / B), b = Point(C / A, 0);
    dir = a - b;
  }

  // Cout
  friend ostream& operator<<(ostream& os, Line& p) {
    return os << p.a << " to " << p.b;
  }

  // Cin
  friend istream& operator>>(istream& is, Line& a) {
    return is >> a.a >> a.b;
  }
};

// 線分
// 通る2点a, b
struct Segment : Line {
  Segment() = default;

  Segment(Point a, Point b) : Line(a, b) {
  }
};

// 円
// 中心点p, 半径r
struct Circle {
  Point p;
  Real r;

  Circle() = default;

  // （中心点, 半径）で初期化
  Circle(Point p, Real r) : p(p), r(r) {
  }
};

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

// 外積 a×b
Real cross(const Point& a, const Point& b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

// 内積 a・b
Real dot(const Point& a, const Point& b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C&lang=ja
// 点の回転方向
int ccw(const Point& a, Point b, Point c) {
  b = b - a, c = c - a;
  if (cross(b, c) > EPS)
    return +1;  // "COUNTER_CLOCKWISE"
  if (cross(b, c) < -EPS)
    return -1;  // "CLOCKWISE"
  if (dot(b, c) < 0)
    return +2;  // "ONLINE_BACK"
  if (norm(b) < norm(c))
    return -2;  // "ONLINE_FRONT"
  return 0;     // "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A&lang=ja
// 平行判定。方向ベクトルの外積が0。
bool parallel(const Line& a, const Line& b) {
  return eq(cross(a.dir, b.dir), 0.0);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A&lang=ja
// 垂直判定。方向ベクトルの内積が0。
bool orthogonal(const Line& a, const Line& b) {
  return eq(dot(a.dir, b.dir), 0.0);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A&lang=ja
// 射影
// 直線 l に p から垂線を引いた交点を求める
Point projection(const Line& l, const Point& p) {
  double t = dot(p - l.a, l.dir) / norm(l.dir);
  return l.a + (l.dir) * t;
}

Point projection(const Segment& l, const Point& p) {
  double t = dot(p - l.a, l.dir) / norm(l.dir);
  return l.a + (l.dir) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B&lang=ja
// 反射
// 直線 l を対称軸として点 p  と線対称にある点を求める
Point reflection(const Line& l, const Point& p) {
  return p + (projection(l, p) - p) * 2.0;
}

// 点pが直線lに乗っているか
bool intersect(const Line& l, const Point& p) {
  return abs(ccw(l.a, l.b, p)) != 1;
}

// 直線l, mが交差するか
bool intersect(const Line& l, const Line& m) {
  return abs(cross(l.dir, m.dir)) > EPS || abs(cross(l.dir, m.b - l.a)) < EPS;
}

// 点pが線分sに乗っているか
bool intersect(const Segment& s, const Point& p) {
  return ccw(s.a, s.b, p) == 0;
}

// 直線lと線分sが交差するか
bool intersect(const Line& l, const Segment& s) {
  return cross(l.dir, s.a - l.a) * cross(l.dir, s.b - l.a) < EPS;
}

Real distance(const Line& l, const Point& p);

// 円cと直線lが交差するか
bool intersect(const Circle& c, const Line& l) {
  return distance(l, c.p) <= c.r + EPS;
}

// 円cが点pを通るか
bool intersect(const Circle& c, const Point& p) {
  return abs(abs(p - c.p) - c.r) < EPS;
}

// 線分s, tが交差するか
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=ja
bool intersect(const Segment& s, const Segment& t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
         ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}


// 円cと線分lの交点の数
int intersect(const Circle& c, const Segment& l) {
  if (norm(projection(l, c.p) - c.p) - c.r * c.r > EPS)
    return 0;
  auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
  if (d1 < c.r + EPS && d2 < c.r + EPS)
    return 0;
  if ((d1 < c.r - EPS && d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS))
    return 1;
  const Point h = projection(l, c.p);
  if (dot(l.a - h, l.b - h) < 0)
    return 2;
  return 0;
}

// 円c1, c2が交差するか（共通接線の数）
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp&lang=ja
// 4:離れている, 3:外接, 2:交わる, 1:内接, 0:内包
int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r)
    swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d)
    return 4;
  if (eq(c1.r + c2.r, d))
    return 3;
  if (c1.r - c2.r < d)
    return 2;
  if (eq(c1.r - c2.r, d))
    return 1;
  return 0;
}

// 2点a,bの距離
Real distance(const Point& a, const Point& b) {
  return abs(a - b);
}

// 直線lと点pの距離
Real distance(const Line& l, const Point& p) {
  return abs(p - projection(l, p));
}

// 2直線l, mの距離（交わるなら0）
Real distance(const Line& l, const Line& m) {
  return intersect(l, m) ? 0 : distance(l, m.a);
}

// 線分s上の点と点pの最短距離
Real distance(const Segment& s, const Point& p) {
  Point r = projection(s, p);
  if (intersect(s, r))
    return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}

// 線分a上の点と線分b上の点の最短距離
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D&lang=ja
Real distance(const Segment& a, const Segment& b) {
  if (intersect(a, b))
    return 0;
  return min(
      {distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

// 直線lと線分sの最短距離
Real distance(const Line& l, const Segment& s) {
  if (intersect(l, s))
    return 0;
  return min(distance(l, s.a), distance(l, s.b));
}

// 直線l, mの交点
Point crosspoint(const Line& l, const Line& m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if (eq(abs(A), 0.0) && eq(abs(B), 0.0))
    return m.a;
  return m.a + (m.b - m.a) * B / A;
}

// 線分l, mの交点
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=ja
Point crosspoint(const Segment& l, const Segment& m) {
  return crosspoint(Line(l), Line(m));
}

// 円cと直線lの交点（必ず交わることを仮定）
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=ja
pair<Point, Point> crosspoint(const Circle& c, const Line l) {
  Point pr = projection(l, c.p);
  Point e = (l.b - l.a) / abs(l.b - l.a);
  if (eq(distance(l, c.p), c.r))
    return {pr, pr};
  double base = sqrt(c.r * c.r - norm(pr - c.p));
  return {pr - e * base, pr + e * base};
}

// 円cと線分lの交点（必ず交わることを仮定）
pair<Point, Point> crosspoint(const Circle& c, const Segment& l) {
  Line aa = Line(l.a, l.b);
  if (intersect(c, l) == 2)
    return crosspoint(c, aa);
  auto ret = crosspoint(c, aa);
  if (dot(l.a - ret.first, l.b - ret.first) < 0)
    ret.second = ret.first;
  else
    ret.first = ret.second;
  return ret;
}

// 円c1, c2の交点
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=ja
pair<Point, Point> crosspoint(const Circle& c1, const Circle& c2) {
  Real d = abs(c1.p - c2.p);
  Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return {p1, p2};
}

double find_min(double l, double r, bool f(double)) {
  double c;
  while (abs(r - l) > EPS) {
    c = (r + l) / 2.0;
    if (f(c)) {
      r = c;
    } else {
      l = c;
    }
  }

  return r;
}


int N;
Points p;


bool f(double r) {
  Points cross;
  repp(i, 0, N - 1) {
    repp(j, i + 1, N - 1) {
      if (distance(p[i], p[j]) > 2 * r + EPS)
        return false;

      auto temp = crosspoint(Circle(p[i], r), Circle(p[j], r));
      cross.pb(temp.fi);
      cross.pb(temp.se);
    }
  }

  for (Point temp : cross) {
    bool ok = true;
    rep(i, N) {
      if (distance(temp, p[i]) > r + EPS)
        ok = false;
    }
    if (ok)
      return true;
  }
  return false;
}


int main() {
  cin >> N;

  p = Points(N);

  rep(i, N) {
    cin >> p[i];
  }

  printf("%.14f\n", find_min(EPS, 100000, f));  // Lf?
}