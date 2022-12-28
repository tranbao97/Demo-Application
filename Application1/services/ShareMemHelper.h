#ifndef SHAREMEMHELPER_H
#define SHAREMEMHELPER_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <bits/stdc++.h>
#include <iostream>
#include <QDebug>

#define KEY 0x02
#define SEGMENT_SIZE 0xff // 256 bytes

class ShareMemHelper {
public:
    ShareMemHelper();
    ~ShareMemHelper();

    void readDataFromShareMem();

private:
    key_t m_shareMemKey;
    int m_shareMemId;
    char* m_shareMemory;
};

#endif // SHAREMEMHELPER_H
