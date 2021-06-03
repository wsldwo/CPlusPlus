#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    for(int i = 0;i < numsSize;i++){
        for(int j = i + 1; j<numsSize; j++){
            if(nums[i] + nums[j] == target){
                int *result = (int *)malloc(2*sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;//答案的元素个数，醉了，C语言做题这么麻烦
                return result;
            }
        }
    }
    *returnSize = 0;//答案的元素个数，醉了，C语言做题这么麻烦
    return NULL;
}
int main(){
    /*
    int a,b;
    scanf("%d",&a);//C语言字符串要用双引号！！！单引号会报错，，，，，但是Python中字符串既可以用单引号又可以用双引号
    scanf("%d",&b);
    printf("a + b = %d\n",a + b);
    printf(" &a: %p, &b: %p",&a,&b);
    return 0;
    */
}