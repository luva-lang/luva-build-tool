#include <task.h>

#include <stdlib.h>

void free_task(task_t* task) {
	free(task->name);
	free(task->command);

	for (size_t i = 0; i < task->argument_count; i++) {
		free(task->arguments[i]);
	}

	for (size_t i = 0; i < task->environment_variable_count; i++) {
		free(task->environment_variables[i]);
	}

	free(task->output);
	free(task->error_output);
	free(task);
}

void free_task_list(task_list_t* list) {
	task_list_t* next;
	while (list != NULL) {
		next = list->next;
		free_task(list->task);
		free(list);
		list = next;
	}
}