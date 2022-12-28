#ifndef SHAREMEM_H
#define SHAREMEM_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <bits/stdc++.h>

struct EmployeeInfo {
    EmployeeInfo() {}
    EmployeeInfo(const char* _name, int _averageScore) {
        std::strcpy(this->name, _name);
        this->averageScore = _averageScore;
    }

    char name[25];
    int averageScore;
};

class ShareMem {
public:
    ShareMem();
    ~ShareMem();

    void initEmployeeInfoList();
    void writeDataToShareMem();

private:
    key_t m_shareMemKey;
    int m_shareMemId;
    char* m_shareMemory;

    EmployeeInfo m_employeeList[50];
};

#endif // SHAREMEM_H
