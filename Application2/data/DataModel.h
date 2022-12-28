#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QVector>
#include <QAbstractListModel>
#include "DataObject.h"
#include <QtCore/qsortfilterproxymodel.h>

class DataModel : public QAbstractListModel {
    Q_OBJECT

public:
    DataModel(QObject *parent = nullptr);
    ~DataModel();
    enum RoleNames {
        EmployeeIdRole = Qt::UserRole,
        EmployeeNameRole,
        EmployeeGradeRole,
        AssemblyScoreRole,
        CplplScoreRole,
        JavaScoreRole,
        QmlScoreRole,
        OpenGlScoreRole,
        AverageScoreRole
    };

    void setList(const QList<DataObject*> &listData);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    void updateData(int idx, int role, QVariant value);
    //bool setDataByEmployeeId(const int &employeeId, const QVariant &value, int role);

    Q_INVOKABLE QVariant getData(const int &index, int role) const;
    Q_INVOKABLE QVariant getDataByEmployeeId(const int &employeeId, int role) const;
    Q_INVOKABLE int getIndexFromEmployeeId(const int &employeeId) const;
    Q_INVOKABLE DataObject* getDataByEmployeeId(const int &employeeId);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void refreshAll();
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<DataObject*> m_employeeData;
};

class EmployeeSearchModel : public QSortFilterProxyModel {
    Q_OBJECT

public:
    explicit EmployeeSearchModel(QObject *parent = 0);

    void setDataModel(DataModel* _dataModel);
    DataObject* getDataModelByEmployeeId(const int& _employeeId) const;

    void setFilterEmployeeName(const QString& _text);
    bool filterAcceptsRow(int _sourceRow, const QModelIndex& _sourceParent) const Q_DECL_OVERRIDE;

private:
    DataModel* m_model;
};

#endif // DATAMODEL_H
