#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "metric_convertor.h"

void file_to_double_array (char *file_name, int ip_index, double *convo_buffer){

    FILE *fp = fopen("length_convo_factor_table.txt","r");

    if (fp == NULL){
        printf("Cant open file\n");
        return;
    }

    char buff[1024], *token, *eptr;

    for (int i=0; i<ip_index; i++){
        fgets(buff, 1024, fp);
    }

    token = strtok(buff,",");
    convo_buffer[0] = strtod(token, &eptr);
    for (int i=1; i<4; i++){
        token = strtok(NULL,",");
        convo_buffer[i] = strtod(token, &eptr);
    }
    return;

}