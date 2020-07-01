#include <vector>
#include <numeric>

using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {
    int num = accumulate(A.begin(), A.end(), 0);
    if (num % 3 != 0) return false;
    int average = num / 3;
    int sum = 0, group = 0, rem = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        if (sum == average) {
            group++;
            if (group == 3) {
                if (i == A.size() - 1) return true;
                else 
                    return accumulate(A.begin() + i + 1, A.end(), 0) == 0 ? true : false;
            }
            sum = 0;
        }
    }
    return false;
}