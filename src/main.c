#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lexer.h>
#include <parser.h>
#include <interpreter.h>

char *tasks[20];

int file_exists(const char *filename);
char *read_file(const char *filename);

int main(int argc, char **argv) {

	// check if build file exists in current directory
	if (!file_exists("build.luva")) {
		printf("Error: build.luva not found in current directory.\n");
		return 1;
	}

	// parse command line arguments
	for (size_t i = 1; i < argc && i < 20; i++) {
		if (strcmp(argv[i], "--help") == 0) {
			printf("Usage: %s [task]+\n", argv[0]);
			return 0;
		}

		if (argv[i][0] == '-') {
			printf("Unknown option: %s\n", argv[i]);
			return 1;
		} else {
			tasks[i - 1] = argv[i];
		}
	}

	// read all data from the file
	char *data = read_file("build.luva");

	// tokenize contents of the build file
	token_list_t *tokens = tokenize(data);

	// free the data
	free(data);

	// parse the tokens to a list of tasks
	task_list_t *tasks = parse(tokens);

	// free the tokens
	free_token_list(tokens);

	// execute the tasks
	int success = execute(tasks);

	// free the tasks
	free_task_list(tasks);

	return success;
}

int file_exists(const char *filename) {
	FILE *file;
	if ((file = fopen(filename, "r"))) {
		fclose(file);
		return 1;
	}
	return 0;
}

char *read_file(const char *filename) {
	FILE *file;
	char *data;
	long length;

	if ((file = fopen(filename, "r"))) {
		fseek(file, 0, SEEK_END);
		length = ftell(file);
		fseek(file, 0, SEEK_SET);
		data = malloc(length + 1);
		fread(data, 1, length, file);
		data[length] = '\0';
		fclose(file);
		return data;
	}

	return NULL;
}