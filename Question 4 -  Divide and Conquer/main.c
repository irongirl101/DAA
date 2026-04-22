#include <stdio.h>
#include <limits.h>

// returns max of 2 integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// finds max sum crossing the midpoint
int maxCrossingSum(int arr[], int l, int mid, int r) {
    int sum = 0;
    int left_sum = INT_MIN;

    for (int i = mid; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;

    for (int i = mid + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

// recursive function with constraint (no full array allowed)
int maxSubarray(int arr[], int l, int r, int orig_l, int orig_r) {
    if (l == r)
        return arr[l];

    int mid = (l + r) / 2;

    int left = maxSubarray(arr, l, mid, orig_l, orig_r);
    int right = maxSubarray(arr, mid + 1, r, orig_l, orig_r);
    int cross = maxCrossingSum(arr, l, mid, r);

    int ans = max(max(left, right), cross);

    // block full array case
    if (l == orig_l && r == orig_r && ans == cross) {
        ans = max(left, right);
    }

    return ans;
}

int main() {
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubarray(arr, 0, n - 1, 0, n - 1);

    printf("Maximum subarray sum: %d\n", result);

    return 0;
}