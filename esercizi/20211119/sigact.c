#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sigh(int signo, siginfo_t *info, void *useless) {
	printf("prrr %d\n", info->si_pid);
}

int main(int argc, char * argv[]) {
	struct sigaction newact = {
		.sa_sigaction = sigh,
		.sa_flags = SA_SIGINFO };
	struct sigaction oldact;
	sigaction(SIGINT, &newact, &oldact);
	int i;
	for (i = 0; i<4 ; i++) {
		sleep(2);
		printf("tran tran %d\n", i);
	}
	sigaction(SIGINT, &oldact, NULL);
	for (; 1 ; i++) {
		sleep(2);
		printf("tran tran %d\n", i);
	}
}
