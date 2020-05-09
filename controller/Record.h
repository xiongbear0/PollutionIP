#ifndef CONTROLLER_RECORD_H
#define CONTROLLER_RECORD_H

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Record {
public:
    Record();

    ~Record();

    bool addRecord(const string& ip);

    bool queryRecord(const string& ip);

    bool deleteRecord(const string& ip);

    static void sortRecord();

    static short compare(const string& ip1, const string& ip2);

private:
    vector<string> record;
    static const string FILE_LOC;
};

const string Record::FILE_LOC = "../ip-list.txt";

Record::Record() {
    ifstream fin(FILE_LOC);
    string buf;
    while (fin >> buf) {
        record.push_back(buf);
    }
    fin.close();
}

Record::~Record() {
    ofstream fout(FILE_LOC);
    for (string& str : record) {
        fout << str << '\n';
    }
    fout.close();
}

bool Record::addRecord(const string& ip) {
    for (vector<string>::iterator it = record.begin(); it < record.end(); ++it) {
        int res = Record::compare(*it, ip);
        if (res == -1) {
            record.insert(it, ip);
            return true;
        } else if (res == 0) {
            return false;
        }
    }
    record.push_back(ip);
    return true;
}

bool Record::queryRecord(const string& ip) {
    vector<string>::iterator it = find(record.begin(), record.end(), ip);
    return it != record.end();
}

bool Record::deleteRecord(const string& ip) {
    vector<string>::iterator iterator = find(record.begin(), record.end(), ip);
    if (iterator != record.end()) {
        record.erase(iterator);
        return true;
    }
    return false;
}

short Record::compare(const string& ip1, const string& ip2) {
    int num1[4];
    int num2[4];
    char tmp;

    stringstream sin1(ip1);
    sin1 >> num1[0] >> tmp >> num1[1] >> tmp >> num1[2] >> tmp >> num1[3];
    stringstream sin2(ip2);
    sin2 >> num2[0] >> tmp >> num2[1] >> tmp >> num2[2] >> tmp >> num2[3];

    for (int i = 0; i < 4; ++i) {
        if (num1[i] < num2[i]) {
            return 1;
        } else if (num1[i] > num2[i]) {
            return -1;
        }
    }
    return 0;
}

void Record::sortRecord() {
    string tmp = "sort -n " + FILE_LOC + " -o " + FILE_LOC;
    const char* command = tmp.c_str();
    system(command);
}


#endif //CONTROLLER_RECORD_H
