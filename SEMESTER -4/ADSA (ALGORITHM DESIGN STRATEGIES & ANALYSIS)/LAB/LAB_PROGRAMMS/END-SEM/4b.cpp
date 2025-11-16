#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct item {
    int w, p;
};

bool compare(item& a, item& b) {
    double A = (double)a.w / a.p;
    double B = (double)b.w / b.p;
    return A > B;
}

void branchandbound(vector<item>& items, int c) {
    sort(items.begin(), items.end(), compare);
    int maxp = 0;
    int n = items.size();

    function<void(int,int,int)> explore = [&](int l, int cw, int cv) {
        // Termination condition for recursion
        if (l == n || cw >= c) 
        {
            if (cv > maxp)
            {
                maxp = cv;
            }
            return;
        }

        // Include this level
        if (cw + items[l].w <= c)
            explore(l + 1, cw + items[l].w, cv + items[l].p);

        // Exclude this level
        explore(l + 1, cw, cv);
    };

    explore(0, 0, 0); // Level, current weight, current value
    cout << "Max profit is: " << maxp;
}

int main() {
    int n, c;
    cout << "No of items : ";
    cin >> n;
    cout << endl << "Enter capacity : ";
    cin >> c;
    vector<item> items(n);
    cout << endl << "Weight : ";
    for (int i = 0; i < n; i++) { 
        cin >> items[i].w;
    }
    cout << endl << "Profit : ";
    for (int i = 0; i < n; i++) { 
        cin >> items[i].p;
    }
    branchandbound(items, c);
    return 0;
}
