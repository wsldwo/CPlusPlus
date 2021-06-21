#include <iostream> 
using namespace std;

char MAP[30][30];
char BLOCK[8] = {'\0','|','-','+','1','2','3','4'};
int R,C;
int M_X,M_Y,Z_X,Z_Y;
int START_X,START_Y;

enum direction
{
	up = 1,down = 2,left = 3,right = 4
}dire;
 
bool isBlock(char c)
{
	if(c != '.')
	return true;
	else
	return false;
}

bool test(int x , int y)//���Կհ�ש 
{
	for(int i = 1;i <= 7;i++)
	{
		MAP[x][y] = BLOCK[i];
		int j = START_X, k = START_Y;//j k Ϊ��ǰש������
		int m = M_X, n = M_X;//m n Ϊ��һ��ש������ 
		while(j != Z_X || k != Z_Y)
		{
			if(MAP[m][n] == 'M')
			{
				//��� 
			}
			else if(MAP[j][k] == 'Z')
			{
				//�յ� 
			}
			else if(MAP[j][k] != '.')
			{
				//;�� 
			}
		}
	}
	MAP[x][y] = '.';//��ԭ 
	return false; 
}

int main()
{
	cin >> R >> C;
	for(int i = 1;i <= R;i++)
	{
		for(int j = 1;j <= C;j++)
		{
			cin >> MAP[i][j];
			if(MAP[i][j] == 'M')
			{
				M_X = i;
				M_Y = j;
			}
			if(MAP[i][j] == 'Z')
			{
				Z_X = i;
				Z_Y = j;
			}
		}
	}
	if(M_X - 1 >= 1 && isBlock(MAP[M_X - 1][M_Y]))//�Ϸ� 
	{
		START_X = M_X - 1;
		START_Y = M_Y;
	}
	else if(M_X + 1 <= R && isBlock(MAP[M_X + 1][M_Y]))//�·� 
	{
		START_X = M_X + 1;
		START_Y = M_Y;
	}
	else if(M_Y - 1 >= 1 && isBlock(MAP[M_X][M_Y - 1]))//�� 
	{
		START_X = M_X;
		START_Y = M_Y - 1;
	}
	else if(M_Y + 1 <= C && isBlock(MAP[M_X][M_Y + 1]))//�ҷ� 
	{
		START_X = M_X;
		START_Y = M_Y + 1;
	}
	if(START_X == 0 && START_Y == 0)//û�е�һ��ש 
	{
		//��������M�����������Ŀ�ש 
	}
	else
	{
		//��λ�ڶϵ��Ŀհ�ש 
	}
	/*
	for(int i = 1;i <= R;i++)
	{
		for(int j = 1;j <= C;j++)
		{
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}
