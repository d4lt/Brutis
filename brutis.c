#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_CHAR '!'
#define LAST_CHAR '~'


typedef struct {
    size_t capacity;
    size_t length;
    char* token;
} Token_buffer;

void cycle_chars(Token_buffer tkb, size_t index) {
    // if (tkb.token[index] == LAST_CHAR) {
    //     tkb.token[index] = FIRST_CHAR;
    //     if tkb.token[index+1]
    // }
}

int is_finaltoken(Token_buffer tkb) {
    for (size_t i = 0; i < tkb.length; i++) {
        if (tkb.token[i] != LAST_CHAR) {
            return 0;
        } 
        else if (tkb.token[i] > LAST_CHAR) {
            printf("Char in index %d is bigger than LAST_CHAR", i);
            exit(-1);
        }
    }
    return 1;
};

int main(int argc, char *argv[]) {

    if (argc > 2) {
        perror("Please only specify the maximum length:\nUsage: brutis <max_len>\n");
        return -1;
    }

    size_t max_len = atoi(argv[1]);
    Token_buffer tk_buff = {
        .capacity = max_len,
        .length = 1,
        .token = (char*) malloc(sizeof(char) * max_len)
    };
    for (tk_buff.length = 1; tk_buff.length <= tk_buff.capacity; tk_buff.length++) { 
        for (size_t i = 0; i < tk_buff.length; i++){
            tk_buff.token[i] = FIRST_CHAR;
        }

        while (!is_finaltoken(tk_buff)) {
            printf("%d: %s/n", tk_buff.length, tk_buff.token);
            if (tk_buff.token[0] == LAST_CHAR) {
                cycle_chars(tk_buff);
            } else {
                tk_buff.token[0]++;
            }
        }
    }

    return 0;
} 