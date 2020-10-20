#include "bolt.h"

#include <stdio.h>
#include <stdlib.h>



Bolt
bolt_new ()
{
	Bolt bolt = malloc(sizeof(Bolt_t));

	bolt->actions = malloc(BOLT_MIN_ACTIONS * sizeof(BoltAction_t));
	bolt->actions_capacity = BOLT_MIN_ACTIONS;
	bolt->actions_count = 0;

	bolt->experiments = malloc(BOLT_MIN_EXPERIMENTS * sizeof(BoltExperiment_t));
	bolt->experiments_capacity = BOLT_MIN_EXPERIMENTS;
	bolt->experiments_count = 0;

	bolt->milestones = malloc(BOLT_MIN_MILESTONES * sizeof(BoltMilestone_t));
	bolt->milestones_capacity = BOLT_MIN_MILESTONES;
	bolt->milestones_count = 0;

	return bolt;
}

Bolt
bolt_delete (Bolt bolt)
{
	if (bolt == NULL) return NULL;

	if (bolt->actions != NULL) free (bolt->actions);
	if (bolt->experiments != NULL) free (bolt->experiments);
	if (bolt->milestones != NULL) free (bolt->milestones);

	free(bolt);
	return NULL;
}



void
bolt_add_action (Bolt bolt, BoltFunction func, char *name, long iterations)
{
	if (bolt == NULL) return;
}

void
bolt_add_experiment (Bolt bolt, BoltFunction func, char *name, long iterations)
{
	if (bolt == NULL) return;
}

void
bolt_add_milestone (Bolt bolt, char *name)
{
	if (bolt == NULL) return;
}



void
bolt_run (Bolt bolt)
{
	if (bolt == NULL) return;
}

void
bolt_run_actions (Bolt bolt)
{
	if (bolt == NULL) return;
}

void
bolt_run_experiments (Bolt bolt)
{
	if (bolt == NULL) return;
}


void
bolt_print (Bolt bolt)
{
	if (bolt == NULL) return;
}

void
bolt_print_actions (Bolt bolt)
{
	if (bolt == NULL) return;
}

void
bolt_print_experiments (Bolt bolt)
{
	if (bolt == NULL) return;
}

void
bolt_print_milestones (Bolt bolt)
{
	if (bolt == NULL) return;
}



char *
bolt_get_csv (Bolt bolt)
{
	if (bolt == NULL) return NULL;
	return NULL;
}

char *
bolt_get_json (Bolt bolt)
{
	if (bolt == NULL) return NULL;
	return NULL;
}

char *
bolt_get_html (Bolt bolt)
{
	if (bolt == NULL) return NULL;
	return NULL;
}

char *
bolt_get_xml (Bolt bolt)
{
	if (bolt == NULL) return NULL;
	return NULL;
}



#define BOLT_PRINT_GENERIC(bolt_get_func) \
	if (bolt == NULL) { \
		printf("Bolt is NULL!\n"); \
		return; \
	} \
	printf("%s\n", bolt_get_func(bolt));

void
bolt_print_csv (Bolt bolt)
{
	BOLT_PRINT_GENERIC(bolt_get_csv);
}

void
bolt_print_json (Bolt bolt)
{
	BOLT_PRINT_GENERIC(bolt_get_json);
}

void
bolt_print_html (Bolt bolt)
{
	BOLT_PRINT_GENERIC(bolt_get_html);
}

void
bolt_print_xml (Bolt bolt)
{
	BOLT_PRINT_GENERIC(bolt_get_xml);
}

#undef BOLT_PRINT_GENERIC



#define BOLT_SAVE_GENERIC(bolt_get_func) \
	FILE *fp = fopen(filename, "w"); \
	if (fp == NULL) return; \
	char *text = bolt_get_func(bolt); \
	fputs(text, fp); \
	fclose(fp);

void
bolt_save_csv (Bolt bolt, char *filename)
{
	BOLT_SAVE_GENERIC(bolt_get_csv);
}

void
bolt_save_json (Bolt bolt, char *filename)
{
	BOLT_SAVE_GENERIC(bolt_get_json);
}

void
bolt_save_html (Bolt bolt, char *filename)
{
	BOLT_SAVE_GENERIC(bolt_get_html);
}

void
bolt_save_xml (Bolt bolt, char *filename)
{
	BOLT_SAVE_GENERIC(bolt_get_xml);
}

#undef BOLT_SAVE_GENERIC


