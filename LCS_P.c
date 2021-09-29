#include<stdio.h>
#include<string.h>
int max(int a, int b){
return (a > b)? a : b;
}
int lcs(char x[], char y[],int m,int n){
if(m==0||n==0){
    return 0;
}
if(x[m-1]==y[n-1]){
    return 1+lcs(x,y,m-1,n-1);
}else{
    return max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
}


}
int main(){
char x[50];
char y[50];
printf("Enter your 1st String ");
gets(x);
printf("\n Enter your 2nd String ");
gets(y);
int m = strlen(x);
int n = strlen(y);
printf("LCS is %d",lcs(x,y,m,n));
}
