#include <stdio.h>  
#include <limits.h>  

// returns max of 2 integers
int max(int a, int b) { 
    return (a > b) ? a : b;  //using ternary op
}

// finds max sum crossing the midpoint
int maxCrossingSum(int arr[], int l, int mid, int r) {  
    int sum = 0;  
    int left_sum = INT_MIN;  
    // looping from mid to left boundary
    for (int i = mid; i >= l; i--) {  
        sum += arr[i];  // add current element to sum
        if (sum > left_sum)  
            left_sum = sum;  
    }

    sum = 0;  
    int right_sum = INT_MIN;  // right_sum = minimum integer value

    for (int i = mid + 1; i <= r; i++) {  //loop to right boundary
        sum += arr[i]; 
        if (sum > right_sum)  
            right_sum = sum;  
    }

    return left_sum + right_sum;  // returning sums
}

//rec func to find max subarray sum
int maxSubarray(int arr[], int l, int r) {  
    if (l == r)  
        return arr[l];  

    int mid = (l + r) / 2;  
    // recurse on left half
    int left = maxSubarray(arr, l, mid); 
    // Recurse on right half 
    int right = maxSubarray(arr, mid + 1, r);  
    // Find crossing sum
    int cross = maxCrossingSum(arr, l, mid, r);  
    // Return the max of left, right, and cross sums
    return max(max(left, right), cross); 
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

    int result = maxSubarray(arr, 0, n - 1);  

    printf("Maximum subarray sum: %d\n", result); 

    return 0; 
}
