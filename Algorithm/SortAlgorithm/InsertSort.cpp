//
// Created by 78410 on 2024/3/1.
//
//直接插入排序思想，是在遍历数组的过程中，将后续的每个元素插入到数组中正确的位置上去
//直接插入排序可以使用二分搜索来提高查找正确位置的速度
//该算法是稳定的，且当元素顺序为正序时，其运行效率最快，为O(n)；
//元素顺序为逆序时，运行效率最坏，为O(n²)
#include<iostream>
#include<vector>
#include <ctime>

using namespace std;

void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void InsertSort(vector<int>&a,int left,int right){
    for(int i=left;i<=right;i++){
        for(int j=i;j>left;j--){
            if(a[j]<a[j-1]){
                Swap(a[j],a[j-1]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"请输入数组长度：";
    cin>>n;
    vector<int>a(n);
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
    }
    cout<<"未排序的数组为：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    InsertSort(a,0,n-1);
    cout<<"排序好的数组为：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


    return 0;
}