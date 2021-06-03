/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1;
    struct ListNode* p2;
    struct ListNode* p3;
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    l3->val = 0;
    l3->next = NULL;//C语言中，如果使用next指针，请一定初始化为NULL，否则运行时报错！
    int carry = 0; //进位
    p1 = l1;
    p2 = l2;
    p3 = l3;
    while (p1 || p2){
        int a,b;
        if(p1){
            a = p1->val;
            p1 = p1->next;
        }
        else{
            a = 0;
        }
        if(p2){
            b = p2->val;
            p2 = p2->next;
        }
        else{
            b = 0;
        }
        if (carry + a + b <= 9){
            p3->val = carry + a + b;

            carry = 0;
            
            if(p1 || p2){
                p3->next = malloc(sizeof(struct ListNode));
                p3->next->next = NULL;
                
                p3 = p3->next;
            }
            

        }
        else{
            p3->val = carry + a + b - 10;

            carry = 1;

            if(p1 || p2){
                p3->next = malloc(sizeof(struct ListNode));
                p3->next->next = NULL;//C语言中，如果使用next指针，请一定初始化为NULL，否则运行时报错！
                
                p3 = p3->next;
            }
            else{
                p3->next = malloc(sizeof(struct ListNode));
                p3->next->val  = carry;
                p3->next->next = NULL;//C语言中，如果使用next指针，请一定初始化为NULL，否则运行时报错！
                carry = 0;
                p3 = p3->next;
            }
        }
        
    }
    return l3;
}

struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL,*tail = NULL;
    int carry = 0;
    while(l1 ||l2){
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = carry + a + b;
        carry = sum / 10;
        if(!head){
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        }
        else{
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail->next->next = NULL;
            tail = tail->next;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        if(!l1 && !l2 && carry == 1){//修正5+5=10的情况
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = 1;
            tail->next->next = NULL;
        }

    }
    return head;

}

int main(){
    addTwoNumbers(NULL,NULL);
}