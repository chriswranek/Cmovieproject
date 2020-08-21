#include "movieDatabase.h"

int main() {
    movieDatabase *mdb = mdb_new();
    char *input = "C:\\Users\\block\\CLionProjects\\untitled4\\films.txt";
    mdb_loadFromFile(input, mdb);
    mdb_printList(mdb);
}
