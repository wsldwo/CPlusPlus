#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//回溯法 使用引用传递，不会开辟新内存，也不会进行数据拷贝，能够提升运行速度
void split(vector<int>& ve, vector<int>& ve2, int sq[], int last_pos, int target, int& step, int& amount)
{
	//ve是计算ve2所打的草稿，step是计算amount所打的草稿，记录last_pos可以确保从大到小输出分解结果，从而避免输出重复组合的情况
	//cout << target << "  " << step << endl;
	if (target <= 0)
	{
		if (target == 0 && (step < amount || amount == 0))
		{
			amount = step;
			ve2 = ve;
			/*for (int i = 0; i < ve2.size(); i++)
				cout << ve2[i] << " ";
			cout << endl;*/
		}
		return;
	}
	if (amount == 1 || amount > 0 && step >= amount)//剪枝优化
		return;
	for (int i = last_pos; i > 0; i--)
	{
		if (sq[i] <= target)
		{
			target -= sq[i];
			step += 1;
			ve.push_back(sq[i]);
			split(ve, ve2, sq, i, target, step, amount);
			ve.pop_back();
			step -= 1;
			target += sq[i];
		}
	}
}
int numSquares_dfs(int n)
{
	int sq[101] = {};//平方数组
	int step = 0, amount = 0; //最少数量
	vector <int> ve, ve2; //记录分解的数字
	for (int i = 1; i <= 100; i++)
		sq[i] = i * i;
	split(ve, ve2, sq, 100, n, step, amount);
	/*cout << "n: " << n << " split: ";
	for (int i = 0; i < ve2.size(); i++)
		cout << ve2[i] << " ";
	cout << " amount: " << amount << endl;*/
	return amount;
}

int numSquares_bfs(int n)
{
	int sq[101] = {};//平方数组
	int level = 0; //树的层级，第一个零节点所处的层数即本题的解
	for (int i = 1; i <= 100; i++)
		sq[i] = i * i;
	deque <int> q;
	q.push_back(n);
	while (q.size() != 0)
	{
		level += 1;
		for (int i = q.size(); i > 0; i--)
		{
			int node = q.front();
			q.pop_front();
			for (int j = 1; j <= 100; j++)
			{
				if (sq[j] == node)
					return level;//零界点，返回解
				else if (sq[j] < node)
					q.push_back(node - sq[j]);
				else
					break;
			}
		}
	}
	return 0;
}


int main()
{
	//numSquares(12);
	for (int i = 9900; i <= 10000; i++)
		cout << "n: " << i << "  dfs: " << numSquares_dfs(i) << "  bfs: " << numSquares_bfs(i) << endl;
	//cout << 98 <<" : "<< numSquares(98) << endl;
	return 0;
}
