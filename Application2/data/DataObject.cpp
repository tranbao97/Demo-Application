#include "DataObject.h"
#include "math.h"


DataObject::DataObject(QObject *parent)
{
    Q_UNUSED(parent);
    m_employeeId = 0;
    m_assemblyScore = -1;
    m_cplplScore = -1;
    m_javaScore = -1;
    m_qmlScore = -1;
    m_openGlScore = -1;
    m_averageScore = 0;
    m_employeeName = "_";
    m_employeeGrade = "_";
}

DataObject::DataObject(const int& _employeeId, const QString& _employeeName, const int& _asssemblyScore, const int& _cppScore, const int& _javaScore, const int& _qmlScore, const int& _openglScore)
{
    m_employeeId = _employeeId;
    m_employeeName = _employeeName;
    m_assemblyScore = _asssemblyScore;
    m_cplplScore = _cppScore;
    m_javaScore = _javaScore;
    m_qmlScore = _qmlScore;
    m_openGlScore = _openglScore;
    setAverageScore(-1);
}

DataObject::~DataObject()
{

}

int DataObject::employeeId() const
{
    return m_employeeId;
}

int DataObject::assemblyScore() const
{
    return m_assemblyScore;
}

int DataObject::cplplScore() const
{
    return m_cplplScore;
}

int DataObject::javaScore() const
{
    return m_javaScore;
}

int DataObject::qmlScore() const
{
    return m_qmlScore;
}

int DataObject::openGlScore() const
{
    return m_openGlScore;
}

double DataObject::averageScore() const
{
    return m_averageScore;
}

QString DataObject::employeeName() const
{
    return m_employeeName;
}

QString DataObject::employeeGrade() const
{
    return m_employeeGrade;
}

void DataObject::setEmployeeId(const int &_employeeId)
{
    if (m_employeeId != _employeeId) {
        m_employeeId = _employeeId;
        emit employeeIdChanged();
    }
}

void DataObject::setAssemblyScore(const int &_assemblyScore)
{
    if (m_assemblyScore != _assemblyScore) {
        m_assemblyScore = _assemblyScore;
        emit assemblyScoreChanged();
    }
}

void DataObject::setCplplScore(const int &_cplplScore)
{
    if (m_cplplScore != _cplplScore) {
        m_cplplScore = _cplplScore;
        emit cplplScoreChanged();
    }
}

void DataObject::setJavaScore(const int &_javaScore)
{
    if (m_javaScore != _javaScore) {
        m_javaScore = _javaScore;
        emit javaScoreChanged();
    }
}

void DataObject::setQmlScore(const int &_qmlScore)
{
    if (m_qmlScore != _qmlScore) {
        m_qmlScore = _qmlScore;
        emit qmlScoreChanged();
    }
}

void DataObject::setOpenGlScore(const int &_openGlScore)
{
    if (m_openGlScore != _openGlScore) {
        m_openGlScore = _openGlScore;
        emit openQlScoreChanged();
    }
}

void DataObject::setAverageScore(const double& _averageScore)
{
    Q_UNUSED(_averageScore)
    m_averageScore = (std::ceil(((m_assemblyScore + m_cplplScore + m_javaScore + m_qmlScore + m_openGlScore) / 5.0) * 100.0)) / 100.0;
    emit averageScoreChanged();
}

void DataObject::setEmployeeName(const QString &_employeeName)
{
    if (m_employeeName != _employeeName) {
        m_employeeName = _employeeName;
        emit employeeNameChanged();
    }
}

void DataObject::setEmployeeGrade(const QString &_employeeGrade)
{
    if (m_employeeGrade != _employeeGrade) {
        m_employeeGrade = _employeeGrade;
        emit employeeGradeChanged();
    }
}
