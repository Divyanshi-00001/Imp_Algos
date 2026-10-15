#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Step 1: Sort string
    sort(s.begin(), s.end());

    // Step 2: Print permutations
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));

    return 0;
}