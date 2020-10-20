#ifndef BOLT_H
#define BOLT_H

#define BOLT_MAX_NAME_LENGTH 128

struct Bolt;
struct BoltAction;
struct BoltExperiment;
struct BoltMilestone;

typedef struct Bolt Bolt;
typedef struct BoltAction BoltAction;
typedef struct BoltExperiment BoltExperiment;
typedef struct BoltMilestone BoltMilestone;


struct Bolt {
	char name[BOLT_MAX_NAME_LENGTH];

	BoltAction *actions;
	int actions_count;
	int actions_capacity;

	BoltExperiment *experiments;
	int experiments_count;
	int experiments_capacity;

	BoltMilestone *milestones;
	int milestones_count;
	int milestones_capacity;
};

struct BoltAction {
	Bolt *bolt;
	char name[BOLT_MAX_NAME_LENGTH];
	long iterations;
};

struct BoltExperiment {
	Bolt *bolt;
	char name[BOLT_MAX_NAME_LENGTH];
	long iterations;
};

struct BoltMilestone {
	Bolt *bolt;
	char name[BOLT_MAX_NAME_LENGTH];
};


Bolt *bolt_new();

void bolt_add_action (Bolt *bolt, char *name, long iterations);
void bolt_add_experiment (Bolt *bolt, char *name, long iterations);
void bolt_add_milestone (Bolt *bolt, char *name);

void bolt_run(Bolt *bolt);
void bolt_run_actions(Bolt *bolt);
void bolt_run_experiments(Bolt *bolt);

void bolt_print(Bolt *bolt);
void bolt_print_actions(Bolt *bolt);
void bolt_print_experiments(Bolt *bolt);
void bolt_print_milestones(Bolt *bolt);

Bolt *bolt_delete(Bolt *bolt);



#endif