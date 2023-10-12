#include<bits/stdc++.h>
using namespace std;

void Bubble(vector<int>&v, int n) {
    int count = 1;
    while(count < n) {
        for(int i=0; i<n-count; i++) {
            if(v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
            }
        }
        count++;
    }
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    Bubble(v, n);
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}
