#include "ShareMemHelper.h"

ShareMemHelper::ShareMemHelper()
{
    m_shareMemKey = ftok("/dev/shm", KEY);
    std::cout << "Created key: " << m_shareMemKey << "\n";

    //Get share memory
    if ((m_shareMemId = shmget(m_shareMemKey, SEGMENT_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("Cannot retrive shared memory");
        exit(EXIT_FAILURE);
    }
}

ShareMemHelper::~ShareMemHelper()
{

}

void ShareMemHelper::readDataFromShareMem()
{
    if((m_shareMemory = (char*)shmat(m_shareMemId, NULL, SHM_RDONLY)) == nullptr){
        perror("Shared memory cannot be attached");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 30; i++) {
        qDebug() << (int)*(m_shareMemory + i);
    }

    qDebug() << "m_shareMemory: " << m_shareMemory;
    // Detach
    if(shmdt(m_shareMemory) == -1){
        perror("Shared memory cannot be detached");
        exit(EXIT_FAILURE);
    }
}
