//
// Created by block on 05/08/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "file.h"
#include <string.h>

Film *newFilm(char *name, int releaseDate, char *ageRating, char *genre,
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
    printf("New Film Created\n");
}

Film * newFilmFromString(char *arrayBuffer){
    double indexRating;
    char *p;

    indexRating = strtod(&arrayBuffer[5], &p);
    Film *filmBuffer = newFilm(&arrayBuffer[0], (int) arrayBuffer[1], &arrayBuffer[2], &arrayBuffer[3], (int) arrayBuffer[4], indexRating);
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
    char returnString[30];
    sprintf(returnString, "%s, %d, %s, %s, %d, %f", f->name,
            f->releaseDate, f->ageRating, f->genre, f->runtime, f->rating);
    return returnString;
}
