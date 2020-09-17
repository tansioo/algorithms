// WA

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string rain_time[30030];

    cin >> n;
    for (int i = 0; i < n; i++) { 
        string time;
        cin >> time;

        // 降り始めと降り終わりに分割
        // 位置 : 012345678
        // 時間 : XXXX-XXXX
        string start_time = time.substr(0, 4);
        string end_time = time.substr(5, 4);

        // 1文字ずつ:start
        string start_first_num = start_time.substr(3, 1);
        // 1文字ずつ:end
        string end_first_num = end_time.substr(3, 1);
        string end_second_num = end_time.substr(2, 1);
        string end_third_num = end_time.substr(1, 1);
        string end_fourth_num = end_time.substr(0, 1);

        // 降り始めの丸め
        if (stoi(start_first_num) <= 4) start_first_num = "0";
        else start_first_num = "5";
        start_time = start_time.substr(0, 3) + start_first_num;

        // 降り終わりの丸め
        if (1 <= stoi(end_first_num) && stoi(end_first_num) <= 4) end_first_num = "5";
        else if (6 <= stoi(end_first_num) && stoi(end_first_num) <= 9) {
            end_first_num = "0";

            if (stoi(end_second_num) <= 4) {
                end_second_num = to_string(stoi(end_second_num) + 1);
            }
            else { // 5以上
                end_second_num = "0";

                // 23時
                if (stoi(end_fourth_num) == 2 && stoi(end_third_num) <= 3) {
                    end_third_num = "0";
                    end_fourth_num = "0";
                }
                else if (stoi(end_third_num) <= 8) {
                    end_third_num = to_string(stoi(end_third_num) + 1);
                }
                else {
                    end_third_num = "0";
                    end_fourth_num = to_string(stoi(end_fourth_num) + 1);
                }
            }
        }
        end_time = end_fourth_num + end_third_num + end_second_num + end_first_num;

        rain_time[i] = start_time + "-" + end_time;
    }

    // 昇順に並べ替え
    sort(rain_time, rain_time + n);

    vector<string> ans;

    string s_time = rain_time[0].substr(0, 4);
    string e_time;
    for (int i = 0; i < n - 1; i++) {
        e_time = max(e_time, rain_time[i].substr(5, 4));
        
        if (rain_time[i + 1].substr(0, 4) > e_time) {
            ans.push_back(s_time + "-" + e_time);
            s_time = rain_time[i + 1].substr(0, 4);
        }

        if (i == n - 2) ans.push_back(s_time + "-" + rain_time[i + 1].substr(5, 4));
    }

    if (n == 1) cout << rain_time[0] << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << rain_time[i] << endl;
    // }

    // cout << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}