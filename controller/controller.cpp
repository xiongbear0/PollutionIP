#include <iostream>
#include "Record.h"
using namespace std;

void readRecord();
void saveRecord();

Record* record = nullptr;

int main() {
    string tmp;
    while (true) {
        cout << "1. Add Record\n";
        cout << "2. Query Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Sort Record\n";
        cout << "5. Save Record\n";
        cout << "6. Exit\n";
        cout << ">> ";
        int opt;
        cin >> opt;
        switch (opt) {
            case 1:
                readRecord();
                cout << "IP: ";
                cin >> tmp;
                if (record->addRecord(tmp)) {
                    cout << "Adding success\n";
                } else {
                    cout << "Adding Fail\n";
                }
                break;
            case 2:
                readRecord();
                cout << "IP: ";
                cin >> tmp;
                if (record->queryRecord(tmp)) {
                    cout << tmp << " is exist in the list.\n";
                } else {
                    cout << tmp << " is not exist in the list.\n";
                }
                break;
            case 3:
                readRecord();
                cout << "IP: ";
                cin >> tmp;
                if (record->deleteRecord(tmp)) {
                    cout << "Delete success\n";
                } else {
                    cout << "Delete Fail\n";
                }
                break;
            case 4:
                saveRecord();
                Record::sortRecord();
                break;
            case 5:
                saveRecord();
                break;
            default:
                saveRecord();
                return 0;
        }
        cout << endl;
    }
}

void readRecord() {
    if (record == nullptr) {
        record = new Record();
    }
}

void saveRecord() {
    if (record != nullptr) {
        delete record;
        record = nullptr;
    }
}
