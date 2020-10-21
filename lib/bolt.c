#include "bolt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Bolt
bolt_new (char *name)
{
	Bolt bolt = malloc(sizeof(Bolt_t));
	strcpy(bolt->name, name);

	bolt->actions = malloc(BOLT_MIN_ACTIONS * sizeof(BoltAction));
	bolt->actions_capacity = BOLT_MIN_ACTIONS;
	bolt->actions_count = 0;

	bolt->experiments = malloc(BOLT_MIN_EXPERIMENTS * sizeof(BoltExperiment));
	bolt->experiments_capacity = BOLT_MIN_EXPERIMENTS;
	bolt->experiments_count = 0;

	bolt->milestones = malloc(BOLT_MIN_MILESTONES * sizeof(BoltMilestone));
	bolt->milestones_capacity = BOLT_MIN_MILESTONES;
	bolt->milestones_count = 0;

	return bolt;
}

Bolt
bolt_delete (Bolt bolt)
{
	if (bolt == NULL) return NULL;

	if (bolt->actions != NULL) free (bolt->actions);
	if (bolt->experiments != NULL) {
		for (int i = 0; i < bolt->experiments_count; ++i) {
			free(bolt->experiments[i]);
		}
		free (bolt->experiments);
	}
	if (bolt->milestones != NULL) {
		for (int i = 0; i < bolt->milestones_count; ++i) {
			free(bolt->milestones[i]);
		}
		free (bolt->milestones);
	}

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
	if (func == NULL) return;
	if (bolt->experiments_count == bolt->experiments_capacity) {
		long new_capacity = bolt->experiments_capacity * 2;
		long size = new_capacity * sizeof(BoltExperiment);
		bolt->experiments = realloc(bolt->experiments, size);
		bolt->experiments_capacity = new_capacity;
	}

	BoltExperiment exp = malloc(sizeof(BoltExperiment_t));
	strcpy(exp->name, name);
	exp->bolt = bolt;
	exp->func = func;
	exp->iterations = iterations;

	bolt->experiments[bolt->experiments_count] = exp;
	bolt->experiments_count++;
}

void
bolt_add_milestone (Bolt bolt, char *name)
{
	if (bolt == NULL) return;
	if (bolt->milestones_count == bolt->milestones_capacity) {
		long new_capacity = bolt->milestones_capacity * 2;
		long size = new_capacity * sizeof(BoltMilestone);
		bolt->milestones = realloc(bolt->milestones, size);
		bolt->milestones_capacity = new_capacity;
	}

	BoltMilestone milestone = malloc(sizeof(BoltMilestone_t));
	strcpy(milestone->name, name);
	milestone->bolt = bolt;

	bolt->milestones[bolt->milestones_count] = milestone;
	bolt->milestones_count++;
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


