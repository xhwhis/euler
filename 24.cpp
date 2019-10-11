#include <iostream>
#define max_n 10
using namespace std;

int jump_num[max_n + 5] = {0};
int dnum[max_n + 5] = {0};

void init() {
    jump_num[0] = 1, dnum[0] = 1;
    for (int i = 1; i < max_n; i++) {
        jump_num[i] = i * jump_num[i - 1];
        dnum[i] = 1;
    }
    return ;
}

int get_num(int n, int k) {
    int ind = (k / jump_num[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int n, k;
    cin >> n >> k;
    k--;
    for (int i = n - 1; i >= 0; i--) {
        int num = get_num(i, k);
        cout << num;
        k %= jump_num[i];
    }
    return 0;
}
