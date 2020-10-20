#include "bolt.h"

#include <stdio.h>



void bolt_run(Bolt bolt) {
	if (bolt == NULL) return;
}

void bolt_run_actions(Bolt bolt) {
	if (bolt == NULL) return;
}

void bolt_run_experiments(Bolt bolt) {
	if (bolt == NULL) return;
}


void bolt_print(Bolt bolt) {
	if (bolt == NULL) return;
}

void bolt_print_actions(Bolt bolt) {
	if (bolt == NULL) return;
}

void bolt_print_experiments(Bolt bolt) {
	if (bolt == NULL) return;
}

void bolt_print_milestones(Bolt bolt) {
	if (bolt == NULL) return;
}



char *bolt_get_csv(Bolt bolt) {
	if (bolt == NULL) return NULL;
	return NULL;
}

char *bolt_get_json(Bolt bolt) {
	if (bolt == NULL) return NULL;
	return NULL;
}

char *bolt_get_html(Bolt bolt) {
	if (bolt == NULL) return NULL;
	return NULL;
}

char *bolt_get_xml(Bolt bolt) {
	if (bolt == NULL) return NULL;
	return NULL;
}



void bolt_print_csv(Bolt bolt) {
	printf("%s\n", bolt_get_csv(bolt));
}

void bolt_print_json(Bolt bolt) {
	printf("%s\n", bolt_get_json(bolt));
}

void bolt_print_html(Bolt bolt) {
	printf("%s\n", bolt_get_html(bolt));
}

void bolt_print_xml(Bolt bolt) {
	printf("%s\n", bolt_get_xml(bolt));
}



#define BOLT_SAVE_GENERIC(bolt_get_func) \
	FILE *fp = fopen(filename, "w"); \
	if (fp == NULL) return; \
	char *text = bolt_get_func(bolt); \
	fputs(text, fp); \
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


