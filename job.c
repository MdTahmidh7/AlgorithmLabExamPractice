#include<stdio.h>

int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}
void knapsack(int num, float weight[], float profot[], float capacity,char id []){
int i,k,timeslot[100],filledTimeSlot = 0,z=0;
float tp=0;;
char fResult[100];

for(i = 0; i <= capacity; i++) {
    timeslot[i] = -1;
  }
for(i=1;i<=num;i++){
   k = minValue(capacity, weight[i-1]);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot=filledTimeSlot+1;
        tp = tp+profot[i-1];
        fResult[z] = id[i-1];
        z=z+1;
        break;
      }
      k--;
    }
    if(filledTimeSlot == capacity) {
      break;
    }
}
  printf("\nRequired Jobs: ");
  for(i = 0; i <capacity; i++) {
    printf(" --> %c\t", fResult[i]);

  }

  printf("\n \n Maximum Profit is = %f",tp);
}
int main(){
float weight[20] ,profit [20],capacity,temp;
int num, i, j;
char id[20];
printf("Enter number of Objects : ");
scanf("%d",&num);
printf("Enter weight and profit of  each Objects : ");
for(i=0;i<num; i++){
    scanf("%f %f %c",&weight[i],&profit[i],&id[i]);
}
printf("Enter time limit : ");
scanf("%f",&capacity);

for(i=0;i<num; i++){
    for(j=i+1;j<num; j++){
        if(profit[j]>profit[i]){

            temp = id[i];
            id[i]=id[j];
            id[j]=temp;

            temp = weight[i];
            weight[i]=weight[j];
            weight[j]=temp;

            temp = profit[i];
            profit[i]=profit[j];
            profit[j]=temp;
        }
    }
}

knapsack(num,weight,profit,capacity,id);
}
