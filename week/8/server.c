#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define BUFF_SIZE 32
#define FLAG_SIZE 32
#define PASS_SIZE 16

int main_prompt(void) {
    char *result;
    char input[BUFF_SIZE];

    printf("Choose an option:\n");
    printf("1. encrypt\n");
    printf("2. decrypt\n");
    printf("3. authenticate\n");
    printf("4. execute command\n");
    printf("0. exit\n");
    printf("> ");
    fflush(stdout);

    result = fgets(input, BUFF_SIZE, stdin);
    if (result == 0) return 0;
    return atoi(input);
}

void cipher(void) {
    int i, len;
    char input[BUFF_SIZE+1], output[BUFF_SIZE+1], c;

    printf("Please provide message to cipher: \n");
    fflush(stdout);
    fgets(input, BUFF_SIZE+1, stdin);
    len = strlen(input);
    for (i = 0; i < len; i++) {
        c = input[i];
        if (c >= 'a' && c <= 'm') c += 13;
        else if (c >= 'A' && c <= 'M') c += 13;
        else if (c >= 'n' && c <= 'z') c -= 13;
        else if (c >= 'N' && c <= 'Z') c -= 13;
        output[i] = c;
    }
    output[len] = 0;
    printf(output);
    fflush(stdout);
}

uint8_t elevate(char *password) {
    char input[BUFF_SIZE+1];

    printf("Please provide admin password: \n");
    fflush(stdout);
    fgets(input, BUFF_SIZE+1, stdin);

    return !strncmp(password, input, PASS_SIZE);
}

void exec_command(void) {
    int i;
    // create a whitelist of valid user commands
    char commands[64] = "ping www.google.com\nls /var/log\ndate\n";
    char buff[BUFF_SIZE+1];

    printf("Admin, provide a command to execute: ");
    fflush(stdout);
    gets(buff);
    buff[BUFF_SIZE] = 0;

    if (strcasestr(commands, buff) == 0) {
        printf("Unable to locate %s in {%s}\n", buff, commands);
        fflush(stdout);
    } else {
        printf("Executing \"%s\"\n", buff);
        fflush(stdout);
        system(buff);
    }
}

int main(void) {
    int i, prompt_response;
    /* password for admin to provide to dump flag */
    char *password;
    /* true if user is admin */
    uint8_t admin;

    /* seed random with time so that we can password */
    srand(time(0));
    admin = 0;
    password = calloc(1, PASS_SIZE+1);
    for (i = 0; i < PASS_SIZE; i++) {
        password[i] = rand() % ('z'-' ') + ' ';
    }
    password[PASS_SIZE] = 0;

    while ((prompt_response = main_prompt()) != 0) {
        if (prompt_response == 1 || prompt_response == 2) {
            cipher();
        } else if (prompt_response == 3) {
            if ((admin = elevate(password)) == 0) {
                printf("Password failed!\n");
                fflush(stdout);
            } else {
                printf("password successful, privilege elevated\n");
                fflush(stdout);
            }
        } else if (prompt_response == 4) {
            if (admin) {
                exec_command();
            } else {
                printf("Unable to execute command without admin privileges!\n");
                fflush(stdout);
            }
        }
    }

    free(password);
    printf("Goodbye!\n");
    fflush(stdout);
}