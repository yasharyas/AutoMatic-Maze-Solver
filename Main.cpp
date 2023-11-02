#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,ex,ey;
int a[110][110];
int head=1,tail=1,step=0;
int q[40000][4];
int fx[5]={0,1,0,-1,0};
int fy[5]={0,0,1,0,-1};
int tx,ty;
void print(int k){
	if(q[k][3]!=0) print(q[k][3]);
	a[q[k][1]][q[k][2]]=2;
	cout<<"("<<q[k][1]<<","<<q[k][2]<<")";
	if(k!=tail) cout<<"->";
	step++;
}
void welcome(){
	cout<<"Welcome to YSC-Maze! An automatic maze solve program.\nDeveloped by Yash Arya, Satvik Ranjan, and Chiranjeev Vyas in 2023 as a DSA Project"<<endl;
}
int main(){
	welcome();
	printf("\033[32m%s\033[0m","[INPUT x AND y]");
	cin>>n>>m;
	printf("\033[32m%s\033[0m\n","[INPUT YOUR MAZE BELOW]");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	printf("\033[32m%s\033[0m","[INPUT START]");
	cin>>sx>>sy;
	printf("\033[32m%s\033[0m","[INPUT END]");
	cin>>ex>>ey;
	q[1][1]=sx;q[1][2]=sy;q[1][3]=0;
	
	while(head<=tail){
		
		for(int i=1;i<=4;i++){
			tx=q[head][1]+fx[i];
			ty=q[head][2]+fy[i];
			
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==0){
				a[tx][ty]=3;
				tail++;
				q[tail][1]=tx;
				q[tail][2]=ty;
				q[tail][3]=head;
				if(tx==ex&&ty==ey) break;
			}
		}
		head++;
	}
	printf("\033[32m%s\033[0m\n","[RESULT OUTPUT]");
	print(tail);
	printf("\n\033[32m%s\033[0m\n","[MAZE]");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==2) printf("\033[31m%d\033[0m",a[i][j]);
			else if(a[i][j]==3) cout<<0;
			else cout<<a[i][j];
		}
		cout<<endl;
	}
	printf("\033[32mSteps:%d\033[0m\n",step-1);
}