#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 100

int main() {
    char lines[MAX_LINES][MAX_LINE_LENGTH]; // 2D array to store lines of text
    char query[MAX_LINE_LENGTH]; // array to store user's search query
    int line_num = 0; // current line number
    int i; // loop counter
    
    // read lines of text from user until maximum number of lines is reached or user enters an empty line
    printf("Enter text (maximum %d lines, press enter on an empty line to finish):\n", MAX_LINES);
    while (line_num < MAX_LINES) {
        fgets(lines[line_num], MAX_LINE_LENGTH, stdin);
        if (strcmp(lines[line_num], "\n") == 0) {
            break;
        }
        line_num++;
    }
    
    // ask user for search query
    printf("Enter search query: ");
    fgets(query, MAX_LINE_LENGTH, stdin);
    query[strcspn(query, "\n")] = '\0'; // remove trailing newline character
    
    // search for query in each line of text and print any matching lines
    printf("Matching lines:\n");
    for (i = 0; i < line_num; i++) {
        if (strstr(lines[i], query) != NULL) {
            printf("%s", lines[i]);
        }
    }
    
    return 0;
}
