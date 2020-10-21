#include "bolt.h"
#include <stdio.h>

void
do_some_stuff ()
{
	int num = 0;
	for (int i = 0; i < 1e6; ++i) {
		num++;
	}
}

int main (int argc, char const *argv[]) {
	BOLT_INIT("Bolt Internal");
	BOLT_MILESTONE("Start");
	BOLT_ACTION(do_some_stuff, 1000);
	BOLT_EXPERIMENT(do_some_stuff, 10);
	BOLT_MILESTONE("End");
	BOLT_RUN;
	BOLT_CLEAN;
	return 0;
}
