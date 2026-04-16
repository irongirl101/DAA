#include <stdio.h> 

int count(int n, int denomination[], int amount){
    int c = 0; 
    for(int i = n-1; i>=0; i--){
        c += amount/denomination[i]; 
        amount = amount%denomination[i];
    }
    return c; 
}
int main(){
    int n; // user input 
    int amount; 
    printf("Enter number of denomination on the coins in ascending order.\n"); 
    scanf("%d", &n);
    int denomination[] = {}; // this is to change to user input. 
    for(int i = 0; i<n;i++){
        scanf("%d", &denomination[i]); 
    }
    printf("Enter value:\n");
    scanf("%d",&amount);
    int result = count(n,denomination,amount); 

}