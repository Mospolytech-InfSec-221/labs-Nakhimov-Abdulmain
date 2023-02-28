#include <iostream>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;

int main() {
    int n; cin >> n;
    std::queue<int> x2, x3, x5;
    x2.push(2);
    x3.push(3);
    x5.push(5);
    for (int i = 0; i < n; i++) {
        int min_n = std::min(x2.front(), std::min(x3.front(), x5.front()));
        cout << min_n << " ";
        x2.push(min_n * 2);
        x3.push(min_n * 3);
        x5.push(min_n * 5);
        if (x2.front() == min_n)
            x2.pop();
        if (x3.front() == min_n)
            x3.pop();
        if (x5.front() == min_n)
            x5.pop();
    }
    return 0;

}
