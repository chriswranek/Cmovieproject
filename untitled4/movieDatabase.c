//
// Created by block on 05/08/2020.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "movieDatabase.h"

struct node *head = NULL;
struct node *current = NULL;

void traverseList(void) {
    struct nodeStruct *root;

    struct nodeStruct *leadPointer;

    root = malloc(sizeof(struct nodeStruct));
    root->next = 0;
    root->f = (Film *) 12;
    leadPointer = root;
    if (leadPointer != 0) {
        while (leadPointer->next != 0){
            leadPointer = (struct nodeStruct *) leadPointer->next;
        }
    }

    leadPointer->next = malloc(sizeof(struct nodeStruct));

    leadPointer = leadPointer->next;

    if(leadPointer == 0){
        printf("Run out of memory");
    }
    leadPointer->next = 0;
    leadPointer->f = (Film *) 42;
}

void mdb_loadFromFile(char *fileName, movieDatabase *mdb){
    FILE *fp = fopen(fileName, "r");

    if(!fp) {
        printf("Cant open text file! Oops!");
    }
    char buffer[1024];
    int row_count = 0;
    while (fgets(buffer, 1024, fp)) {
        row_count++;
        if (row_count == 1) {
            continue;
        }
        mdb_addFilm(mdb, newFilmFromString(buffer));
        printf("\n");
    }
    fclose(fp);
}

void mdb_addFilm(movieDatabase *mdb, Film *f){

}

struct movieDatabaseStruct *mdb_new(){

}
