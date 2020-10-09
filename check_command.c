#include "main.h"

// returns appopriate number for the call
int check_command(char* input, char** token){
    if (strncmp("quit", input, 4)==0) return 0;
    else if (strncmp("create", input, 5)==0) return 1;
    else if ((strncmp("dumpdata", input, 8)==0)&&(token[1][0]=='l')) return 2; // if its is a list and dumpdata   
    else if (strncmp("list_push_back", input, 14)==0) return 3;
    else if (strncmp("list_push_front", input, 14)==0) return 4;
    else if (strncmp("delete", input, 6)==0) return 5;
    else if (strncmp("list_pop_back", input, 13)==0) return 6;
    else if (strncmp("list_push_back", input, 14)==0) return 7;
    else if (strncmp("list_remove", input, 11)==0) return 8;
    else if (strncmp("list_reverse", input, 12)==0) return 9;
    else if ((strncmp("delete", input, 6)==0)&&(token[1][0]=='l')) return 10;
    else if (strncmp("list_empty", input, 10)==0) return 11;
    else if (strncmp("list_size", input, 9)==0) return 12;
    else if (strncmp("list_max", input, 8)==0) return 13;
    else if (strncmp("list_min", input, 8)==0) return 14;
    else if (strncmp("list_insert_ordered", input, 19)==0) return 15;
    else if (strncmp("list_back", input, 9)==0) return 16;
    else if (strncmp("list_unique", input, 11)==0) return 17;
    else if (strncmp("list_swap", input, 9)==0) return 18;
    else if (strncmp("list_splice", input,11)==0) return 19;
    else if (strncmp("list_shuffle", input, 12)==0) return 20;
    else if (strncmp("list_sort", input, 9)==0) return 21;
}
