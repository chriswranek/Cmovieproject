//
// Created by block on 05/08/2020.
//
#ifndef UNTITLED4_movieDatabase_H
#define UNTITLED4_movieDatabase_H

#endif //UNTITLED4_movieDatabase_H
#include "file.h"



//Node Struct
typedef struct nodeStruct {
    Film *f;
    struct nodeStruct *next;
} node;

//Movie Database Struct
typedef struct movieDatabaseStruct {
    node* first;
    node* last;
} movieDatabase;

struct movieDatabaseStruct *mdb_new();

void mdb_freeMem(movieDatabase* mdb);

void mdb_addFilm(movieDatabase *mdb, Film *f);

void mdb_loadFromFile(char *fileName, movieDatabase *mdb);

void mdb_printList(movieDatabase *mdb);