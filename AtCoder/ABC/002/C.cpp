#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double ans = abs((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc)) / 2;

    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}