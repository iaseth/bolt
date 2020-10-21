#include "bolt.h"
#include <stdio.h>

void
sample_action ()
{
	int num = 0;
	for (int i = 0; i < 1e6; ++i) {
		num++;
	}
}

void
sample_experiment ()
{
	long num = 0;
	for (int i = 0; i < 1e6; ++i) {
		for (int i = 0; i < 100; ++i) {
			num++;
		}
	}
}

int main (int argc, char const *argv[]) {
	BOLT_INIT("Bolt Internal");
	BOLT_MILESTONE("Start");
	BOLT_ACTION(sample_action, 1000);
	BOLT_EXPERIMENT(sample_experiment, 10);
	BOLT_MILESTONE("End");
	BOLT_RUN;
	BOLT_CLEAN;
	return 0;
}
