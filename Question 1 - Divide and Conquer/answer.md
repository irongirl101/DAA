1. Design a divide and conquer approach to merge skylines.
merge-sort style approach:

Steps:
Divide buildings into two halves
Recursively compute skyline of each half
Merge the two skylines

Base Case
If only one building:
(l,h,r)→[(l,h),(r,0)]

Merge Step
We merge two skylines:
	S_1: left skyline
	S_2: right skyline
Maintained:
	h_1: current height from S_1
	h_2: current height from S_2
	Result height = max⁡(h_1,h_2)
Logic:
	Compare x-coordinates from both skylines
	Move pointer of smaller x
	Update height
	Add point only if height change

2. Handle overlapping buildings correctly

Overlapping is handled by:
"visible height"=max⁡(h_1,h_2)

So:
	Taller building dominates 
	When one ends → height drops 
	No duplicate heights added

3. Implement the algorithm
Look Into main.c

4. Derive the Recurrence Relation 
At each step:
	Divide into 2 halves 
	Merge takes linear time 
T(n)=2T(n/2)+O(n)

5. Time Complexity
Using Master Theorem:
T(n)=O(nlog⁡n)

6. Prove the correctness of the merging step 

Idea:
At any x-coordinate:
	h_1is correct height from left skyline 
	h_2is correct height from right skyline 
So:
"final height"=max⁡(h_1,h_2)





