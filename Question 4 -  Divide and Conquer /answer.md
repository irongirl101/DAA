## 1. Design the divide-and-conquer algorithm.
### Algorithms
```
ALG MAX_CROSSING_SUM()
    // inputs : arr, l,mid,r
    // output : right sum + left sum 
    sum <- 0 
    left_sum <- infinity 

    for i<- mid to l do 
        sum <- sum + arr[i] 
        if sum > left_sum 
            left_sum = sum 
    
    sum <- 0 
    right_sum <- infinity
     for i<- mid+1 to r do 
        sum <- sum + arr[i] 
        if sum > right_sum 
            right_sum = sum 
    
    return left_sum + right_sum
```
```
ALG MAX_SUBARRAY()
    // input : arr,l,r
    // output : max value 

    if l = r 
        return arr[l]
    
    if mid = (l+r) /2 

    left = MAX_SUBARRAY(arr,l,mid)
    right = MAX_SUBARRAY(arr,mid+1,r)
    cross = MAX_CROSSING_SUM(arr,l,mid,r)

    return max(max(left,right),cross)
```

## 2. Implement the algorithm 
Please check main.c 

## 3. Derive the recurrence relation for the running time.
### Recurrence Relation 
``` T(n) = 2T(n/2) + O(n) ``` 
Therefore, time complexity = Θ(n log n)

## 4. Solve the recurrence using the Master Theorem.
```
T(n) = aT(n/b) + f(n)
n^(log_b a) = n^(log₂ 2) = n^1 = n
f(n) = O(n)
n^(log_b a) = n
f(n) = Θ(n^(log_b a))
```
Therefore, time complexity = Θ(n log n)


## 5. Compare the performance with the brute-force O(n?) solution. 