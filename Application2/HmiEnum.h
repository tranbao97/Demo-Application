#ifndef HMIENUM_H
#define HMIENUM_H

#include <QObject>
#include <data/DataModel.h>

class HmiEnum : public QObject {
    Q_OBJECT

public:
    HmiEnum(QObject *parent = 0);

    enum HMI_ROLE_NAME {
        E_HMI_ROLE_EMPLOYEE_ID = Qt::UserRole,
        E_HMI_ROLE_EMPLOYEE_NAME,
        E_HMI_ROLE_EMPLOYEE_GRADE,
        E_HMI_ROLE_ASSEMBLY_SCORE,
        E_HMI_ROLE_CPP_SCORE,
        E_HMI_ROLE_JAVA_SCORE,
        E_HMI_ROLE_QML_SCORE,
        E_HMI_ROLE_OPENGL_SCORE,
        E_HMI_ROLE_AVERAGE_SCORE
    };

    Q_ENUM(HMI_ROLE_NAME)
};

#endif // HMIENUM_H
