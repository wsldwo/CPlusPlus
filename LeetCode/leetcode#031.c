#include<stdio.h>

//返回正数长度
int len(int n){
    int length = 1;
    while(n >= 10){
        n /= 10;
        length ++;
    }
    return length;
}

//将数据最高位对齐，对每一位进行比较
int compare(int a,int b){
    int max_length = 4;//位数上限
    int len_a = len(a),len_b = len(b);
    while(len_a < max_length){
        a *= 10;
        len_a ++;

    }
    while (len_b < max_length)
    {
        b *= 10;
        len_b ++;
    }

    if(a > b){
        return 1;//左边大
    }else if(a == b){
        return 0;//相等
    }else{// a < b
        return -1;//右边大
    }
    
}

void select_sort(int* nums,int start,int end){
    for(int i = start;i < end;i ++){
        int minIndex = i;
        for(int j = i + 1;j < end + 1;j ++){

            int m = nums[minIndex],n = nums[j];

            int res = compare(m,n);
            if(res == 1){
               minIndex = j;
            }
        }
        //交换
        if(minIndex != i){
            int temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }

    }

}



void nextPermutation(int* nums, int numsSize){
    if(numsSize == 1){
        return;
    }
    int pos_j[numsSize];//存储交换j索引的位置
    for(int i = 0;i < numsSize;i ++){
        pos_j[i] = -1;//初始化为-1
    }
    for(int i = numsSize - 1;i >= 1;i --){

        for(int j = i - 1;j >= 0;j --){

            int m = nums[i],n = nums[j];
            int res = compare(m,n);
            if(res == 1){
                pos_j[i] = j;
                break;
                
            }
        }
    }



    int maxj = -1,maxi = -1;
    for(int i = 0;i < numsSize;i ++){
        printf("%d,%d\n",i,pos_j[i]);
        if(pos_j[i] > maxj){
            maxi = i;
            maxj = pos_j[i];
        }else if(pos_j[i] == maxj){
            if(compare(nums[i],nums[maxi]) == -1){
                printf("---------(%d , %d)---------\n",nums[i],nums[maxi]);
                maxi = i;
            }
        }

    }

    if(maxj >= 0 && maxi >= 0 && maxj != maxi){
        //交换
                
    int temp = nums[maxi];
    nums[maxi] = nums[maxj];
    nums[maxj] = temp;


    select_sort(nums,maxj + 1,numsSize - 1);

    }else{
    //已经是最大，根据首位进行升序排列
    //基于选择排序
    select_sort(nums,0,numsSize - 1);

    }
}

int main(){
    int data[] = {1,20,26,1,15,29,4,29,10,9,21,7,27,11,21,5,9,7,27,16,17,3,6,5,16,23,29,14,28,21,2,29,3,29,0,18,28,5,10,9,6,23,8,25,26,21,1,5,29,28,14,8,1,20,13,10};
    nextPermutation(data,56);
    for(int i = 0;i < 56;i ++){
        printf("%d ",data[i]);
    }
}