#include <bits/stdc++.h>

using namespace std;

#include "pair.h"
#include "Array.h"
#include "hash.h"
#include "User.h"
#include "heap.h"
#include "Magazin.h"

ofstream g("out");

int a[500005];
std::vector<int> v;

int main() {
    Hash H;
    srand(time(NULL));
    for (int i = 1; i <= 500000; ++i) {
        a[i] = rand();
        H.insert(a[i], i);
    }

    for (int i = 1; i <= 500000; ++i) {
        g << i << ' ' << a[i] << '\n';
    }

    Magazin M(532314, 124253.5, 2342.4, 300000);
    cout << fixed << setprecision(3);
    cout << M.getId() << ' ' << M.getX() << ' ' << M.getY() << '\n';

    for (int i = 1; i <= 300000; ++i) {
        User gigel(rand(), rand() % 100000, rand() % 100000);
        if (i & 1) {
            M.visit(rand(), gigel, -1);
        } else {
            int x = rand() % 100000;
            v.push_back(x);
            M.visit(rand(), gigel, x);
        }
    }

    // am verificat cu std::vector daca sunt corecte primele 100 de discounturi
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    Array <int> topKdiscounts = M.topKdiscounts(100);
    for (int i = 0; i < topKdiscounts.size(); ++i) {
        cout << topKdiscounts[i] << ' ' << v[i] << '\n';
    } cout << '\n';

    Array <double> topKdistances = M.topKdistances(100);
    for (int i = 0; i < topKdistances.size(); ++i) {
        cout << topKdistances[i] << '\n';
    } cout << '\n';
    return 0;
}