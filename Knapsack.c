
#include<stdio.h>

void knapsack(int num, float weight[], float profot[], float capacity){
int i;
float x[20],tp=0;
for(i=0;i<num;i++){
    x[i]=0;
}
for(i=0;i<num;i++){
    if(weight[i]>capacity){
        break;
    }else{
     x[i]=1;
     tp = tp + profot[i];
     capacity = capacity-weight[i];

    }

}
if(i<num){

    x[i]= capacity/weight[i];
    tp = tp+(x[i]*profot[i]);

}

printf("\n The result vector is : ");

    for(i=0;i<num;i++){
       printf("%f \t",x[i]);
     }

    printf("\n Maximum profit is : %f",tp);

}

int main(){
float weight[20] ,profit [20], ratio[20],capacity,temp;
int num, i, j;
printf("Enter number of Objects : ");
scanf("%d",&num);
printf("Enter weight and profit of  each Objects : ");
for(i=0;i<num; i++){
    scanf("%f %f",&weight[i],&profit[i]);
}
printf("Enter the capacity of the Knapsack : ");
scanf("%f",&capacity);

for(i=0;i<num; i++){
   ratio[i] = profit[i] / weight[i];
}
for(i=0;i<num; i++){
    for(j=i+1;j<num; j++){
        if(ratio[j]>ratio[i]){

            temp = ratio[i];
            ratio[i]=ratio[j];
            ratio[j]=temp;

            temp = weight[i];
            weight[i]=weight[j];
            weight[j]=temp;

            temp = profit[i];
            profit[i]=profit[j];
            profit[j]=temp;
        }
    }

}


printf("\n Printing weight and Profit ");
   printf("\n Ratio ");
for(i=0;i<num; i++){

   printf("%f \t",ratio[i]);

}
   printf("\n weight ");
for(i=0;i<num; i++){

   printf("%f \t",weight[i]);

}
printf("\n profit ");
for(i=0;i<num; i++){

   printf("%f \t",profit[i]);

}

knapsack(num,weight,profit,capacity);

}
