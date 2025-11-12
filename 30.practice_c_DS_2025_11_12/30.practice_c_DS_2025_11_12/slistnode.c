#include "slistnode.h"


void SLN_print(SLN* ps) {
	assert(ps);
	SLN* pc = ps;
	while (pc) {
		printf("%d ", pc->x);
		pc = pc->next;
	}
	printf("NULL\n");
}