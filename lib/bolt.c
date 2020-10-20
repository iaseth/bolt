#include "bolt.h"

#include <stdio.h>

void bolt_save_csv(Bolt bolt, char *filename) {
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		return;
	}
	char *text = bolt_get_csv(bolt);
	int result = fputs(text, fp);
	fclose(fp);
}

void bolt_save_json(Bolt bolt, char *filename) {
	//
}

void bolt_save_html(Bolt bolt, char *filename) {
	//
}

void bolt_save_xml(Bolt bolt, char *filename) {
	//
}


