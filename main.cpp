#include<stdio.h>

void swap(int nums[], int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
/* 快速排序类 */
// 快速排序类-哨兵划分
int partition(int nums[], int left, int right) {
    // 以 nums[left] 为基准数
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            // 从右向左找首个小于基准数的元素
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            // 从左向右找首个大于基准数的元素
            i++;
        }
        // 交换这两个元素
        swap(nums, i, j);
    }
    // 将基准数交换至两子数组的分界线
    swap(nums, i, left);
    // 返回基准数的索引
    return i;
}

// 快速排序类-快速排序
void qsort(int nums[], int left, int right) {
    // 子数组长度为 1 时终止递归
    if (left < right) {
    // 哨兵划分
    int pivot = partition(nums, left, right);
    // 递归左子数组、右子数组
    qsort(nums, left, pivot - 1);
    qsort(nums, pivot + 1, right);
    }
}

int main(){
    int a[]={6,2,4,3,3,1},n=6;
    int z=0,y=5;
    qsort(a,z,y);
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
}




