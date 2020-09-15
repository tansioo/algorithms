#include <iostream>
#include <string>
using namespace std;

int main() {
    double m;
    cin >> m;

    //mをkmに変換
    m /= 1000;

    string vv;

    if (m < 0.1) vv = "00";
    else if (m < 1) vv = "0" + to_string((int)(m * 10));
    else if (m <= 5) vv = to_string((int)(m * 10));
    else if (m <= 30) vv = to_string((int)(m + 50));
    else if (m <= 70) vv = to_string((int)((m - 30) / 5 + 80));
    else vv = "89";

    cout << vv << endl;
    return 0;
}