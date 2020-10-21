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

	if (bolt->actions != NULL) {
		for (int i = 0; i < bolt->actions_count; ++i) {
			free(bolt->actions[i]);
		}
		free (bolt->actions);
	}

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



BoltAction
bolt_add_action (Bolt bolt, BoltFunction func, char *name, long iterations)
{
	if (bolt == NULL) return NULL;
	if (func == NULL) return NULL;
	if (bolt->actions_count == bolt->actions_capacity) {
		long new_capacity = bolt->actions_capacity * 2;
		long size = new_capacity * sizeof(BoltAction);
		bolt->actions = realloc(bolt->actions, size);
		bolt->actions_capacity = new_capacity;
	}

	BoltAction action = malloc(sizeof(BoltAction_t));
	strcpy(action->name, name);
	action->bolt = bolt;
	action->func = func;
	action->iterations = iterations;

	action->setup_func = NULL;
	action->setup_name[0] = '\0';
	action->cleanup_func = NULL;
	action->cleanup_name[0] = '\0';

	bolt->actions[bolt->actions_count] = action;
	bolt->actions_count++;
	return action;
}

BoltExperiment
bolt_add_experiment (Bolt bolt, BoltFunction func, char *name, long iterations)
{
	if (bolt == NULL) return NULL;
	if (func == NULL) return NULL;
	if (bolt->experiments_count == bolt->experiments_capacity) {
		long new_capacity = bolt->experiments_capacity * 2;
		long size = new_capacity * sizeof(BoltExperiment);
		bolt->experiments = realloc(bolt->experiments, size);
		bolt->experiments_capacity = new_capacity;
	}

	BoltExperiment experiment = malloc(sizeof(BoltExperiment_t));
	strcpy(experiment->name, name);
	experiment->bolt = bolt;
	experiment->func = func;
	experiment->iterations = iterations;

	experiment->setup_func = NULL;
	experiment->setup_name[0] = '\0';
	experiment->cleanup_func = NULL;
	experiment->cleanup_name[0] = '\0';

	bolt->experiments[bolt->experiments_count] = experiment;
	bolt->experiments_count++;
	return experiment;
}

BoltMilestone
bolt_add_milestone (Bolt bolt, char *name)
{
	if (bolt == NULL) return NULL;
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
	return milestone;
}



void
bolt_add_action_setup (BoltAction action, BoltFunction func)
{
	if (action == NULL) return;
	if (func == NULL) return;
	action->setup_func = func;
}

void
bolt_add_action_cleanup (BoltAction action, BoltFunction func)
{
	if (action == NULL) return;
	if (func == NULL) return;
	action->cleanup_func = func;
}



void
bolt_add_experiment_setup (BoltExperiment experiment, BoltFunction func)
{
	if (experiment == NULL) return;
	if (func == NULL) return;
	experiment->setup_func = func;
}

void
bolt_add_experiment_cleanup (BoltExperiment experiment, BoltFunction func)
{
	if (experiment == NULL) return;
	if (func == NULL) return;
	experiment->cleanup_func = func;
}



void
bolt_run (Bolt bolt)
{
	if (bolt == NULL) return;
	bolt_run_actions(bolt);
	bolt_run_experiments(bolt);
}

void
bolt_run_actions (Bolt bolt)
{
	if (bolt == NULL) return;
	if (bolt->actions != NULL) {
		for (int i = 0; i < bolt->actions_count; ++i) {
			BoltAction action = bolt->actions[i];
			BoltFunction func = action->func;
			long iterations = action->iterations;
			printf("Running action: '%s'\n", action->name);
			if (action->setup_func != NULL) action->setup_func();
			timespec_get(&action->start, TIME_UTC);
			for (int iteration = 0; iteration < iterations; ++iteration) {
				func();
			}
			timespec_get(&action->end, TIME_UTC);
			if (action->cleanup_func != NULL) action->cleanup_func();
			long time_taken_ms = (action->end.tv_sec - action->start.tv_sec) * 1e6 + (action->end.tv_nsec - action->start.tv_nsec) / 1e3;
			printf("\tTook %ldms.\n", time_taken_ms);
		}
	}
}

void
bolt_run_experiments (Bolt bolt)
{
	if (bolt == NULL) return;
	if (bolt->experiments != NULL) {
		for (int i = 0; i < bolt->experiments_count; ++i) {
			BoltExperiment experiment = bolt->experiments[i];
			BoltFunction func = experiment->func;
			long iterations = experiment->iterations;
			printf("Running experiment: '%s'\n", experiment->name);
			if (experiment->setup_func != NULL) experiment->setup_func();
			for (int iteration = 0; iteration < iterations; ++iteration) {
				func();
			}
			printf("\t%ld iterations complete.\n", iterations);
			if (experiment->cleanup_func != NULL) experiment->cleanup_func();
		}
	}
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


