#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{
	int index;
	int deadline;
	int profit;
} Job_t;

int compare(const void *a, const void *b)
{
	Job_t *j1 = (Job_t *)a;
	Job_t *j2 = (Job_t *)b;

	return j2->profit - j1->profit;
}

int jobSeq(Job_t *jobs, int n, int **seq, int *seq_size)
{
	int totalProfit = 0;
	qsort(jobs, n, sizeof(Job_t), compare);

	int max_time = jobs[0].deadline;
	for(int i = 1; i < n; i++)
	{
		if(jobs[i].deadline > max_time)
		{
			max_time = jobs[i].deadline;
		}
	}

	*seq = calloc(max_time, sizeof(int));
	*seq_size = max_time;

	for(int i = 0; i < n; i++)
	{
		for(int j = jobs[i].deadline - 1; j >= 0; j--)
		{
			if((*seq)[j] == 0)
			{
				(*seq)[j] = jobs[i].index;
				totalProfit += jobs[i].profit;
				break;
			}
		}
	}

	return totalProfit;
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	Job_t jobs[n];
	for(int i = 0; i < n; i++)
	{
		printf("Enter job (%d) profit and deadline: ", i + 1);
		scanf("%d %d", &(jobs[i].profit), &(jobs[i].deadline));
		jobs[i].index = i + 1;
	}

	int *seq = NULL; int seq_size = 0;
	int totalProfit = jobSeq(jobs, n, &seq, &seq_size);

	printf("Total profit: %d\nSequence: ", totalProfit);
	for(int i = 0; i < seq_size; i++)
	{
		printf("%d ", seq[i]);
	}
	putchar('\n');

	free(seq);
	return 0;
}
