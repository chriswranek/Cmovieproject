//
// Created by block on 05/08/2020.
//
#ifndef UNTITLED4_file_H
#define UNTITLED4_file_H

#endif //UNTITLED4_file_H

typedef struct FilmStruct{
    char *name;
    int releaseDate;
    char *ageRating;
    char *genre;
    int runtime;
    double rating;
} Film;

Film *newFilm(char *name, int releaseDate,
                            char *ageRating, char *genre, int runtime, double rating);

Film *newFilmFromString(char *stringLine);

void freeFilmMem(Film *f);

char *getFilmTitle(const Film *f);

int getFilmYear(const Film *f);

char *getFilmAgeRating(const Film *f);

char *getFilmGenre(const Film *f);

int getFilmDuration(const Film *f);

double getFilmRating(const Film *f);

char *filmToString(Film *f);