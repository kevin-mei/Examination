#include <stdio.h>
//#include <stidb.h>

#define MAX 100

void Hamiton(int n, int x[MAX], int c[MAX][MAX])
{
	int t;
	int visited[MAX];
	int k;

	/*��ʼ��x�����visited����*/
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
		visited[i] = 0;
	}

	/*������ʼ����*/
	k = 0;
	//(1)
	visited[0] = 1;
	x[0] = 0;
	k = k + 1;

	/*������������*/ // init k=1
	while (k >= 0)
	{
		x[k] = x[k] + 1; // x[1]=1
		while (x[k] < n) // �ҵ�ǰ�����Ƿ���Ϊ���ʹ����ڽӵ�
		{
			if ( 0 == visited[x[k]] && c[x[k-1]][x[k]]==1)
			{
				/*�ڽӶ���x[k]δ�����ʹ�*/
				break;
			}
			else
			{
				x[k] = x[k] + 1;				
			}
		}
		if (x[k] < n && n-1 == k && c[x[n-1]][0] == 1) // �����������ж� ���һ������͵�һ�������б�����
		{
			/*�ҵ�һ����·*/
			for (k = 0; k < n; k++)
			{
				printf("%d--", x[k]);
			}
			printf("%d--", x[0]);
			return;
		}
		else if (x[k] < n && k < n - 1)
		{
			/*���õ�ǰ����ķ��ʱ�־��������һ������*/
			visited[x[k]] = 1;
			k = k + 1;
		}
		else
		{
			/*û��δ�����ʹ����ڽӶ��㡣���˵���һ������*/
			x[k] = 0;
			//visited[x[k]] = 0;
			k = k - 1;
		}
	}

}