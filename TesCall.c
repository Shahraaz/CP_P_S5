//Optimise
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
void fun2(int t)
{
	// printf("ONE\n");
	pid_t ppid = getpid();
	pid_t cpid = fork();
	printf("%d %d\n", ppid, cpid);
	if (cpid > 0)
	{
		char call[20] = "sleep ", num[20];
		int i = 0;
		while (t)
		{
			num[i] = t % 10 + '0';
			++i;
			t /= 10;
		}
		int end = 0;
		while (call[end])
			end++;
		for (int j = i - 1; j >= 0; --j)
			call[end++] = num[j];
		call[end] = '\0';
		system(call);
		call[0] = 'k';
		call[1] = 'i';
		call[2] = 'l';
		call[3] = 'l';
		call[4] = ' ';
		end = 5;
		t = cpid;
		i = 0;
		while (t)
		{
			num[i] = t % 10 + '0';
			++i;
			t /= 10;
		}
		for (int j = i - 1; j >= 0; --j)
			call[end++] = num[j];
		call[end] = '\0';
		system(call);
		exit(0);
	}
	return;
}

void fun(int t)
{
}

void solve(int caseNo)
{
	int n;
	scanf("%d", &n);
	fun(n);
	n = 10;
	while (n--)
		printf("I am doing shit %d\n", getpid());
}

int main()
{
	solve(0);
	return 0;
}