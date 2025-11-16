#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Token types
typedef enum {
    NUMBER,
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    LPAREN,
    RPAREN,
    END,
    ERROR
} Token_Type;

// Token structure
typedef struct {
    Token_Type type;
    char* value;
} Token;

// Function to tokenize input string
Token* lexer(char* input_string) {
    Token* tokens = (Token*) malloc(strlen(input_string) * sizeof(Token));
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int pos = 0;
    int token_index = 0;
    while (input_string[pos] != '\0') {
        // Skip whitespace
        if (isspace(input_string[pos])) {
            pos++;
            continue;
        }

        // Check for numbers
        if (isdigit(input_string[pos])) {
            int start = pos;
            while (isdigit(input_string[pos]))
                pos++;
            int length = pos - start;
            char* number = (char*) malloc((length + 1) * sizeof(char));
            strncpy(number, input_string + start, length);
            number[length] = '\0';
            tokens[token_index].type = NUMBER;
            tokens[token_index].value = number;
            token_index++;
            continue;
        }

        // Check for operators and parentheses
        switch (input_string[pos]) {
            case '+':
                tokens[token_index].type = PLUS;
                tokens[token_index].value = "+";
                token_index++;
                break;
            case '-':
                tokens[token_index].type = MINUS;
                tokens[token_index].value = "-";
                token_index++;
                break;
            case '*':
                tokens[token_index].type = TIMES;
                tokens[token_index].value = "*";
                token_index++;
                break;
            case '/':
                tokens[token_index].type = DIVIDE;
                tokens[token_index].value = "/";
                token_index++;
                break;
            case '(':
                tokens[token_index].type = LPAREN;
                tokens[token_index].value = "(";
                token_index++;
                break;
            case ')':
                tokens[token_index].type = RPAREN;
                tokens[token_index].value = ")";
                token_index++;
                break;
            default:
                fprintf(stderr, "Invalid character encountered: %c\n", input_string[pos]);
                tokens[token_index].type = ERROR;
                tokens[token_index].value = NULL;
                token_index++;
                break;
        }

        pos++;
    }

    // Add END token
    tokens[token_index].type = END;
    tokens[token_index].value = NULL;

    return tokens;
}

// Function to free tokens
void free_tokens(Token* tokens) {
    Token* t = tokens;
    while (t->type != END) {
        free(t->value);
        t++;
    }
    free(tokens);
}

// Function to print tokens (for debugging)
void print_tokens(Token* tokens) {
    Token* t = tokens;
    while (t->type != END) {
        printf("Token(type=%d, value='%s')\n", t->type, t->value);
        t++;
    }
}jai

// Example usage
int main() {
    char input_string[] = "3 + 42 * (15 - 7)";
    Token* tokens = lexer(input_string);

    // Print tokens (for debugging)
    print_tokens(tokens);

    // Free tokens
    free_tokens(tokens);

    return 0;
}
