#include <iostream>
#include <algorithm>
using namespace std;

void permute(string s, int l, int r) {
    if(l == r) {
        cout << s << endl;
        return;
    }

    for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l+1, r);
        swap(s[l], s[i]); // backtrack
    }
}

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    permute(s, 0, s.length()-1);

    return 0;
}