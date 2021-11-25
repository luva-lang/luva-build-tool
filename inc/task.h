#ifndef LUVA_BUILD_TOOL__TASK_H_
#define LUVA_BUILD_TOOL__TASK_H_

// define a struct that represents a task
typedef struct {
	// the name of the task
	char* name;
	// the command to execute
	char* command;
	// the working directory
	char* working_directory;
	// the arguments to pass to the command
	char** arguments;
	// the number of arguments
	int argument_count;
	// the environment variables to pass to the command
	char** environment_variables;
	// the number of environment variables
	int environment_variable_count;
	// the exit code of the task
	int exit_code;
	// the output of the task
	char* output;
	// the error output of the task
	char* error_output;
} task_t;

// define a list of tasks
typedef struct task_list_t {
	// the token
	task_t *task;
	// the index of the token
	int index;
	// the previous token
	struct task_list_t* prev;
	// the next token
	struct task_list_t *next;
} task_list_t;

// free a task
void free_task(task_t* task);

// free a list of tasks
void free_task_list(task_list_t* list);

#endif // LUVA_BUILD_TOOL__TASK_H_