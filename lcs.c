#include<stdio.h>
#include<string.h>
int fStringL,sStringL,c[10][10];
char x[10],y[10],b[10][10];
void lcs(){
    fStringL = strlen(x);
    sStringL = strlen(y);
    printf("1st string length= %d",fStringL);
    printf("2nd string length= %d",sStringL);

    for(int i=0;i<=fStringL;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=sStringL;i++){
        c[0][i]=0;
    }


    for(int i=1;i<=fStringL;i++){
        for(int j=1;j<=sStringL;j++){
            if(x[i-1] == y[i-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }else{
                c[i][j]=c[i][j-1];
                 b[i][j]='l';
            }
        }
    }

}
void printlcs(int i,int j){
    if(i==0 || j==0){
        return;
    }
   if(b[i][j]=='c'){
        printf("%c",x[i-1]);
        printlcs(i-1,j-1);
    }
    else if(b[i][j]=='u'){
       // printf("%c",x[i-1]);
        printlcs(i-1,j);
    }
    else{
        printlcs(i,j-1);
    }

}
int main(){
    printf("Enter 1st sequence ");
    gets(x);
    printf("Enter 2nd sequence ");
    gets(y);
    lcs();
    //printf(x);
    printf("\n LCS is = ");
    printlcs(fStringL,sStringL);

}
