#include <iostream>
using namespace std;
int BOARD[11][11];//����
int COLUMN[11],LINE1[22],LINE2[22];//������ б��1���� б��2���� �������ж��ܷ��໥���� 
int N,SOLU;//���̳ߴ磬������

void dfs(int row)//row ��ǰ���� ��1��ʼ 
{
	if(row > N)
	{
		SOLU += 1;
		return;
	}
	for(int col = 1;col <= N;col++)//ÿһ�� 
	{
		bool can_place = true;
		//if i not in column and i not in line1 and i not in line2: 
		for(int i = 0;i < 11;i++)
		{
			if(col == COLUMN[i])//�����ѱ�ռ�� 
			{
				can_place = false;
				break;
			}
		}
		for(int i = 0;i < 22;i++)
		{
			if(row - col == LINE1[i])//��б��1��x - y Ϊ��ֵ���ѱ�ռ�� 
			{
				can_place = false;
				break;
			}
		}
		for(int i = 0;i < 22;i++)
		{
			if(row + col == LINE2[i])//��б��2��x + y Ϊ��ֵ���ѱ�ռ�� 
			{
				can_place = false;
				break;
			}
		}
		if(can_place)
		{
			//���򣬣�row,col����������
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
