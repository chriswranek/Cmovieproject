//
// Created by block on 05/08/2020.
//
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
    FILE *fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Cant open text file! Oops!");
        exit(1);
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
    current = head;
    while (current->next != NULL){
        current = current->next;
    }

    current->next = (node*) malloc(sizeof(node));
    current->next->f = f;
    current->next->next = NULL;
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
    current = head;

    while (current != NULL){
        printf("%s", filmToString(current->f));
        current = current->next;
    }

}