#include <stdio.h>
#include <string.h>
#define LEN 10005
typedef struct pp{//类型名替换，类型名比如系统自带的int，char，double
    char name[100]; //任务名
    int t; //任务结束时间
}P;
P Q[LEN];//定义一个pp类型的数组
int head, tail, n;//head和tail都是全局的变量
void enqueue(P x){
    Q[tail] = x;
    tail = (tail+1) % LEN;//一个数除以另一个数，要是比另一个数小的话，商为0，余数就是它自己.
}
P dequeue(){//从队列里抽取元素
    P x = Q[head];//头元素
    head = (head+1) % LEN;
    return x;
}
int min(int a, int b){return a < b ? a : b;};
int main(){
    int i,q,c;
    int elaps=0;//累计处理时间
    P u;
    scanf("%d", &n);
    scanf("%d", &q);//n = 任务数，q = 时间片
    for (i = 1; i <= n; i++) {
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
    }
    head = 1; tail = n + 1;
    while (head!=tail){
        u = dequeue();
        c =min(q, u.t);//处理完返回时间片，不处理完返回处理时间
        u.t -= c;
        elaps += c;//总处理时间
        if (u.t > 0)
            enqueue(u);
        else
            printf("%s,%d\n", u.name, elaps);
    }
}

