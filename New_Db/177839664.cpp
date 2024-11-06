#include <iostream>
#include "vector"
#include "string"
#include "set"
#include "cmath"
#include "iomanip"
#include "algorithm"
#include "map"
#include "unordered_set"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
const ld PI = acos(-1);
void f() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
struct otr{
    pair<ll, ll> fir;
    pair<ll, ll> sec;
};
vector<otr> a(3);
bool ygl(){
    pair<ll, ll>q1 = {a[0].fir.first-a[0].sec.first, a[0].fir.second - a[0].sec.second};
    pair<ll, ll>q2 = {a[1].fir.first-a[1].sec.first, a[1].fir.second - a[1].sec.second};
    ld vec = q1.first*q2.second-q1.second*q2.first;
    ld skal = q1.first*q2.first+q1.second*q2.second;
    ld yg = atan2(vec, skal);
    return (skal >= 0 || abs(skal) < 1E-20);
}
bool prin(pair<ll, ll>q, otr t) {
    ld aa = t.fir.second - t.sec.second;
    ld bb = t.sec.first-t.fir.first;
    ld cc = -(aa*t.fir.first+bb*t.fir.second);
    ld qqq = aa*q.first+bb*q.second+cc;
    return (abs(qqq) < 1E-20 && q.first >= min(t.fir.first, t.sec.first) && q.first <= max(t.fir.first, t.sec.first));
}
void proverka() {
    if (!ygl()) {
        cout << "NO" << "\n";
        return;
    }
    if ((prin(a[2].fir, a[0]) && prin(a[2].sec, a[1])) || (prin(a[2].sec, a[0]) && prin(a[2].fir, a[1]))) {
        if ((prin(a[2].fir, a[0]) && prin(a[2].sec, a[1]))) {
            ld r1, r2, r3, r4;
            r1 = (a[0].fir.first-a[2].fir.first)*(a[0].fir.first-a[2].fir.first) + (a[0].fir.second-a[2].fir.second)*(a[0].fir.second-a[2].fir.second);
            r2 = (a[0].sec.first-a[2].fir.first)*(a[0].sec.first-a[2].fir.first) + (a[0].sec.second-a[2].fir.second)*(a[0].sec.second-a[2].fir.second);
            r3 = (a[1].fir.first-a[2].sec.first)*(a[1].fir.first-a[2].sec.first) + (a[1].fir.second-a[2].sec.second)*(a[1].fir.second-a[2].sec.second);
            r4 = (a[1].sec.first-a[2].sec.first)*(a[1].sec.first-a[2].sec.first) + (a[1].sec.second-a[2].sec.second)*(a[1].sec.second-a[2].sec.second);
            if (min(r1, r2)*16 >= max(r1, r2) && min(r3, r4)*16 >= max(r3, r4)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        else {
            ld r1, r2, r3, r4;
            r1 = (a[0].fir.first-a[2].sec.first)*(a[0].fir.first-a[2].sec.first) + (a[0].fir.second-a[2].sec.second)*(a[0].fir.second-a[2].sec.second);
            r2 = (a[0].sec.first-a[2].sec.first)*(a[0].sec.first-a[2].sec.first) + (a[0].sec.second-a[2].sec.second)*(a[0].sec.second-a[2].sec.second);
            r3 = (a[1].fir.first-a[2].fir.first)*(a[1].fir.first-a[2].fir.first) + (a[1].fir.second-a[2].fir.second)*(a[1].fir.second-a[2].fir.second);
            r4 = (a[1].sec.first-a[2].fir.first)*(a[1].sec.first-a[2].fir.first) + (a[1].sec.second-a[2].fir.second)*(a[1].sec.second-a[2].fir.second);
            if (min(r1, r2)*16 >= max(r1, r2) && min(r3, r4)*16 >= max(r3, r4)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
    else {
        cout << "NO" << "\n";
        return;
    }
}
int main() {
    f();
    ll t;
    cin >> t;
    while (t--) {
        for (ll i = 0; i < 3; ++i) {
            cin >> a[i].fir.first >> a[i].fir.second >> a[i].sec.first >> a[i].sec.second;
        }
        if (a[0].fir == a[1].fir) {
            proverka();
        }
        else if (a[0].fir == a[1].sec) {
            swap(a[1].sec, a[1].fir);
            proverka();
        }
        else if (a[0].fir == a[2].fir) {
            swap(a[1], a[2]);
            proverka();
        }
        else if (a[0].fir == a[2].sec) {
            swap(a[2].sec, a[2].fir);
            swap(a[1], a[2]);
            proverka();
        }
        else if (a[0].sec == a[1].fir) {
            swap(a[0].fir, a[0].sec);
            proverka();
        }
        else if (a[0].sec == a[1].sec) {
            swap(a[0].fir, a[0].sec);
            swap(a[1].fir, a[1].sec);
            proverka();
        }
        else if (a[0].sec == a[2].fir) {
            swap(a[0].fir, a[0].sec);
            swap(a[2], a[1]);
            proverka();
        }
        else if (a[0].sec == a[2].sec) {
            swap(a[0].fir, a[0].sec);
            swap(a[2].fir, a[2].sec);
            swap(a[1], a[2]);
            proverka();
        }
        else if (a[1].fir == a[2].fir) {
            swap(a[2], a[0]);
            proverka();
        }
        else if (a[1].fir == a[2].sec) {
            swap(a[2].fir, a[2].sec);
            swap(a[2], a[0]);
            proverka();
        }
        else if (a[1].sec == a[2].fir) {
            swap(a[1].sec, a[1].fir);
            swap(a[2], a[0]);
            proverka();
        }
        else if (a[1].sec == a[2].sec) {
            swap(a[1].sec, a[1].fir);
            swap(a[2].sec, a[2].fir);
            swap(a[2], a[0]);
            proverka();
        }
        else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}