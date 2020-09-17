#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double deg, dis;
    cin >> deg >> dis;

    //本来の角度を求めるために10で割る
    deg /= 10;
    //風速を求めるために60秒で割り、少数第二位を四捨五入する
    dis /= 60;
    dis = round(dis * 10) / 10;

    //ans
    string dir;
    int w;

    if (11.25 <= deg && deg < 33.75) dir = "NNE";
    else if (33.75 <= deg && deg < 56.25) dir = "NE";
    else if (56.25 <= deg && deg < 78.75) dir = "ENE";
    else if (78.75 <= deg && deg < 101.25) dir = "E";
    else if (101.25 <= deg && deg < 123.75) dir = "ESE";
    else if (123.75 <= deg && deg < 146.25) dir = "SE";
    else if (146.25 <= deg && deg < 168.75) dir = "SSE";
    else if (168.75 <= deg && deg < 191.25) dir = "S";
    else if (191.25 <= deg && deg < 213.75) dir = "SSW";
    else if (213.75 <= deg && deg < 236.25) dir = "SW";
    else if (236.25 <= deg && deg < 258.75) dir = "WSW";
    else if (258.75 <= deg && deg < 281.25) dir = "W";
    else if (281.25 <= deg && deg < 303.75) dir = "WNW";
    else if (303.75 <= deg && deg < 326.25) dir = "NW";
    else if (326.25 <= deg && deg < 348.75) dir = "NNW";
    else dir = "N";

    if (0.0 <= dis && dis <= 0.2) {
        w = 0;
        dir = "C";
    }
    else if (0.3 <= dis && dis <= 1.5) w = 1;
    else if (1.6 <= dis && dis <= 3.3) w = 2;
    else if (3.4 <= dis && dis <= 5.4) w = 3;
    else if (5.5 <= dis && dis <= 7.9) w = 4;
    else if (8.0 <= dis && dis <= 10.7) w = 5;
    else if (10.8 <= dis && dis <= 13.8) w = 6;
    else if (13.9 <= dis && dis <= 17.1) w = 7;
    else if (17.2 <= dis && dis <= 20.7) w = 8;
    else if (20.8 <= dis && dis <= 24.4) w = 9;
    else if (24.5 <= dis && dis <= 28.4) w = 10;
    else if (28.5 <= dis && dis <= 32.6) w = 11;
    else if (32.7 <= dis) w = 12;

    cout << dir << " " << w << endl;
    return 0;
}