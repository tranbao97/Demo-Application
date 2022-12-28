#include "DataModel.h"

DataModel::DataModel(QObject *parent) : QAbstractListModel(parent)
{

}

DataModel::~DataModel()
{
    if (m_employeeData.isEmpty() == false) {
        qDeleteAll(m_employeeData.begin(), m_employeeData.end());
        m_employeeData.clear();
    }
}

void DataModel::setList(const QList<DataObject *> &listData)
{
    // beginResetModel();
    if (m_employeeData.isEmpty() == false) {
        // clear old data
        qDeleteAll(m_employeeData.begin(), m_employeeData.end());
    }

    if (m_employeeData.count() < listData.count()) {
        this->insertRows(m_employeeData.count(), listData.count() - m_employeeData.count(), QModelIndex());
    } else if (m_employeeData.count() > listData.count()) {
        this->removeRows(listData.count(), m_employeeData.count() - listData.count(), QModelIndex());
    }

    m_employeeData = listData;
    refreshAll();
    // endResetModel();
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_employeeData.size();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    QVariant resultVar;
    if( (0 <= row) && (m_employeeData.size() > row))
    {
        switch(role) {
        case EmployeeIdRole:
            resultVar = m_employeeData.at(row)->employeeId();
            break;
        case EmployeeNameRole:
            resultVar = m_employeeData.at(row)->employeeName();
            break;
        case EmployeeGradeRole:
            resultVar = m_employeeData.at(row)->employeeGrade();
            break;
        case AssemblyScoreRole:
            resultVar = m_employeeData.at(row)->assemblyScore();
            break;
        case CplplScoreRole:
            resultVar = m_employeeData.at(row)->cplplScore();
            break;
        case JavaScoreRole:
            resultVar = m_employeeData.at(row)->javaScore();
            break;
        case QmlScoreRole:
            resultVar = m_employeeData.at(row)->qmlScore();
            break;
        case OpenGlScoreRole:
            resultVar = m_employeeData.at(row)->openGlScore();
            break;
        case AverageScoreRole:
            resultVar = m_employeeData.at(row)->averageScore();
            break;
        default:
            break;
        }
    }
    return resultVar;
}

bool DataModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row + count  - 1);
    endInsertRows();
    return true;
}

bool DataModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    endRemoveRows();
    return true;
}

void DataModel::initModel()
{
    m_employeeData.push_back(new DataObject(1, "Daisy Deborah", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(2, "Isabel Stella", 2, 2, 5, 3, 1));
    m_employeeData.push_back(new DataObject(3, "Debra Beverly", 5, 1, 4, 3, 2));
    m_employeeData.push_back(new DataObject(4, "Vera Angela", 2, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(5, "Lucy Lauren", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(6, "Janet Loretta", 4, 2, 3, 3, 1));
    m_employeeData.push_back(new DataObject(7, "Tracey Sabrina", 5, 2, 1, 4, 1));
    m_employeeData.push_back(new DataObject(8, "Melody Chrysta", 5, 4, 3, 4, 1));
    m_employeeData.push_back(new DataObject(9, "Christina Vicki", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(10, "Molly Alison", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(11, "Miranda Stephanie", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(12, "Leona Katrina", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(13, "Mila Gabriela", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(14, "Williams Harris", 5, 2, 4, 4, 1));
    m_employeeData.push_back(new DataObject(15, "Thomas Robinson", 5, 2, 3, 5, 1));
    m_employeeData.push_back(new DataObject(16, "Scott Nelson", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(17, "Mitchell Morgan", 5, 2, 3, 4, 1));
    m_employeeData.push_back(new DataObject(18, "Davis Howard", 5, 2, 3, 3, 1));
    m_employeeData.push_back(new DataObject(19, "Miller Martin", 5, 2, 2, 4, 1));
    m_employeeData.push_back(new DataObject(20, "Smith Anderson", 5, 4, 1, 2, 1));
}

QVariant DataModel::getData(const int &index, int role) const
{
    QVariant resultVar;
    if( (0 <= index) && (m_employeeData.size() > index))
    {
        switch(role) {
        case EmployeeIdRole:
            resultVar = m_employeeData.at(index)->employeeId();
            break;
        case EmployeeNameRole:
            resultVar = m_employeeData.at(index)->employeeName();
            break;
        case EmployeeGradeRole:
            resultVar = m_employeeData.at(index)->employeeGrade();
            break;
        case AssemblyScoreRole:
            resultVar = m_employeeData.at(index)->assemblyScore();
            break;
        case CplplScoreRole:
            resultVar = m_employeeData.at(index)->cplplScore();
            break;
        case JavaScoreRole:
            resultVar = m_employeeData.at(index)->javaScore();
            break;
        case QmlScoreRole:
            resultVar = m_employeeData.at(index)->qmlScore();
            break;
        case OpenGlScoreRole:
            resultVar = m_employeeData.at(index)->openGlScore();
            break;
        case AverageScoreRole:
            resultVar = m_employeeData.at(index)->averageScore();
            break;
        default:
            break;
        }
    }
    return resultVar;
}

QVariant DataModel::getDataByEmployeeId(const int &employeeId, int role) const
{
    QVariant resultVar;
    int nFound = -1;

    for (int nIndex = 0; nIndex < m_employeeData.size(); nIndex++) {
        if (m_employeeData[nIndex]->employeeId() == employeeId) {
            nFound = nIndex;
            break;
        }
    }

    if (nFound != -1) {
        resultVar = getData(nFound, role);
    }

    return resultVar;
}

DataObject* DataModel::getDataByEmployeeId(const int &employeeId)
{
    DataObject* pData = nullptr;

    for (int nIndex = 0; nIndex < m_employeeData.size(); nIndex++) {
        if (m_employeeData[nIndex]->employeeId() == employeeId) {
            pData = m_employeeData[nIndex];
        }
    }

    return pData;
}

void DataModel::clear()
{
    if(!m_employeeData.isEmpty()) {
        beginRemoveRows(QModelIndex(), 0, m_employeeData.count() - 1);
        qDeleteAll(m_employeeData.begin(), m_employeeData.end());
        m_employeeData.clear();
        endRemoveRows();
    }
}

void DataModel::refreshAll()
{
    for (int i = 0; i < m_employeeData.size(); i++) {
        emit dataChanged(index(i), index(i));
    }
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[EmployeeIdRole] = "employeeId";
    roles[EmployeeNameRole] = "employeeName";
    roles[EmployeeGradeRole] = "employeeGrade";
    roles[AssemblyScoreRole] = "assemblyScore";
    roles[CplplScoreRole] = "cplplScore";
    roles[JavaScoreRole] = "javaScore";
    roles[QmlScoreRole] = "qmlScore";
    roles[OpenGlScoreRole] = "openGlScore";
    roles[AverageScoreRole] = "averageScore";
    return roles;
}

EmployeeSearchModel::EmployeeSearchModel(QObject *parent)
{
    Q_UNUSED(parent);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void EmployeeSearchModel::setDataModel(DataModel *_dataModel)
{
    qDebug("setDataModel");
    m_model = _dataModel;
    QSortFilterProxyModel::setSourceModel(m_model);
}

DataObject *EmployeeSearchModel::getDataModelByEmployeeId(const int &_employeeId) const
{
    if (m_model == nullptr) {
        return new DataObject();
    }
    return m_model->getDataByEmployeeId(_employeeId);
}

//DataObject EmployeeSearchModel::getDataModelByEmployeeId(const int &_employeeId) const
//{
//    if (m_model == nullptr) {
//        return new DataObject();
//    }

//    return m_model->getDataByEmployeeId(_employeeId);
//}

void EmployeeSearchModel::setFilterEmployeeName(const QString &_text)
{
    setFilterFixedString(_text);
}

bool EmployeeSearchModel::filterAcceptsRow(int _sourceRow, const QModelIndex &_sourceParent) const
{
    const QModelIndex index = m_model->index(_sourceRow, 0, _sourceParent);
    const QString name = index.data(DataModel::EmployeeNameRole).toString();

    return name.contains(filterRegExp());
}
