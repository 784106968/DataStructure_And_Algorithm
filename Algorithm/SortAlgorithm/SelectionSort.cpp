//
// Created by 78410 on 2024/3/2.
//
//简单选择排序：
//基本思想，每次遍历从中选取一个最值，将其逐个与前排元素交换，与冒泡相比，其减少了元素的交换次数
//

#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void print(vector<int>a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void SelectionSort(vector<int>&a,int left,int right){
    for(int i=left;i<right;i++){
        int min=i;
        for(int j=i+1;j<=right;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        Swap(a[min],a[i]);
        cout<<"第"<<i<<"次选择结果：";
        print(a);
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
    SelectionSort(a,0,n-1);
    cout<<"排序好的数组为：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}