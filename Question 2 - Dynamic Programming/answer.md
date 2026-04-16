## 1. Derive the Recurrence Relation.
``` 
Let
X be of length m 
Y be of length n 

DP Table : dp[i][j] = length of LCS of X[0 . . i-1] and Y[0 . . j-1]

If the character match 
X[i-1] == Y[j-1]
dp[i][j] = 1 + dp[i-1][j-1]

If they do not match 
dp[i][j] = max(dp[i-1][j],dp[i][j-1])

Base case
dp[i][0] = 0 
dp[0][j] = 0 
```
## 2. Construct the DP Table.
```
Let X = ABCDGH 
Let Y = AEDFHR 

      A   E   D   F   H   R
    ----------------------
 0 | 0  0   0   0   0   0   0
 A | 0  1   1   1   1   1   1
 B | 0  1   1   1   1   1   1
 C | 0  1   1   1   1   1   1
 D | 0  1   1   2   2   2   2
 G | 0  1   1   2   2   2   2
 H | 0  1   1   2   2   3   3

```

## 3. Determine the length of LCS.
LCS Length = dp[6][6] = 3 

## 4. Reconstruct the sequence. 
Backtracking the steps:
Start from dp[m][n]
- If X[i-1] == Y[j-1]
- Else 
    - Move to the cell with greater value 
        - dp[i-1][j] (up)
        - dp[1][j-1] (left)

Example Trace 
```
Start at dp[6][6] → 3

H == H → include 'H'
Move to dp[5][5]

G != F → move to dp[4][5]

D == D → include 'D'
Move to dp[3][2]

A == A → include 'A'
```
## 5. Analyze the time and space complexity. 

Time Complexity = Θ(m x n) -> Filling the DP table
Space Complexity = Θ(m x n) -> DP table storage
