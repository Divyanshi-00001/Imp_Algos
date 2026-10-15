#include <iostream>
using namespace std;

#define d 256  // number of characters

void rabinKarp(string text, string pattern, int q) {
    int n = text.length();
    int m = pattern.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // Calculate h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {

        // If hash values match, check characters
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    int q = 101; // prime number

    rabinKarp(text, pattern, q);
    return 0;
}