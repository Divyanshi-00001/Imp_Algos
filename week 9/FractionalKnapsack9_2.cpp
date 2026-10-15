#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
    double r;
    int v, w;
    int i;
};

bool cmp(item a, item b) {
    return a.r>b.r;
}

int main() {
    int n;
    cin >> n;
    vector<item> items(n);
    for(int i=0;i<n;i++) {
        cin >> items[i].w;
        items[i].i=i+1;
    } 
    for(int i=0;i<n;i++) {
        cin >> items[i].v;
    } 
    int W;
    cin >> W;
    for(int i=0;i<n;i++) {
        items[i].r = (double)items[i].v/items[i].w;
    } 
    sort(items.begin(),items.end(),cmp);
    double maxV=0;
    for(int i=0;i<n&&W>0;i++) {
        if(items[i].w<=W) {
            W-=items[i].w;
            maxV+=items[i].v;
            cout << items[i].i << " - " << items[i].w << endl;
        }
        else {
            maxV+=items[i].r*W;
            cout << items[i].i << " - " << W << endl;
            W=0;
        }
    }
    cout << maxV << endl;
}