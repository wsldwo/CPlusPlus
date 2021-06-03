double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size = nums1Size + nums2Size;
    int count = 0;//计数变量
    int *p1 = nums1,*p2 = nums2;//复制指针地址
    if(size % 2 == 0){//偶数个
    int a,b;
    int limit = size / 2 + 1;
    while(count <= limit){
        count ++;
        if(p1 && p2){
            if(*p1 < *p2){
                if(count == limit - 1)
                    a = *p1;
                if(count == limit)
                    b = *p1;
                p1 ++;
            }else{
                if(count == limit - 1)
                    a = *p2;
                if(count == limit)
                    b = *p2;
                p2 ++;

            }
        }else if(p1){
            if(count == limit - 1)
                a = *p1;
            if(count == limit)
                b = *p1;
            p1 ++;
        }else if(p2){
            if(count == limit - 1)
                a = *p2;
            if(count == limit)
                b = *p2;
            p2 ++;

        }
    }
    return ( (double) a + (double) b ) / 2;
    

    }else{//奇数个

    int a;
    int limit = (size + 1) / 2;
    while(count <= limit){
        count ++;
        if(p1 && p2){
            if(*p1 < *p2){
                
                if(count == limit)
                    a = *p1;
                p1 ++;
            }else{
                
                if(count == limit)
                    a = *p2;
                p2 ++;

            }
        }else if(p1){
            
            if(count == limit)
                a = *p1;
            p1 ++;
        }else if(p2){
            
            if(count == limit)
                a = *p2;
            p2 ++;

        }


    }
    return (double) a;

    }

}

//归并
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int size = nums1Size + nums2Size;
    int num[size];
    int k = 0,start1 = 0,end1 = nums1Size - 1,start2 = 0,end2 = nums2Size - 1;
    while( start1 <= end1 && start2 <= end2){
        num[k ++] = nums1[start1] < nums2[start2] ? nums1[start1 ++] : nums2[start2 ++];
    }
    while (start1 <= end1)
    {
        num[k ++] = nums1[start1 ++];
    }
    while (start2 <= end2)
    {
        num[k ++] = nums2[start2 ++];
    }
    
    if(size % 2 == 0){
        return (double)(num[size / 2 - 1] + num[size / 2 + 1 - 1]) / 2;

    }else{
        return (double)num[(size + 1) / 2 - 1];

    }
    
}