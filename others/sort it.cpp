// 2689 sort it

#include<iostream>
#include<vector>
using namespace std;

#define MAX 100001

int data[MAX], n,i, j,cnt,tmp[MAX];

void mSort(int lhs, int rhs)
{
	if(lhs == rhs) return;
	int mid = (lhs+rhs) / 2;
	mSort(lhs, mid);
	mSort(mid+1, rhs);

	int i = lhs, 
		j = mid+1,
		k = lhs;
	//	tmp[MAX];

	while(i <= mid && j <= rhs)
	{
		if(data[i] < data[j])
		{
			tmp[k++] = data[i++];
		}
		else
		{
			//cnt++;
			cnt += (mid-i+1);
			tmp[k++] = data[j++];
		}
	}

	while(i <= mid)
		tmp[k++] = data[i++];

	while(j <= rhs)
		tmp[k++] = data[j++];

	for(i = lhs; i<= rhs; i++)
		data[i] = tmp[i];
}

int main()
{
	
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&data[i]);

		cnt = 0;
		mSort(0, n-1);

/*		for(i=0; i<n; i++)
			printf("%d ",data[i]);*/
		printf("%d\n",cnt);
	}

	return 0;
}

/*
int main()
{
	int data[MAX], n,i, j,tmp,cnt;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&data[i]);

		cnt = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<(n-1);j++)
			{
				if(data[j] > data[j+1])
				{
					tmp = data[j];
					data[j] = data[j+1];
					data[j+1] = tmp;
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}

	return 0;
}*/