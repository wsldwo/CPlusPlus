#include <stdio.h>
#include <stdlib.h>
int len(char * s){
    int length = 0;
    while (*s != '\0')
    {
        length ++;
        s ++;
    }
    return length;
}

void expand(int *lr,char *s,int left,int right){
    int length = len(s);
    while(left >= 0 && right < length && s[left] == s[right]){
        left -= 1;
        right += 1;
    }
    lr[0] = left + 1;
    lr[1] = right - 1;
}

void print_str(char * s){
    while (*s != '\0')
    {
        printf("%c",*s);
        s ++;
    }
    printf("\n");

}

char * longestPalindrome(char * s){
    int length = len(s);
    int start = 0,end = 0;
    for(int i = 0;i < length;i ++){
        int lr1[2],lr2[2];
        expand(lr1,s,i,i);//单个字符展开
        expand(lr2,s,i,i + 1);//双个字符展开
        if(lr1[1] - lr1[0] > end - start){
            start = lr1[0];
            end = lr1[1];
        }
        if(lr2[1] - lr2[0] > end - start){
            start = lr2[0];
            end = lr2[1];
        }
    }
    char *r = malloc((end - start + 2) * sizeof(char));//多一位用于放置'\0'
    for(int i = 0,j = start;i < (end - start + 1);i ++,j ++){
        r[i] = s[j];
    }
    r[end - start + 1] = '\0';//力扣C语言不添加此句，会报错字符数组越界

    return r;
}

int main(){
    //printf("%d , %s",len("abcd"),"abcd");
    char *r = longestPalindrome("cbbdbbcd");
    print_str(r);
}