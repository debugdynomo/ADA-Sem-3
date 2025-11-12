//it is limited to only non-negative integers
#include <iostream>
int main(){
    int num[5]={1,4,2,5,6};
    int max=num[0],count,flag=0;
    for(int i=0;i<5;i++){
        if(max<num[i]){
            max=num[i];
        }
    }
    int count_arr[max+1]={0};
    for(int i=0;i<max+1;i++){
        count=0;
        for(int j=0;j<5;j++){
            if(num[j]==i){
                count++;
            }
        }
        count_arr[flag]=count;
        flag++;
    }
    for(int i=0;i<max+1;i++){
        for(int j=0;j<count_arr[i];j++){
            printf("%d\n",i);
        }
    }
    return 0;
}