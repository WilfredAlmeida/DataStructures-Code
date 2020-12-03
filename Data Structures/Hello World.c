#include <stdio.h>
#define SIZE 11
int main()
{

	int t, n, m;
	int a[SIZE], b[SIZE];

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for (int i = 0; i < m; i++)
			scanf("%d", &b[i]);

		int unionn[SIZE] = {-1};
		int c = 0;

		int f = 0;
		for (int i = 0; i < n; i++)
		{
			f = 0;

			for (int j = 0; j < n; j++)
			{
				if (a[i] != 0)
					if (unionn[j] == a[i])
					{
						f = 1;
						break;
					}
			}
			if (f == 0&&a[i]!=0)
			{
				unionn[c++] = a[i];
			}
		}

		for (int i = 0; i < m; i++)
		{
			f = 0;
			//if (a[i] != 0)
			for (int j = 0; j < c; j++)
			{
				if (b[i] != 0)
					if (unionn[j] == b[i])
					{
						f = 1;
						break;
					}
			}
			if (f == 0&&b[i] != 0)
			{
				unionn[c++] = b[i];
			}
		}

		for (int i = 0; i < c; i++)
			printf(" %d ", unionn[i]);
		printf("%d\n", c);
	}

	return 0;
}