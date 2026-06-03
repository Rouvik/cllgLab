#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);

    int s[n], f[n];

    printf("Start times: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);

    printf("Finish times: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &f[i]);

    clock_t st = clock();

    printf("Selected: 1 ");
    int last = 0;

    for(int i = 1; i < n; i++)
    {
        if(s[i] >= f[last])
        {
            printf("%d ", i + 1);
            last = i;
        }
    }

    clock_t en = clock();

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("\nTime: %f sec",
           (double)(en - st) / CLOCKS_PER_SEC);

    printf("\nSpace: %ld KB\n",
           usage.ru_maxrss);

    return 0;
}