#include<stdio.h>
#include<stdlib.h>

int len(char* s){
    int length = 0;
    while (*s != '\0')
    {
        length ++;
        s ++;
    }
    return length;
}

void append(char* s,char c){//只能操作字符数组
    s[len(s)] = c;
}

void clear(char* s){//只能操作字符数组
    int length = len(s);
    for(int i = 0;i < length;i ++){
        s[i] = '\0';
    }
}

/*
错误版本，len(s)每次都会调用，导致长度一直在减少！！！
void clear(char* s){//只能操作字符数组
    for(int i = 0;i < len(s);i ++){
        s[i] = '\0';
    }
}
*/

int isInContianer(char* s,char c){
    while (*s != '\0')
    {
        if(*s == c){
            return 1;//非零为真
        }
        
        s ++;
    }
    return 0;//零为假
}

int lengthOfLongestSubstring(char* s){
    if (len(s) == 0){
        return 0;
    }
    if (len(s) == 1){
        return 1;
    }

    int maxlen = 0;
    char container[100] = "";
    char *head=NULL,*tail=NULL;
    
    char *slow,*quick;
    slow = quick = s;//复制字符串首字符地址
    while (*slow != '\0')
    {
        quick = slow;
        clear(container);
        int length = 0;
        while (*quick != '\0')
        {
            printf("%c",*quick);
            printf(" ##->  %s  <-## ",container);
            if (!isInContianer(container,*quick)){
                append(container,*quick);
                length ++;
            }
            else{
                if(length > maxlen){
                    head = slow;
                    tail = -- quick;
                    maxlen = length;
                }
                break;
            }
            quick ++;
            if(*quick == '\0'){
                if(length > maxlen){
                    head = slow;
                    tail = -- quick;
                    maxlen = length;
                }

            }
        }
        printf("\n");
        slow ++;
    }

    while(head <= tail){
        printf("%c",*head);
        head ++;
    }

    return maxlen;

}

int main(){
    
    char container[100] = "";
    container[0] = 'a';
    append(container,'b');
    append(container,'c');
    
    

    //printf("%s",'a'+'b');
    //append(container,'a');
    //append(container,'b');
    printf("%s\'s length is %d.\n",container,len(container));//再说一次C语言字符串要用双引号括起来！！！


    clear(container);
    printf("%s\'s length is %d.\n",container,len(container));

    printf("%d\n",isInContianer("bcda",'a'));

    printf(" %d",lengthOfLongestSubstring("anviaj"));
    return 0;
}