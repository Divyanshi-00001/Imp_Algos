#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value, index;
    double ratio;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int N;
    cin >> N;

    vector<Item> items(N);

    // Input weights
    for(int i = 0; i < N; i++) {
        cin >> items[i].weight;
        items[i].index = i + 1;
    }

    // Input values
    for(int i = 0; i < N; i++) {
        cin >> items[i].value;
    }

    int W;
    cin >> W;

    // Calculate ratio
    for(int i = 0; i < N; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort by ratio
    sort(items.begin(), items.end(), cmp);

    double maxValue = 0.0;

    cout << "Selected items:\n";

    for(int i = 0; i < N; i++) {
        if(W == 0) break;

        if(items[i].weight <= W) {
            // take full item
            W -= items[i].weight;
            maxValue += items[i].value;

            cout << items[i].index << "-" << items[i].weight << endl;
        } 
        else {
            // take fraction
            double fraction = (double)W / items[i].weight;
            maxValue += items[i].value * fraction;

            cout << items[i].index << "-" << W << endl;

            W = 0;
        }
    }

    cout << "Maximum value : " << maxValue << endl;

    return 0;
}