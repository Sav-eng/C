#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int weight(string s) {
    int w = 0;
    bool b = true;
    for (char c : s) {
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                if (b) {
                    w += 1;
                    b = false;
                }
                break;
            default:
                b = true;
        }
    }
    return w;
}


bool compare(string s, string t) {
    return weight(s) > weight(t);
}


int main(void) {
    int t, n;
    vector<string> ls;
    cin >> t;
    while (t--) {
        cin >> n;
        ls.clear();
        for (int i=0; i<n; i++) {
            string w;
            cin >> w;
            ls.push_back(w);
        }
        stable_sort(ls.begin(), ls.end());
        stable_sort(ls.begin(), ls.end(), compare);
        for (int i=0; i<n-1; i++) {
            cout << ls[i] << " ";
        }
        cout << ls[n-1] << endl;
    }
    return 0;
}
