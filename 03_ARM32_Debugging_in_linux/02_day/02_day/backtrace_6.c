
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <libunwind.h>

void sighandler(int signo)
{
	char name[256];
	unw_word_t pc, sp, offp;
	unw_cursor_t cursor;
	unw_context_t uc;
	int i = 0;
	unw_getcontext(&uc);
	unw_init_local(&cursor, &uc);
	unw_step(&cursor);
	while (unw_step(&cursor) > 0) {
		name[0] = '\0';
		unw_get_proc_name(&cursor, name, 256, &offp);
		unw_get_reg(&cursor, UNW_REG_IP, &pc);
		unw_get_reg(&cursor, UNW_REG_SP, &sp);
		printf("%d: %s (+0x%lx) pc = 0x%lx, sp = 0x%lx\n", i, name, 
				(long) offp, (long) pc, (long) sp);
		i++;
	}
	printf("signo=%d\n", signo );
	exit(-1);
}

void func2()
{
	int *p = 0;
	printf("%d\n", *p );
}

void func1()
{
	func2();
}

int main()
{
	signal(11, sighandler);
	func1();
	return 0;
}

