#include "minitalk.h"

void sig_handler(int sig)
{
	static char c = 0;
	static int i = 0;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int main()
{
	struct sigaction sa;

	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Error: failed to set signal handler\n", 37);
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = &sig_handler;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Error: failed to set signal handler\n", 37);
		exit(EXIT_FAILURE);
	}
	ft_printf("Server PID: %d\n", getpid());

	while(1)
		pause();
	return (0);
}
