#include "bolt.h"

#include <stdio.h>



#define BOLT_SAVE_GENERIC(bolt_get_func) FILE *fp = fopen(filename, "w"); \
	if (fp == NULL) return; \
	char *text = bolt_get_func(bolt); \
	int result = fputs(text, fp); \
	fclose(fp);

void bolt_save_csv(Bolt bolt, char *filename) {
	BOLT_SAVE_GENERIC(bolt_get_csv);
}

void bolt_save_json(Bolt bolt, char *filename) {
	BOLT_SAVE_GENERIC(bolt_get_json);
}

void bolt_save_html(Bolt bolt, char *filename) {
	BOLT_SAVE_GENERIC(bolt_get_html);
}

void bolt_save_xml(Bolt bolt, char *filename) {
	BOLT_SAVE_GENERIC(bolt_get_xml);
}

#undef BOLT_SAVE_GENERIC


