#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>
#include <QString>

class DataObject: public QObject {
    Q_OBJECT
    Q_PROPERTY(int employeeId READ employeeId WRITE setEmployeeId NOTIFY employeeIdChanged)
    Q_PROPERTY(int assemblyScore READ assemblyScore WRITE setAssemblyScore NOTIFY assemblyScoreChanged)
    Q_PROPERTY(int cplplScore READ cplplScore WRITE setCplplScore NOTIFY cplplScoreChanged)
    Q_PROPERTY(int javaScore READ javaScore WRITE setJavaScore NOTIFY javaScoreChanged)
    Q_PROPERTY(int qmlScore READ qmlScore WRITE setQmlScore NOTIFY qmlScoreChanged)
    Q_PROPERTY(int openGlScore READ openGlScore WRITE setOpenGlScore NOTIFY openQlScoreChanged)
    Q_PROPERTY(double averageScore READ averageScore WRITE setAverageScore NOTIFY averageScoreChanged)
    Q_PROPERTY(QString employeeName READ employeeName WRITE setEmployeeName NOTIFY employeeNameChanged)
    Q_PROPERTY(QString employeeGrade READ employeeGrade WRITE setEmployeeGrade NOTIFY employeeGradeChanged)

public:
    explicit DataObject(QObject *parent = nullptr);
    DataObject(const int& _employeeId, const QString& _employeeName, const int& _asssemblyScore, const int& _cppScore, const int& _javaScore, const int& _qmlScore, const int& _openglScore);
    ~DataObject();
    int employeeId() const;
    int assemblyScore() const;
    int cplplScore() const;
    int javaScore() const;
    int qmlScore() const;
    int openGlScore() const;
    double averageScore() const;
    QString employeeName() const;
    QString employeeGrade() const;

private:
    int m_employeeId;
    int m_assemblyScore;
    int m_cplplScore;
    int m_javaScore;
    int m_qmlScore;
    int m_openGlScore;
    double m_averageScore;
    QString m_employeeName;
    QString m_employeeGrade;

public slots:
    void setEmployeeId(const int &_employeeId);
    void setAssemblyScore(const int &_assemblyScore);
    void setCplplScore(const int &_cplplScore);
    void setJavaScore(const int &_javaScore);
    void setQmlScore(const int  &_qmlScore);
    void setOpenGlScore(const int &_openGlScore);
    void setAverageScore(const double& _averageScore);
    void setEmployeeName(const QString &_employeeName);
    void setEmployeeGrade(const QString &_employeeGrade);

signals:
    void employeeIdChanged();
    void assemblyScoreChanged();
    void cplplScoreChanged();
    void javaScoreChanged();
    void qmlScoreChanged();
    void openQlScoreChanged();
    void averageScoreChanged();
    void employeeNameChanged();
    void employeeGradeChanged();
};

#endif // DATAOBJECT_H
