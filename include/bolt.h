#ifndef BOLT_H
#define BOLT_H

#define BOLT_MAX_NAME_LENGTH 128

struct Bolt_t;
struct BoltAction_t;
struct BoltExperiment_t;
struct BoltMilestone_t;

typedef struct Bolt_t Bolt_t;
typedef struct BoltAction_t BoltAction_t;
typedef struct BoltExperiment_t BoltExperiment_t;
typedef struct BoltMilestone_t BoltMilestone_t;

typedef struct Bolt_t *Bolt;
typedef struct BoltAction_t *BoltAction;
typedef struct BoltExperiment_t *BoltExperiment;
typedef struct BoltMilestone_t *BoltMilestone;


struct Bolt_t {
	char name[BOLT_MAX_NAME_LENGTH];

	BoltAction actions;
	int actions_count;
	int actions_capacity;

	BoltExperiment experiments;
	int experiments_count;
	int experiments_capacity;

	BoltMilestone milestones;
	int milestones_count;
	int milestones_capacity;

	char *csv;
	char *json;
	char *html;
	char *xml;
};

struct BoltAction_t {
	Bolt bolt;
	char name[BOLT_MAX_NAME_LENGTH];
	long iterations;
};

struct BoltExperiment_t {
	Bolt bolt;
	char name[BOLT_MAX_NAME_LENGTH];
	long iterations;
};

struct BoltMilestone_t {
	Bolt bolt;
	char name[BOLT_MAX_NAME_LENGTH];
};


Bolt bolt_new();

void bolt_add_action (Bolt bolt, char *name, long iterations);
void bolt_add_experiment (Bolt bolt, char *name, long iterations);
void bolt_add_milestone (Bolt bolt, char *name);

void bolt_run(Bolt bolt);
void bolt_run_actions(Bolt bolt);
void bolt_run_experiments(Bolt bolt);

void bolt_print(Bolt bolt);
void bolt_print_actions(Bolt bolt);
void bolt_print_experiments(Bolt bolt);
void bolt_print_milestones(Bolt bolt);

void bolt_print_csv(Bolt bolt);
void bolt_print_json(Bolt bolt);
void bolt_print_html(Bolt bolt);
void bolt_print_xml(Bolt bolt);

char *bolt_get_csv(Bolt bolt);
char *bolt_get_json(Bolt bolt);
char *bolt_get_html(Bolt bolt);
char *bolt_get_xml(Bolt bolt);

void bolt_save_csv(Bolt bolt, char *filename);
void bolt_save_json(Bolt bolt, char *filename);
void bolt_save_html(Bolt bolt, char *filename);
void bolt_save_xml(Bolt bolt, char *filename);

Bolt bolt_delete(Bolt bolt);



#endif