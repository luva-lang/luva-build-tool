#include <lexer.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

token_list_t *tokenize(const char *str) {
	token_list_t *list = NULL;
	token_list_t *next = NULL;

	// tokenize the string
	while (*str != '\0') {
		// skip whitespace
		while (isspace(*str)) {
			str++;
		}

		// skip comments
		if (*str == '#') {
			while (*str != '\n') {
				str++;
			}
			continue;
		}

		// create a new token
		next = (token_list_t *)malloc(sizeof(token_list_t));
		next->next = NULL;
		next->token = (token_t *)malloc(sizeof(token_t));
		next->token->type = -1;
		next->token->value = NULL;

		// parse the token
		if (isdigit(*str)) {
			// parse a number
			next->token->type = TOKEN_NUMBER;
			next->token->value = (char *)malloc(sizeof(char));
			*next->token->value = *str;
			str++;
			while (isdigit(*str)) {
				next->token->value = (char *)realloc(next->token->value, sizeof(char) * (strlen(next->token->value) + 1));
				*(next->token->value + strlen(next->token->value)) = *str;
				str++;
			}

			printf("number: %s\n", next->token->value);
		} else if (isalpha(*str)) {
			// parse an identifier
			next->token->type = TOKEN_IDENTIFIER;
			next->token->value = (char *)malloc(sizeof(char));
			*next->token->value = *str;
			str++;
			while (isalnum(*str)) {
				next->token->value = (char *)realloc(next->token->value, sizeof(char) * (strlen(next->token->value) + 1));
				*(next->token->value + strlen(next->token->value)) = *str;
				str++;
			}
			printf("identifier %s\n", next->token->value);
		} else {
			// parse a symbol
			next->token->type = TOKEN_SYMBOL;
			next->token->value = (char *)malloc(sizeof(char));
			*next->token->value = *str;
			str++;

			printf("symbol %s\n", next->token->value);
		}
	}

	return list;
}
