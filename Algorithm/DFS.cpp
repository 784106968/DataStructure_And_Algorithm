//
// Created by 78410 on 2023/11/23.
//
//�Բ���·����̵��Թ�Ϊ����
/*����һ����ά�����ʾ�Թ���Ȼ��������ʼλ�ú�Ҫ�ҵ���λ�ã��������·��

��ͼ����
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
int n,m;//��������߽��С


void dfs(int x,int y,int step){
    int tx,ty;
    int dx[4]={0,1,0,-1};//�����������������ƶ�����
    int dy[4]={1,0,-1,0};
    if(x==endx&&y==endy){//���õݹ��������
        if(step<min_step){
            min_step=step;
            return;
        }
    }
    for(int k=0;k<=3;k++){//ÿ��dfs����������ĸ�����
        tx=x+dx[k];
        ty=y+dy[k];
        //�����ж�Խ��������
        if(tx<0||tx>n-1||ty<0||ty>m-1){
            continue;
        }
        //����жϽڵ��Ƿ񱻷��ʹ���
        if(maze[tx][ty]==0&&tempmaze[tx][ty]==0){
            tempmaze[tx][ty]=1;//���ʹ��󣬽ڵ���Ϊ1����־���ʹ�
            dfs(tx,ty,step+1);//�ڵ�ǰ�ڵ����dfs����������+1
            tempmaze[tx][ty]=0;//��dfs���ʽ����󣬵�ǰ�ڵ������Ϊ0�Դ�������֮ǰ�ڵ�
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
    cout<<"���·��Ϊ��"<<min_step<<endl;
    return 0;
}