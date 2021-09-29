#include<stdio.h>


void knapsack_01(int v[] , int w[] , int n, int W){
   int k [20][20],i,j;
   for(i=0;i<n;i++){
        for(j=0;j<=W;j++){

            if(i==0 || j==0){
                k[i][j]=0;
            }
            else if(j<w[i]){
                   k[i][j]=k[i-1][j];
            }
            else{
                if(k[i-1][j]>k[i-1][j-w[i]]+v[i]){
                        k[i][j]=k[i-1][j];

                }
                else{
                        k[i][j]=k[i-1][j-w[i]]+v[i];
                }
            }



        }
   }




   for(i=0;i<n;i++){
        for(j=0;j<W;j++){

            printf("    %d",k[i][j]);

        }
        printf("\n");
   }

   printf("Result is = %d",k[n][W]);




}

int main(){
int weight[20],profit[20],capacity,num;
printf("Enter the number of objects = ");
scanf("%d",&num);
printf("Enter the weight and profit of  objects \n ");
for(int i = 0 ; i<num; i++){
    scanf("%d %d",&weight[i],&profit[i]);
}
printf("Enter the capacity");
scanf("%d",&capacity);
knapsack_01(profit,weight,num,capacity);


}
