#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;
int n,amount = 1;//�۲�Ա������������ˮ������ 
typedef struct
{
	int s,w;//s λ��  w ����  l ������˵�  r �����Ҷ˵� 
}people;
people pe[500005];
typedef struct
{
	int l,r;//������˵㡢�Ҷ˵� 
}interval;
interval iv[500005]; 
bool compare(people p1,people p2)
{
	return p1.s < p2.s;
}
interval isIntersection(interval iv1,interval iv2)
{//�н������ؽ������޽������ؿ� 
	if(iv1.l <= iv2.l && iv1.r >= iv2.r)return iv2;
	if(iv2.l <= iv1.l && iv2.r >= iv1.r)return iv1;
	if(iv1.l <= iv2.l && iv2.l <= iv1.r && iv2.r >= iv1.r)
	{
		interval itv;
		itv.l = iv2.l,itv.r = iv1.r;
		return itv; 
	}
	if(iv2.l <= iv1.l && iv1.l <= iv2.r && iv1.r >= iv2.r)
	{
		interval itv;
		itv.l = iv1.l,itv.r = iv2.r;
		return itv; 
	}
	if(iv1.r < iv2.l || iv2.r < iv1.l)
	{
		interval itv;
		itv.l = INF,itv.r = INF;
		return itv; 
	}
}
void f()
{
	iv[1].l = pe[1].s - pe[1].w,iv[1].r = pe[1].s + pe[1].w; 
	for(int i = 2;i <= n;i++)
	{//�ɽ���Զ������ӹ۲�Ա 
		interval itv = {pe[i].s - pe[i].w,pe[i].s + pe[i].w};
		//����������������ж�
		interval itvl = isIntersection(iv[amount],itv);
		if(itvl.l != INF)
		{//���½��� 
			iv[amount].l = itvl.l;
			iv[amount].r = itvl.r;
		}
		else
		{//�½����� 
			amount++;
			iv[amount].l = itv.l;
			iv[amount].r = itv.r;
		}
	}
	cout << amount << endl;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> pe[i].s >> pe[i].w;
		//p[i].l = p[i].s - p[i].w;
		//p[i].r = p[i].s + p[i].w;
	}
	sort(pe + 1,pe + 1 + n,compare);//sort(start,start+size,compare)
	f();
	/*
	interval iv1 = {2,4},iv2 = {1,14};
	interval itv = isIntersection(iv1,iv2);
	if(itv.l != INF)
	cout << "{ " << itv.l << "," << itv.r << " }" << endl;
	else
	cout << "{ }" << endl;
	
	for(int i = 1;i <= n;i++)
		cout << pe[i].s << "  " << pe[i].w << endl;//"  " << p[i].l << "  " << p[i].r <<
	*/
	return 0;
} 
