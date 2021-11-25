#include <token.h>

#include <stdlib.h>

void free_token(token_t* token) {
	free(token->value);
	free(token);
}

void free_token_list(token_list_t* list) {
	token_list_t* next;
	while (list) {
		next = list->next;
		free_token(list->token);
		free(list);
		list = next;
	}
}