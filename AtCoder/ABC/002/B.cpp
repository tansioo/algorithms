#include <iostream>
using namespace std;

int main() {
    string w;
    cin >> w;

    string ans;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == 'a' || w[i] == 'i' || w[i] == 'u' || w[i] == 'e' || w[i] == 'o') continue;
        ans.push_back(w[i]);
    }

    cout << ans << endl;
    return 0;
}