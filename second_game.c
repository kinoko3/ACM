#include <stdio.h>
#include <math.h>

int main() {
    int cotal_number,str[18], k=7,temp;
    scanf("%d", &cotal_number);
    int id[cotal_number][18];
    char c;
    double num=0,d,bool=0,T[cotal_number];
    for (int j = 0; j < cotal_number; j++) {
        fflush(stdin);
        for (int i = 0; i < 18; i++) {
            scanf("%c",&c);
            id[j][i] = c-'0';
        }
    }
    for (int l = 0; l < cotal_number;l++) {
        for (int i = 6; i <= 14; i++) {
            d = id[l][i];
            if(i ==6){num=d*pow(10,k);k--;}
            else{
                num = num+d*pow(10,k);
                k--;}
        }
        if (l==0){
            bool = num;
            num=0;
            k=7;
            continue;}
        if (bool<num){
            for (int w = 0; w < 18; w++) {
                temp = id[l-1][w];
                id[l-1][w] = id[l][w];
                id[l][w] = temp;
            }
            bool = num;
        } else{printf("");bool=num;}
        num=0;
        k=7;
    }
    for (int m = 0; m < cotal_number;m++) {
        for (int u = 0; u < 18; u++) {
            printf("%d", id[m][u]);
        }
        printf("\n");
    }
    return 0;
}
