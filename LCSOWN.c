
#include<stdio.h>
#include<string.h>
int c[20][20],m,n,count=0;
char x[20],y[20],b[20][20];

void printLcs(int m,int n){
if(m==0 || n==0){
    return 0;
}
if(b[m][n]=='c'){
    printf("%c",x[m-1]);
    count=count+1;
    printLcs(m-1,n-1);
}
else if(b[m][n]=='u'){

    printLcs(m-1,n);
}
else{
    printLcs(m,n-1);
}

}


void lcs(){
     m=strlen(x);
     n= strlen(y);
    // for(int i=0;i<=m;i++){
    //    c[i][0]=0;
    //// }
    // for(int i=0;i<=n;i++){
    //    c[0][i]=0;
    // }


    for(int i=0;i<=m;i++){
       for(int j=0;j<=n;j++){
        if(i==0 || j==0){
            c[i][j]=0;
        }
       }
     }

     for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    c[i][j]=1+c[i-1][j-1];
                    b[i][j]='c';
                }
                else if(c[i-1][j]>=c[i][j-1]){
                    c[j][j]=c[i-1][j];
                    b[i][j]='u';
                }
                else{
                    c[j][j]=c[i][j-1];
                    b[i][j]='l';
                }

        }
     }

}
int main(){
    printf("Enter 1st String ");
    gets(x);
    printf("Enter 2nd String ");
    gets(y);
    printf("\n LCS is : ");
    lcs();
    printLcs(m,n);
    printf("\n LCS length is = %d",count);
}
