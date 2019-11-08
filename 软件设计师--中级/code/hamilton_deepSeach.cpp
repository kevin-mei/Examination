#include <stdio.h>
//#include <stidb.h>

#define MAX 100

void Hamiton(int n, int x[MAX], int c[MAX][MAX])
{
	int t;
	int visited[MAX];
	int k;

	/*初始化x数组和visited数组*/
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
		visited[i] = 0;
	}

	/*访问起始顶点*/
	k = 0;
	//(1)
	visited[0] = 1;
	x[0] = 0;
	k = k + 1;

	/*访问其它顶点*/ // init k=1
	while (k >= 0)
	{
		x[k] = x[k] + 1; // x[1]=1
		while (x[k] < n) // 找当前定点是否有为访问过的邻接点
		{
			if ( 0 == visited[x[k]] && c[x[k-1]][x[k]]==1)
			{
				/*邻接顶点x[k]未被访问过*/
				break;
			}
			else
			{
				x[k] = x[k] + 1;				
			}
		}
		if (x[k] < n && n-1 == k && c[x[n-1]][0] == 1) // 第三个条件判断 最后一个顶点和第一个顶点有边相连
		{
			/*找到一条回路*/
			for (k = 0; k < n; k++)
			{
				printf("%d--", x[k]);
			}
			printf("%d--", x[0]);
			return;
		}
		else if (x[k] < n && k < n - 1)
		{
			/*设置当前顶点的访问标志，继续下一个顶点*/
			visited[x[k]] = 1;
			k = k + 1;
		}
		else
		{
			/*没有未被访问过的邻接顶点。回退到上一个顶点*/
			x[k] = 0;
			//visited[x[k]] = 0;
			k = k - 1;
		}
	}

}