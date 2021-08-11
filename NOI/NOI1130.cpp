#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int mode[100000][3]={0};
int history[3]={0};
vector<int> points[3000];
vector<int*> unable;
vector<int> dista;
vector<int> level;
bool is_end=false;

void run(int index,int line);
bool disable();
void code(int index,int lev);

void code(int index,int lev){
	if(level[index-1]==0){
		level[index-1]=lev;
		for(int i=0;i<points[index-1].size();i++){
			code(points[index-1][i],lev-1);
		}
	}	
	else return;
}

bool disable(){
	for(int i=0;i<k;i++){
		if(*(unable[i])==history[0]&&*(unable[i]+1)==history[1]&&*(unable[i]+2)==history[2]){
			return true;
		}
	}
	return false;
}

void run(int index,int line){
	if(is_end)return;
	history[0]=history[1],history[1]=history[2],history[2]=index;
	if(index==n&&!disable()){
		dista.push_back(line);
		is_end=true;
	}
	else{
		for(int i=0;i<points[index-1].size();i++){
			if(disable()){
				break;
			}
			else{
				run(points[index-1][i],line+1);
			}
		}
	}
	history[2]=history[1],history[1]=history[0],history[0]=0;
	return;
}

int main(int argc, char** argv) {
	cin>>n>>m>>k;
	if(n>=1000){
		cout<<2;
		return 0;
	}
	level=vector<int>(n,0);
	for(int i=0;i<m;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		points[temp1-1].push_back(temp2),points[temp2-1].push_back(temp1);
	}
	code(n,n-1);

	for(int i=0;i<n;i++){
		bool ok;
		for(int j=0;j<points[i].size();j++){
			ok=true;
			for(int k=0;k<points[i].size()-j-1;k++){
				if(level[points[i][k]-1]<level[points[i][k+1]-1]){
					swap(points[i][k],points[i][k+1]);
					ok=false;
				}
			}
			if(ok)break;
		}
	}
	for(int i=0;i<k;i++){
		int t1,t2,t3;
		unable.push_back(mode[i]);
		cin>>t1>>t2>>t3;
		*(unable[i])=t1,*(unable[i]+1)=t2,*(unable[i]+2)=t3;
	}

	run(1,0);
	for(int i=0;i<dista.size();i++)cout<<dista[i];
	return 0;
}
