#include "bolt.h"
#include <stdio.h>

void
do_some_stuff ()
{
	//
}

int main (int argc, char const *argv[]) {
	BOLT_INIT("Bolt Internal");
	BOLT_MILESTONE("Start");
	BOLT_ACTION(do_some_stuff, 1000);
	BOLT_EXPERIMENT(do_some_stuff, 1000);
	BOLT_MILESTONE("End");
	BOLT_CLEAN;
	return 0;
}
