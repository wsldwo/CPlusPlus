#include <iostream>
using namespace std;
int BOARD[11][11];//棋盘
int COLUMN[11],LINE1[22],LINE2[22];//列容器 斜线1容器 斜线2容器 ，用于判断能否相互攻击 
int N,SOLU;//棋盘尺寸，方案数

void dfs(int row)//row 当前行数 从1开始 
{
	if(row > N)
	{
		SOLU += 1;
		return;
	}
	for(int col = 1;col <= N;col++)//每一列 
	{
		bool can_place = true;
		//if i not in column and i not in line1 and i not in line2: 
		for(int i = 0;i < 11;i++)
		{
			if(col == COLUMN[i])//此列已被占用 
			{
				can_place = false;
				break;
			}
		}
		for(int i = 0;i < 22;i++)
		{
			if(row - col == LINE1[i])//此斜线1（x - y 为定值）已被占用 
			{
				can_place = false;
				break;
			}
		}
		for(int i = 0;i < 22;i++)
		{
			if(row + col == LINE2[i])//此斜线2（x + y 为定值）已被占用 
			{
				can_place = false;
				break;
			}
		}
		if(can_place)
		{
			//否则，（row,col）可以落子
			int col_pos = 0,line1_pos = 0,line2_pos = 0; 
			for(int i = 0;i < 11;i++)
			{
				if(COLUMN[i] == -100)
				{
					col_pos = i;
					COLUMN[i] = col;
					break;
				}
			}
			for(int i = 0;i < 22;i++)
			{
				if(LINE1[i] == -100)
				{
					line1_pos = i;
					LINE1[i] = row - col;
					break;
				}
			}
			for(int i = 0;i < 22;i++)
			{
				if(LINE2[i] == -100)
				{
					line2_pos = i;
					LINE2[i] = row + col;
					break;
				}
			}
			dfs(row + 1);
			COLUMN[col_pos] = -100;
			LINE1[line1_pos] = -100;
			LINE2[line2_pos] = -100;
		}
	} 
} 

int main()
{
	cin >> N;
	for(int i = 0;i < 11;i++)
	COLUMN[i] = -100;
	for(int i = 0;i < 22;i++)
	{
		LINE1[i] = -100;
		LINE2[i] = -100;
	}
	dfs(1);
	cout << SOLU << endl;
	return 0;
} 
