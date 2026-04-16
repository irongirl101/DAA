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
    int n = 0; // user input 
    int amount = 0; 
    printf("Enter number of denomination on the coins in ascending order.\n"); 
    scanf("%d", &n);
    int denomination[n]; // this is to change to user input. 
    int used[n]; 
    for(int i = 0; i<n;i++){
        scanf("%d", &denomination[i]); 
    }
    printf("Enter value:\n");
    scanf("%d",&amount);
    int result = count(n,denomination,used,amount); 

    for(int i = n-1; i >= 0; i--){   
        if(used[i] > 0){
            printf("%d x %d\n", denomination[i], used[i]);
        }
    }
    return 0; 
}