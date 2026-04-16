#include <stdio.h> 

int count(int n, int denomination[], int used[],int amount){
    int c = 0; 
    for(int i = n-1; i>=0; i--){
        used[i]= amount/denomination[i]; 
        c+=used[i];
        amount = amount%denomination[i];

    }
    return c; 
}
int main(){
    int n = 0; 
    int amount = 0; 
    printf("Enter number of denominations \n"); 
    scanf("%d", &n);
    int denomination[n]; 
    int used[n]; 
    printf("Enter denominations seperated by a space in ascending order.\n"); 
    for(int i = 0; i<n;i++){
        scanf("%d", &denomination[i]); 
    }
    printf("Enter value:\n");
    scanf("%d",&amount);
    int result = count(n,denomination,used,amount); 

    printf("Coins used\n"); 
    for(int i = n-1; i >= 0; i--){   
        if(used[i] > 0){
            printf("%d x %d\n", denomination[i], used[i]);
        }
    }
    return 0; 
}