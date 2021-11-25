#ifndef LUVA_BUILD_TOOL__PARSER_H_
#define LUVA_BUILD_TOOL__PARSER_H_

#include <token.h>
#include <task.h>

// parse tokens and return a list of tasks
task_list_t* parse(token_list_t *tokens);


#endif // LUVA_BUILD_TOOL__PARSER_H_