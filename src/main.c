#include "bolt.h"
#include <stdio.h>

int main (int argc, char const *argv[]) {
	Bolt bolt = bolt_new();
	bolt = bolt_delete(bolt);
	return 0;
}
