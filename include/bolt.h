#ifndef BOLT_H
#define BOLT_H

#define BOLT_MAX_NAME_LENGTH 100

struct Bolt;
struct Action;
struct Experiment;
struct Milestone;

typedef struct Bolt Bolt;
typedef struct Action Action;
typedef struct Experiment Experiment;
typedef struct Milestone Milestone;


struct Bolt {
	char name[BOLT_MAX_NAME_LENGTH];

	Action *actions;
	int actions_count;
	int actions_capacity;

	Experiment *experiments;
	int experiments_count;
	int experiments_capacity;

	Milestone *milestones;
	int milestones_count;
	int milestones_capacity;
};

struct Action {
	Bolt *bolt;
	char name[BOLT_MAX_NAME_LENGTH];
};

struct Experiment {
	Bolt *bolt;
	char name[BOLT_MAX_NAME_LENGTH];
};

struct Milestone {
	Bolt *bolt;
	char name[BOLT_MAX_NAME_LENGTH];
};


#endif