#include <stdio.h>
#define OK 1
#define ERROR -1
#define TURE 1
#define FALSE 0
#define MAXLENGTH 20

struct sequencelist
{
    int data[MAXLENGTH];
    int length;
};


int getElement(struct sequencelist list,int index,int *element)
{
    printf("\ngetElement\n");
    int length = list.length;//获取长度
    printf("length is %d\n",length);
    if(length ==0 || index < 0 || index >= length)//判断长度
        return ERROR;
    *element = list.data[index];
    return OK;
}


int insert(struct sequencelist *list,int index,int element)//插入元素
{
    printf("\ninsert\n");
    int length = list->length;
    printf("length is %d\n",length);
    if(length ==0 || index < 0 || index > length || length >= MAXLENGTH)
        return ERROR;
    list->data[index] = element;
    for(int i = length - 1;i>index;i--)
    {
        list->data[i+1] = list->data[i];
    }
    list->length++;
    return OK;
}


int deleter(struct sequencelist *list,int index)//删除表中元素
{
    printf("\ndelete\n");
    int length = list->length;
    printf("length is %d\n",length);
    if(length ==0 || index < 0 || index > length-1 )
    return ERROR;
    for(int i = index;i<length-1;i++)
    {
    printf("delete data[%d]\n",i);
    list->data[i] = list->data[i+1];
    }
    list->data[length-1] = '\0';
    list->length--;
    return OK;
}

int main()
{
    struct sequencelist list =
            {
                    {3,1,5,7,12,78,34},//整个表
                    7//长度
            };

    printf("list length  : %d\n",list.length);
    //Test get
    int *element, test = 8;


    if(OK == getElement(list,2,element))
    {
        printf("list get 2 :%d\n", *element);
    }
    //Test insert
    if(OK == insert(&list,7,520))
    {
        printf("list insert 7 ok!\n");
    }
    if(OK == getElement(list,7,element))
    {
        printf("list get 7 :%d\n", *element);
    }
    if(OK == insert(&list,3,520))
    {
        printf("list insert 3 ok!\n");
    }
    if(OK == getElement(list,3,element))
    {
        printf("list get 3 :%d\n", *element);
    }

    //Test delete
    if(OK == deleter(&list,3))
    {
        printf("list delete 3 ok!\n");
    }
    if(OK == getElement(list,3,element))
    {
        printf("list get 3 :%d\n", *element);
    }
    if(OK == deleter(&list,6))
    {
        printf("list delete 6 ok!\n");
    }
    if(OK == getElement(list,6,element))
    {
        printf("list get 6 :%d\n", *element);
    }
    else
    {
        printf("list get ERROR!\n");
    }
}