#include <stdio.h>
#include <stdlib.h>
void SelectSort(int *nums,int numsSize){
    int min,temp;
    for(int i=0;i<numsSize-1;i++){
        min=i;
        for(int j=i+1;j<numsSize;j++){
            if(nums[min]>nums[j]){
                min=j;
            }
        }
        if(min!=i){
            temp=nums[min];
            nums[min]=nums[i];
            nums[i]=temp;
        }
    }
}
int* test(int* nums1, int n, int * indexset, int returnSize){
    int *Surplus,Surplus_number;
    Surplus_number = n - returnSize;
    Surplus = (int *)malloc(Surplus_number*sizeof(int));

    for (int i = 0, j=0, k=0; i < Surplus_number&&k < n;) {
        if (indexset[j] != k){
            Surplus[i] = nums1[k];
            i++;
            k++;
        }else{j++;k++;
        }
    }
    return Surplus;
}
int* testint(int* nums1,int* nums2,int cotalSize,int m ,int n,int* indexset, int returnSize){
     //并集
    int *cotalset;
    cotalset = (int *)malloc(cotalSize*sizeof(int));
    for (int j = 0; j < m; j++) {
        cotalset[j] = nums2[j];
    }
    for (int i = m, j=0, k=0; i < cotalSize&&k < n;) {
        if(indexset[j] != k){
            cotalset[i] = nums1[k];
            i++;
            k++;
        }else{
            j++;
            k++;
        }
    }
    SelectSort(cotalset, cotalSize);
    return cotalset;
}

//传出A的索引
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int* returnIndex) {
    int temp,i,j,*result,a=0;
    if (nums1Size > nums2Size)
        result=(int *)malloc(nums1Size*sizeof(int));
    else
        result=(int *)malloc(nums2Size*sizeof(int));
    //返回结果数组大小

    //选择排序
    SelectSort(nums1,nums1Size);
    SelectSort(nums2,nums2Size);

    *returnSize=0; //返回结果数组长度
    temp=nums1[nums1Size-1]+1;  //给temp赋一个不可能与nums1或nums2冲突的值
    for(i=0,j=0;i < nums1Size&&j<nums2Size;){
        if(nums1[i]>nums2[j]){
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            if(temp!=nums1[i]){ //不会重复加载
                result[(*returnSize)++]=nums1[i];
                returnIndex[a++]=i; //索引是A的
            }
            i++;
            j++;
        }
    }
    return result;
}
int main() {
    int n,m,a[10],*g, cotal, *r,size, *Surplus;
    printf("enter total number:");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    int B[m];
    for (int j=0; j < m; j++){
        scanf("%d", &B[j]);
    }
    int w[n+m];
    g = intersection(A, n, B, m, a,w);
    cotal = n + m - *a;
    //printf("%d", cotal);

    r = testint(A, B,cotal, m,n, w, *a);

    Surplus = test(A, n, w, *a);

    for (int k=0; k < cotal;k++){
        printf("%d", r[k]);
        printf(" ");
    }
    //printf("%d", w[0]);


    /*for (int k = 0; k < *a; k++){
        printf("%d", w[k]);
        printf(" ");
        //printf("%d", B[k]);
    }*/


    return 0;
}
