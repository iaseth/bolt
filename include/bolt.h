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



#endif