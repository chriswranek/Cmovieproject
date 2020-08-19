#include <stdio.h>
#include <string.h>
#include "movieDatabase.h"

int main() {
    movieDatabase *mdb = mdb_new();
    char *input = "films.txt";
    mdb_loadFromFile(input, mdb);
}
