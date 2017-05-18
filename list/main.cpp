#include <iostream>
#include <stdio.h>
#include <iostream>
#include <curses.h>
#define list_size 100
#define list_add 10
typedef struct Node{
    int *prev;
    int list_long;
    int now_long;
};
Node *list;
void list_heard(){
        list->prev= (int *)malloc(list_size*sizeof(int));//划内存
        list->list_long=list_size;
        list->now_long=0;

}
int insert(int x, int element){//x是插入位置
    int length = list->list_long;
    if (x<1||x>list->now_long+1)
        return 0;
    list->prev[x-1] = element;
    for (int i = length-1; i > x ; i++) {
        list->prev[i+1] = list->prev[i];
    }
    list->now_long++;
    return 1;
}
int getelement(Node *list, int x, int *element){
    int length = list->list_long;
    printf("%d", length);
    *element = list->prev[x];
    return 1;
}
int main() {

    int *element, *a, f;
    list_heard();
    insert(1, 520);
    printf("%p", list);

}
