#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> freq(26, 0);

    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        freq[ch - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            cout << char(i + 'a') << " " << freq[i] << endl;
        }
    }

    return 0;
}