#include <iostream>
#include <stdio.h>
typedef struct Node{
    int key;
    Node *prev, *next;
};
Node *nil;//头结点
void init(){//头结点初始化
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}
void insert(int key){//节点插入
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
}
Node* listseach(int key){//节点搜索
    Node *cur = nil->next;
    while (cur!=nil&&cur->key != key){
        cur = cur->next;
    }
    return cur;//返回的是搜索到的那个节点的指针
}
void deleteNode(Node *t){//删除节点
    if (t == nil)return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}
void printlist(){//遍历节点
    int isf=0;
    Node *cur = nil->next;
    while (1){
        if (cur == nil) break;
        if (isf++ >0) printf(" ");
        printf("%d", cur->key);
    }
    printf("\n");
}
int main() {
    return 0;
}