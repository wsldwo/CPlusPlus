#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//���ݷ� ʹ�����ô��ݣ����Ὺ�����ڴ棬Ҳ����������ݿ������ܹ����������ٶ�
void split(vector<int>& ve, vector<int>& ve2, int sq[], int last_pos, int target, int& step, int& amount)
{
	//ve�Ǽ���ve2����Ĳݸ壬step�Ǽ���amount����Ĳݸ壬��¼last_pos����ȷ���Ӵ�С����ֽ������Ӷ���������ظ���ϵ����
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
	if (amount == 1 || amount > 0 && step >= amount)//��֦�Ż�
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
	int sq[101] = {};//ƽ������
	int step = 0, amount = 0; //��������
	vector <int> ve, ve2; //��¼�ֽ������
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
	int sq[101] = {};//ƽ������
	int level = 0; //���Ĳ㼶����һ����ڵ������Ĳ���������Ľ�
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
					return level;//���㣬���ؽ�
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
