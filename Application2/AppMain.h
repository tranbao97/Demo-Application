#ifndef APPMAIN_H
#define APPMAIN_H

#include <QObject>
#include <QQmlError>
#include <QQuickView>
#include <QQmlContext>
#include "data/DataModel.h"
#include "HmiEnum.h"
#include <QJsonObject>
#include <QFile>
#include <QJsonArray>

class AppMain : public QObject {
    Q_OBJECT

    Q_PROPERTY(int selectedEmployeeId READ selectedEmployeeId WRITE setSelectedEmployeeId NOTIFY selectedEmployeeIdChanged)

public:
    explicit AppMain(QObject *parent = nullptr);
    ~AppMain();

    void initAppMain();

    Q_INVOKABLE void requestToSelectEmployee(const int& _selectedEmployeeId);
    Q_INVOKABLE void requestGetEmployeeList();
    Q_INVOKABLE void requestToSearchEmployeeName(const QString& _employeeName);
    Q_INVOKABLE void requestToUpdateEmployeeInfo(const int& _employeeId, const QString& _employeeName, const int& _assemblyScore, const int& _cppScore, const int& _javaScore, const int& _qmlScore, const int& _openglScore);

    int selectedEmployeeId();
signals:

    void selectedEmployeeIdChanged();
public slots:
    void onUpdateEmployeeList();

    void setSelectedEmployeeId(const int &_employeeId);

private:
    QQuickView* m_view;
    DataModel *m_dataModel;
    EmployeeSearchModel *m_searchEmployee;

    int m_selectedEmployeeId;
    QJsonObject m_employee;
    QJsonArray m_arrEmployees;
};

#endif // APPMAIN_H
