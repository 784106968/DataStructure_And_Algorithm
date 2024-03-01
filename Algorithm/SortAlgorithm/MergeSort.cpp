//
// Created by 78410 on 2024/3/1.
//
//归并排序算法:（分治法）
//是一种稳定的排序算法，平均时间复杂度为O(nlogn)，最佳时间复杂度：O(n)，最差时间复杂度：O(nlogn)
//相较于快速排序算法，归并排序胜在是一种稳定的排序算法，但是其空间开销是O(n)，速度仅次于快速排序
//步骤一：首先将待排序的元素分成大小大致相同的两个序列。
//步骤二：再把子序列分成大小大致相同的两个子序列。
//步骤三：如此下去，直到分解成一个元素停止，这时含有一个元素的子序列都是有序的。
//步骤四：进行合并操作，将两个有序的子序列合并为一个有序序列，如此下去，直到所有的元素都合并为一个有序序列。

#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int>&a,int left,int mid,int right){
    //开辟一个辅助数组，用来存储当前需合并数组的排序结果，注意right是数组中最后一位下标，而非数组长度，故而要+1
    vector<int>b(right-left+1);
    //获取当前合并数组的首位下标，以及中间位的下一位下标
    //这里获取中间位的下一位下标，是因为数组的左右两部分的合并要分别以mid和right为终止条件
    int i=left;
    int j=mid+1;
    int k=0;
    //根据结束条件进入循环
    while(i<=mid&&j<=right){
        //若左部分小于等于右部分的数，则将左部分加入到数组中，反之则将右部分插入数组
        //这里解释一下为什么只需要左右分别比较即可排序：
        //因为在递归过程中，每次递归完成后进行合并，都是按照从小到大进行合并的，所以每次进行两部分数组合并时，其顺序都是由小到大排列的
        //故而每部分本身是有序的，只需要分别比较一次，即可得到新的合并后的有序数组
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    //若其中一方先到达合并数组的边界，则另一方直接全部添加到辅助数组后即可完成排序
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=right){
        b[k++]=a[j++];
    }
    //此时要从k=0开始为数组a赋值，因为b仅仅是个辅助数组，而原先在a中的下标范围不能改变
    k=0;
    //每组排序完后，需要重新赋值给原数组：
    for(int i=left;i<=right;i++){
        a[i]=b[k++];
    }
    vector<int>().swap(b);//辅助数组用完后，及时释放其空间
}

//递归实现归并排序：
void MergeSort(vector<int>&a,int left,int right){
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    //递归分解：
    MergeSort(a,left,mid);
    MergeSort(a,mid+1,right);
    //回溯合并排序
    Merge(a,left,mid,right);
}

int main(){
    int n;
    cout<<"请输入数组长度：";
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"尚未排序的数组：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    MergeSort(a,0,n-1);
    cout<<"排序好的数组：";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}