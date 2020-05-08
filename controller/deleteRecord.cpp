#include "Record.h"

int main(int argc, char* argv[]) {
    Record record;
    for (int i = 1; i < argc; ++i) {
        record.deleteRecord(argv[i]);
    }
    return 0;
}