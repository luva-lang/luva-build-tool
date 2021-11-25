#ifndef LUVA_BUILD_TOOL__TOKEN_H_
#define LUVA_BUILD_TOOL__TOKEN_H_

// define an enum that represents a token type
typedef enum {
	// a string
	TOKEN_STRING,
	// a number
	TOKEN_NUMBER,
	// a symbol
	TOKEN_SYMBOL,
	// a identifier
	TOKEN_IDENTIFIER,
	// a keyword
	TOKEN_KEYWORD,
	// a newline
	TOKEN_NEWLINE,
	// a space
	TOKEN_SPACE,
	// a tab
	TOKEN_TAB,
	// a comment
	TOKEN_COMMENT,
	// a semicolon
	TOKEN_SEMICOLON,
	// a colon
	TOKEN_COLON,
	// a comma
	TOKEN_COMMA,
	// a left parenthesis
	TOKEN_LPAREN,
	// a right parenthesis
	TOKEN_RPAREN,
	// a left bracket
	TOKEN_LBRACKET,
	// a right bracket
	TOKEN_RBRACKET,
	// a left brace
	TOKEN_LBRACE,
	// a right brace
	TOKEN_RBRACE,
} token_type_t;

// define a struct that represents a token
typedef struct {
	// the type of the token
	token_type_t type;
	// the value of the token
	char* value;
	// the line of the token
	int line;
	// the column of the token
	int column;
} token_t;

// define a struct that represents a token list
typedef struct token_list_t {
	// the token
	token_t *token;
	// the index of the token
	int index;
	// the previous token
	struct token_list_t* prev;
	// the next token
	struct token_list_t *next;
} token_list_t;

void free_token(token_t* token);
void free_token_list(token_list_t* list);

#endif // LUVA_BUILD_TOOL__TOKEN_H_