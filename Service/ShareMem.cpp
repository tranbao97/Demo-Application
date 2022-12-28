#include "ShareMem.h"
#include <stdlib.h>

#define KEY 0x02
#define SEGMENT_SIZE 0xff // 256 bytes

ShareMem::ShareMem()
{
    m_shareMemKey = ftok("/dev/shm", KEY);
    std::cout << "Created key: " << m_shareMemKey << "\n";

    //Get share memory
    if ((m_shareMemId = shmget(m_shareMemKey, SEGMENT_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("Cannot retrive shared memory");
        exit(EXIT_FAILURE);
    }

    initEmployeeInfoList();
}

ShareMem::~ShareMem()
{

}

void ShareMem::initEmployeeInfoList()
{
    std::cout << "initEmployeeInfoList\n";

    m_employeeList[0] = EmployeeInfo("Daisy", 5);
    m_employeeList[1] = EmployeeInfo("Isabel", 2);
    m_employeeList[2] = EmployeeInfo("Debra", 3);
    m_employeeList[3] = EmployeeInfo("Angela", 2);
    m_employeeList[4] = EmployeeInfo("Lucy", 3);
    m_employeeList[5] = EmployeeInfo("Janet", 4);
}

void ShareMem::writeDataToShareMem()
{
    std::cout << "writeDataToShareMem\n";
    // Attach the shared memory.
    // NULL let the operating system choose where to allocate the memory
    if ((m_shareMemory = (char*)shmat(m_shareMemId, NULL, 0)) == nullptr) {
        perror("Shared memory cannot be attached");
        exit(EXIT_FAILURE);
    };

    // Print data
    memcpy(m_shareMemory, m_employeeList, sizeof(m_employeeList));
    for (int i = 0; i < 30; i++) {
        std::cout << (int)*(m_shareMemory + i) << " " ;
    }

    // Detach
    if(shmdt(m_shareMemory) == -1){
        perror("Shared memory cannot be detached");
        exit(EXIT_FAILURE);
    }
}
