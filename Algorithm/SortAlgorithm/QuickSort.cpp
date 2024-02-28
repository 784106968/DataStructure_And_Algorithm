//
// Created by 78410 on 2024/2/28.
//
#include<bits/stdc++.h>

using namespace std;
//快速排序基本思想：
//根据基准值进行数组划分
//以升序排序为例，从右边界开始，向前查找第一个出现小于基准值的位置并记录，此时从左边界查找第一个大于基准值的位置并记录
//两方查找结束的条件为左边界大于右边界或与右边界重合，此时一次查找结束
//递归以上方法，将整体区间不断缩小，最终排序完成
//以下是代码实现：

void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

//一次快速排序的实现
int position(vector<int>&a,int left,int right){
    int key=left;
    while(left<right){
        //查找小于基准值下标
        while(left<right&&a[right]>=a[key]){
            right--;
        }
        //查找大于基准值下标
        while(left<right&&a[left]<=a[key]){
            left++;
        }
        //对应位置数值交换
        Swap(a[left],a[right]);
    }
    //在整体完成交换后，最后要将基准值换到左边界最终停到的位置
    Swap(a[left],a[key]);
    return left;
}

//递归实现快速排序：
void QuickSort(vector<int>&a,int left,int right){
    if(left>=right){
        return;
    }
    //调用快排函数，并获取下一次排序位置
    int div=position(a,left,right);
    QuickSort(a,left,div-1);
    QuickSort(a,div+1,right);
}

int main(){
    vector<int>a={124,254,23,62,899,122};
    QuickSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}