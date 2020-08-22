//
// Created by block on 05/08/2020.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "movieDatabase.h"

node *head = NULL;
node *current = NULL;

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
    int i;
    char buffer[1024];
    char *arrayBuffer[6];
    FILE *fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Cant open text file! Oops!");
        exit(1);
    }

    while(fgets(buffer, 1024, fp)){
        char *field;
        field = strtok(buffer, ",");
        while(field != NULL){
            for(i = 1; i <= 6; i++){
                printf("%s", field);
                arrayBuffer[i-1] = field;
                field = strtok(NULL, ",");
            }
        }
        Film *newFilm = newFilmFromString(arrayBuffer);
        mdb_addFilm(mdb, newFilm);
    }

    fclose(fp);

}

void mdb_addFilm(movieDatabase *mdb, Film *f){
    current = mdb->first;
    while (current->next != NULL){
        current = current->next;
        printf("next film");
    }

    current->next = (node*) malloc(sizeof(node));
    current->next->f = f;
    current->next->next = NULL;
    printf("Film added to database");
}

movieDatabase *mdb_new(){
    movieDatabase *mbd = malloc(sizeof(movieDatabase));
    node *const first = NULL;
    node *const last = NULL;
    mbd->first = first;
    mbd->last = last;
    return mbd;
}

void mdb_printList(movieDatabase *mdb){
    current = mdb->first;

    while (current != NULL){
        printf("%s", filmToString(current->f));
        current = current->next;
    }

}