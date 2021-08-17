#include<stdio.h>
#include<stdlib.h>
//进行函数申明
void print_arr(int arr[],int arr_len);
void merge_sort_recursive(int arr[],int res[],int start,int end);
void quick_sort_recursive(int arr[],int start,int end);

//冒泡排序:每次将最大元素排到最后面
void bubble_sort(int arr[],int arr_len){
    printf("bubble_sort...\n");
    for(int i = 0;i < arr_len;i ++){
        for(int j = 0;j < arr_len - 1 - i;j++){//每次都从最前边开始，后边已经排好的就不管了
            if(arr[j] > arr[j + 1]){//遇到更大的就前后交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

//选择排序：每次将最小元素排到最前边
void select_sort(int arr[],int arr_len){
    printf("select_sort...\n");
    for(int i = 0;i < arr_len - 1;i ++){//只用交换到倒数第二个，因为当你把倒数第二个排好了，最后一个一定是最大的
        int min_index = i;//最小元素标签
        for(int j = i + 1;j < arr_len;j ++){
            if(arr[j] < arr[min_index]){
                min_index = j;//更新最小标签
            }
        }
        //把最小值交换到当前位置
        if(min_index != i){
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }

}

//插入排序
void insert_sort(int arr[],int arr_len){
    printf("insert_sort...\n");
    for(int i = 1;i < arr_len;i ++){//从第二个元素开始，把当前元素往前边插入
        int temp = arr[i];//备份当前元素
        for(int j = i - 1;j >= 0;j --){//从后向前查找合适位置
            if(arr[j] > temp){
                arr[j + 1] = arr[j];//如果大于当前元素，则往后移动
                if(j == 0){//特殊情况处理
                    arr[j] = temp;
                }
            }else{
                arr[j + 1] = temp;//arr[j + 1]为重复值，找到插入位置,进行插入
                break;//跳出，进行下一轮插入
            }
        }
    }
}

//希尔排序
void shell_sort(int arr[],int arr_len){
    printf("shell_sort...\n");
    for(int gap = arr_len / 2;gap > 0;gap/=2){//增量控制
        for(int i = gap;i < arr_len;i ++){//从第二个元素开始，把当前元素往前边插入
            int temp = arr[i];//备份当前元素
            for(int j = i - gap;j >= 0;j -= gap){//从后向前查找合适位置
                if(arr[j] > temp){//如果大于当前元素，则往后移动
                    arr[j + gap] = arr[j];
                    if(j - gap < 0){//特殊情况处理
                        arr[j] = temp;
                    }
                }else{
                    arr[j + gap] = temp;//arr[j + gap]为重复值，找到插入位置,进行插入
                    break;//跳出，进行下一轮插入
                }
                
            }
        }
        print_arr(arr,arr_len);

    }

}

//归并排序 递归版
void merge_sort(int arr[],int arr_len){
    printf("merge_sort...\n");
    int res[arr_len];//定义额外数组
    merge_sort_recursive(arr,res,0,arr_len - 1);
}
void merge_sort_recursive(int arr[],int res[],int start,int end){
    if(start >= end)
    return;
    //前半区间
    int start1 = start;
    int end1 = (start + end) / 2;//中间
    //后半区间
    int start2 = end1 + 1;
    int end2 = end;
    merge_sort_recursive(arr,res,start1,end1);
    merge_sort_recursive(arr,res,start2,end2);
    //合并两个有序数组
    int k = start;//对准起始位置
    while(start1 <= end1 && start2 <= end2){
        res[k ++] = arr[start1] < arr[start2] ? arr[start1 ++] : arr[start2 ++];
    }
    while(start1 <= end1){
        res[k ++] = arr[start1 ++];
    }
    while (start2 <= end2){
        res[k ++] = arr[start2 ++];
    }
    for(int i = start;i <= end;i++){
        arr[i]  = res[i];//将结果拷贝回去原数组
    }
}

//快速排序 递归版
void quick_sort(int arr[],int arr_len){
    printf("quick_sort...\n");
    quick_sort_recursive(arr,0,arr_len - 1);
}
void quick_sort_recursive(int arr[],int start,int end){
    if(start < end){
        //挖坑填数
        int i = start,j = end,pivot = arr[start];//arr[i]就是第一个坑
        while(i < j){
            // 从右向左找小于x的数来填arr[i]
            while (i < j && arr[j] >= pivot)
                j --;
            if(i < j)
                arr[i ++] = arr[j];//将arr[j]填到arr[i]中，arr[j]就形成了一个新的坑
            //从左向右找大于或等于x的数来填arr[j]
            while (i < j && arr[i] < pivot)
                i ++;
            if(i < j)
                arr[j --] = arr[i];//将arr[i]填到arr[j]中，arr[i]就形成了一个新的坑
        }
        arr[i] = pivot;//i == j时，把基准值填进去

        quick_sort_recursive(arr,start,i - 1);
        quick_sort_recursive(arr,i + 1,end);
    }

}

/*
传参后失效
int len(int arr[]){
    printf("%d  /  %d",sizeof(arr),sizeof(*arr));
    return (int) sizeof(arr) / sizeof(*arr);
}
*/

void print_arr(int arr[],int arr_len){
    for (int i = 0;i < arr_len;i ++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(int argc,char *argv){
    int arr[] = {49,38,65,97,76,13,27,49,55,04};
    int arr_len = (int) sizeof(arr) / sizeof(*arr);//只能在数组定义所在的代码区中，采用此方法，传参后失效。
    printf("%d / %d == %d \n",sizeof(arr),sizeof(*arr),(int) sizeof(arr) / sizeof(*arr));
    printf("before sort:  ");
    print_arr(arr,arr_len);
    //bubble_sort(arr,arr_len);
    //select_sort(arr,arr_len);
    //insert_sort(arr,arr_len);
    //shell_sort(arr,arr_len);
    //merge_sort(arr,arr_len);
    quick_sort(arr,arr_len);
    printf("after sort:  ");
    print_arr(arr,arr_len);
}