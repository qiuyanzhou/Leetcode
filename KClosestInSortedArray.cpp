#include <iostream>
#include <vector>
using namespace std;
int Largestsmaller(vector<int> a, int target) {
    int left = 0;
    int right = a.size() - 1;
    while(left < right - 1) {
        int mid = left + (right - left) / 2;
        if(a[mid] <= target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (a[right] <= target) {
        return right;
    }
    if (a[left] <= target) {
        return left;
    }
    return -1;
}

vector<int> kClosest(vector<int> array, int target, int k) {
    if (array.empty() || array.size() == 0) {
        return array;
    }
    if (k == 0) {
        vector<int> b;
        return b;
    }
    int left = Largestsmaller(array, target);
    int right = left + 1;
    vector<int> result (k);
    for(int i = 0; i < k; i++){
        
        if(left >= 0 && right <= array.size() - 1) {
            if (abs(target - array[left]) <= abs(array[right] - target)) {
                result[i] = array[left--];
            } else {
                result[i] = array[right++];
            }
        } else if(left < 0) {
            result[i] = array[right++];
        } else {
            result[i] = array[left--];
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A = {1, 4, 6, 8};
    int T = 9;
    int K = 3;
    vector<int> B = kClosest(A, T, K);
    for (int i = 0; i < B.size(); i++) {
        cout<< B[i] << " ";
    }
    cout << endl;
    return 0;
}
