//
// Created by 78410 on 2024/3/1.
//
#include<iostream>
#include<vector>
using namespace std;

void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
//冒泡排序
void BubbleSort(vector<int>&a,int left,int right){
    for(int i=left+1;i<=right;i++){
        for(int j=left;j<=right-i+1;j++){
            if(a[j]>a[j+1]){
                Swap(a[j+1],a[j]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"请输入数组长度：";
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"未排序的数组为：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    BubbleSort(a,1,n-2);
    cout<<"排序好的数组为：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


    return 0;
}