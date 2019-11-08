#include <stdio.h>


// n+n/2+n/4+..+1; 一共执行了x次 N*(1/2)^x=1
int getCounterfeitCoin(int coins[], int first, int last)
{
	int firstSum = 0, lastSum = 0;
	int i;
	if (first == last - 1)
	{
		/*只剩两枚硬币*/
		if (coins[first] < coins[last])
			return first;
		return last;
	}
	if (0 == (last - first + 1) % 2 )
	{
		for (i = first; i < (last - first) / 2+1; i++)
		{
			firstSum += coins[i];
		}
		for (i = first + (last - first) / 2 + 1; i < last + 1; i++)
		{
			lastSum += coins[i];
		}

		if (firstSum < lastSum)
			return getCounterfeitCoin(coins, first, first+(last-first)/2);
		else
			return getCounterfeitCoin(coins, first + (last - first) / 2+1, last);
	}
	else
	{
		for (i = first; i < first + (last - first) / 2; i++)
		{
			firstSum += coins[i];
		}
		for ( i < first + (last - first) / 2+1;i<last+1; i++)
		{
			lastSum += coins[i];
		}
		if (firstSum < lastSum)
			return getCounterfeitCoin(coins, first, first + (last - first) / 2 - 1);
		else if (firstSum > lastSum)
			return getCounterfeitCoin(coins, first + (last - first) / 2, last);
		else
			return coins[(last - first) / 2];
	}

}