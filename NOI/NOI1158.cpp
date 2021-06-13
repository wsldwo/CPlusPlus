#include <iostream>
using namespace std;

struct dice
{
	int up = 1;
	int down = 6;
	int left = 4;
	int right = 3;
	int front = 2;
	int behind = 5;
	int R;//行 ROW
	int C;//列 COLUMN
	long long SUM = 1;//总和
	long long SUM2 = 0;//总和

	void go_right()
	{
		int temp = up;
		up = left;
		left = down;
		down = right;
		right = temp;
	}

	void go_left()
	{
		int temp = up;
		up = right;
		right = down;
		down = left;
		left = temp;
	}

	void go_down()
	{
		int temp = up;
		up = behind;
		behind = down;
		down = front;
		front = temp;
	}

	void roll()//方法超时
	{
		int x = 1,y = 1;
		//cout << up << " ";
		while(true)
		{
			//从左向右滚动
			if(y < C)
			{
				for(int i = 1; i < C; i++)
				{
					go_right();
					//cout << up << " ";
					SUM += up;
				}
				//cout << endl;
				y = C;
			}
			//从上向下滚动
			if(x < R)
			{
				go_down();
				//cout << up << " ";
				SUM += up;
				x += 1;
				//从右向左滚动
				for(int i = 1; i < C; i++)
				{
					go_left();
					//cout << up << " ";
					SUM += up;
				}
				//cout << endl;
				y = 1;
			}
			else
				break;
			//从上向下滚动
			if(x < R)
			{
				go_down();
				//cout << up << " ";
				SUM += up;
				x += 1;
			}
			else
				break;
		}
	}
	void roll2()
	{
		if(C % 4 == 0)
		{
			//6组一循环
			long long sum[7];
			int left[7][4] = {{0,0,0,0},{0,1,5,11},{0,5,11,13},{0,4,6,9},{0,6,9,10},{0,2,3,8},{0,3,8,12}};
			for(int i = 1;i <= 6;i++)
			{
				sum[i] = (C / 4) * 14 + left[i][C % 4];
				//cout<< sum[i] << " ";
			}
			//cout << endl;
			SUM2 = (R / 6) * (sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6]);
			for(int i = 1;i <= R % 6;i++)
			{
				SUM2 += sum[i];
			}
		}
		else if(C % 4 == 2)
		{
			//6组一循环
			long long sum[7];
			int left[7][4] = {{0,0,0,0},{0,1,5,11},{0,5,6,8},{0,3,8,12},{0,6,9,10},{0,2,8,13},{0,4,6,9}};
			for(int i = 1;i <= 6;i++)
			{
				sum[i] = (C / 4) * 14 + left[i][C % 4];
				//cout<< sum[i] << " ";
			}
			//cout << endl;
			SUM2 = (R / 6) * (sum[1] + sum[2] + sum[3] + sum[4] + sum[5] + sum[6]);
			for(int i = 1;i <= R % 6;i++)
			{
				SUM2 += sum[i];
			}
		}
		else if(C % 4 == 1)
		{
			//4组一循环
			long long sum[5];
			int left[5][4] = {{0,0,0,0},{0,1,5,11},{0,5,8,10},{0,6,10,11},{0,2,5,10}};
			for(int i = 1;i <= 4;i++)
			{
				sum[i] = (C / 4) * 14 + left[i][C % 4];
				//cout<< sum[i] << " ";
			}
			//cout << endl;
			SUM2 = (R / 4) * (sum[1] + sum[2] + sum[3] + sum[4]);
			for(int i = 1;i <= R % 4;i++)
			{
				SUM2 += sum[i];
			}
		}
		else//C % 4 == 3
		{
			//2组一循环
			long long sum[3];
			int left[3][4] = {{0,0,0,0},{0,1,5,11},{0,5,9,11}};
			for(int i = 1;i <= 2;i++)
			{
				sum[i] = (C / 4) * 14 + left[i][C % 4];
				//cout<< sum[i] << " ";
			}
			//cout << endl;
			SUM2 = (R / 2) * (sum[1] + sum[2]);
			for(int i = 1;i <= R % 2;i++)
			{
				SUM2 += sum[i];
			}
		}
	}
};
struct dice DICE;

int main()
{
	cin >> DICE.R >> DICE.C;//R行C列
	//DICE.roll();
	//cout << DICE.SUM << endl;
	DICE.roll2();
	cout << DICE.SUM2 << endl;
	return 0;
}
