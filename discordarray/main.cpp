#include <iostream>
#include <math.h>
using namespace std;
int x[1000001];
int a[1000001];

const int md = 1e9 + 7;

string F(string s, string t, char c) {
    if (c == '+') {
        if (t == "0") return s;
        string tmp = "S";
        return tmp + "(" + F(s, t.substr(2, (int)t.size() - 3), '+') + ")";
    }
    if (t == "0") return "0";
    return F(F(s, t.substr(2, (int)t.size() - 3), '.'), s, '+');
}
void sol() {
    string s, t;
    cin >> s >> t;
    int n = 0;
    for (char c : s)
        n += c == 'S';
    int m = 0;
    for (char c : t)
        m += c == 'S';
    for (int i = 1; i <= n * m; i++)
        cout << "S(";
    cout << 0;
    for (int i = 1; i <= n * m; i++)
        cout << ")";
}

void solve() {
    int T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        sol();
    }
}
int main(int argc,char *argv[]) {
    solve();
}
