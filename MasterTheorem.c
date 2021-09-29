#include<stdio.h>
#include <math.h>

int main(){
int a,b,k,p,coeff;
double log_result;

printf("Enter value for a, b, k, p: ");
scanf("%d %d %d %d",&a,&b,&k,&p);
log_result = log(a) / log(b);
printf("Enter the co-efficient of logn ");
scanf("%d",&coeff);
if(coeff>1){
    printf("Invalid\t Case -  Does not apply");
}
else{

    if (log_result > k){
        printf("Case - 1 and Complexity T(n) = O(n ^ log %d base %d )",b,a);
    }
    else if(log_result == k){
            int q = p+1;
        if(p>-1){
            printf("Case - 2 and Complexity T(n) = O(n ^ %d * log ^(%d) n",k,q);
        }
        else if(p=-1){
            printf("Case - 2 and Complexity T(n) = O(n ^ %d log logn)",k);
        }
        else{
            printf("Case - 2 and Complexity T(n) = O(n ^ %d)",k);
        }
    }
    else if(log_result < k){
        if(p>=0){
                if(p>0){
                    printf("Case - 3 and Complexity T(n) = O(n ^ %d * log ^(%d) n",k,p);
                }
                else{
                    printf("Case - 3 and Complexity T(n) = O(n ^ %d)",k);
                }
        }
        else{
             printf("Case - 3 and Complexity T(n) = O(n ^ %d)",k);
        }
    }
}
}
