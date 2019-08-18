#include <iostream>
#include <cstdlib>
#include <cstring>
#define max_n 10000
#define max_m 210
using namespace std;

int result[max_n][max_m];
int result_len = 0;

int find_result(int *num) {
    for (int i = 0; i < result_len; i++) {
        if (memcmp(result + i, num, sizeof(int) * max_m)) continue;
        return i + 1;
    }
    return 0;
}

int main() {
    memset(result, 0, sizeof(result));
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int temp[max_m] = {0};
            temp[0]= 1, temp[1] = 1;
            for (int i = 0; i < b; i++) {
                for (int j = 1; j <= temp[0]; j++) {
                    temp[j] *= a;
                }
                for (int j = 1; j <= temp[0]; j++) {
                    if (temp[j] < 10) continue;
                    temp[j + 1] += temp[j] / 10;
                    temp[j] %= 10;
                    temp[0] += (j == temp[0]);
                }
            }
            if (find_result(temp) == 0) {
                memcpy(result + result_len, temp, sizeof(int) * max_m);
                result_len++;
            }
        }
    }
    cout << result_len;
    return 0;
}
