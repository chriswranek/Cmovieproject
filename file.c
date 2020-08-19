//
// Created by block on 05/08/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include <string.h>

struct FilmStruct *newFilm(char *name, int releaseDate, char *ageRating, char *genre,
                            int runtime, double rating) {

    Film *f = (Film*)malloc(sizeof(Film));

    if (f == NULL){
        fprintf(stderr, "Unable to allocate memory to new film struct\n");
        exit(EXIT_FAILURE);
    }

    f->name = name;
    f->releaseDate = releaseDate;
    f->ageRating = ageRating;
    f->genre = genre;
    f->runtime = runtime;
    f->rating = rating;
}

struct FilmStruct *newFilmFromString(char *stringLine){
    int fieldCount = 0;
    int i = 0;
    double indexRating;
    char *p;
    char *field = strtok(stringLine, ",");
    char *arrayBuffer[6];

    while(field != NULL){
        arrayBuffer[i++] = field;
        field = strtok(NULL, ",");
        fieldCount++;
    }

    indexRating = strtod(arrayBuffer[5], &p);
    struct FilmStruct *filmBuffer = newFilm(arrayBuffer[0], (int) arrayBuffer[1], arrayBuffer[2], arrayBuffer[3], (int) arrayBuffer[4], indexRating);
    for (i = 0; i < 6; i++){
        printf("%s\n", arrayBuffer[i]);
    }

    return filmBuffer;
}

char *getFilmTitle(const Film *f){
    return f->name;
}

int getFilmYear(const Film *f){
    return f->releaseDate;
}

char *getFilmAgeRating(const Film *f){
    return f->ageRating;
}

char *getFilmGenre(const Film *f){
    return f->genre;
}

int getFilmDuration(const Film *f){
    return f->runtime;
}

double getFilmRating(const Film *f){
    return f->rating;
}

char *filmToString(Film *f){
    printf(f->name, f->releaseDate, f->ageRating, f->genre, f->runtime, f->rating);
}
