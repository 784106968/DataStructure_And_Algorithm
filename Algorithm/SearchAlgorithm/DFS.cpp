//
// Created by 78410 on 2023/11/23.
//
//以查找路径最短的迷宫为例：
/*输入一个二维数组表示迷宫，然后输入起始位置和要找到的位置，求其最短路径

地图样例
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
 */
#include<iostream>

using namespace std;

int startx,starty,endx,endy;
int min_step=9999999;
int maze[100][100];
int tempmaze[100][100]={0};
int n,m;//设置数组边界大小


void dfs(int x,int y,int step){
    int tx,ty;
    int dx[4]={0,1,0,-1};//按照右下左上设置移动方向
    int dy[4]={1,0,-1,0};
    if(x==endx&&y==endy){//设置递归结束条件
        if(step<min_step){
            min_step=step;
            return;
        }
    }
    for(int k=0;k<=3;k++){//每次dfs都按序遍历四个方向
        tx=x+dx[k];
        ty=y+dy[k];
        //首先判断越界条件：
        if(tx<0||tx>n-1||ty<0||ty>m-1){
            continue;
        }
        //其次判断节点是否被访问过：
        if(maze[tx][ty]==0&&tempmaze[tx][ty]==0){
            tempmaze[tx][ty]=1;//访问过后，节点置为1，标志访问过
            dfs(tx,ty,step+1);//在当前节点进行dfs，并将步数+1
            tempmaze[tx][ty]=0;//在dfs访问结束后，当前节点必须置为0以此来回溯之前节点
        }
    }
    return;
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    cin>>startx>>starty>>endx>>endy;
    tempmaze[startx][starty]=1;
    dfs(startx,starty,0);
    cout<<"最短路径为："<<min_step<<endl;
    return 0;
}