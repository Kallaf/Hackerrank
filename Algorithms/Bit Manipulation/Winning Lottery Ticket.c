#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the winningLotteryTicket function below.
long winningLotteryTicket(int n, char** tickets) {
    long codes[1030] = {0};
    for(int i=0;i<n;i++)
    {
        int m = strlen(tickets[i]);
        long count[15] = {0};
        for(int j=0;j<m;j++)
            count[tickets[i][j]-'0']++;
            
        int code = 0;
        for(int j=0;j<10;j++)
            if(count[j])code += 1 << j;
        codes[code]++;
    }
    long ans = 0;
    for(int i=0;i<1023;i++)
        for(int j=i+1;j<1024;j++)
            if((i|j) == 1023)ans += codes[i]*codes[j];
    ans += codes[1023]*(codes[1023]-1)/2;            
    return ans;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** tickets = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* tickets_item = readline();

        *(tickets + i) = tickets_item;
    }

    int tickets_count = n;

    long result = winningLotteryTicket(tickets_count, tickets);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
