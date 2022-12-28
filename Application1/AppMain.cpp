#include "AppMain.h"
#include <QJsonParseError>
#include "services/ShareMemHelper.h"

AppMain::AppMain(QObject *parent) : QObject(parent),
    m_view(nullptr),
    m_dataModel(new DataModel(nullptr)),
    m_searchEmployee(new EmployeeSearchModel(nullptr)),
    m_selectedEmployeeId(1)
{
    // Connect signals and slots
}

AppMain::~AppMain()
{
    if (nullptr != m_view) {
        delete m_view;
        m_view = nullptr;
    }
}

void AppMain::initAppMain()
{
    if (nullptr == m_view) {
        m_view = new QQuickView;
    }

    if (nullptr != m_view) {
        qmlRegisterType<HmiEnum>("HmiEnum", 1, 0, "HmiEnum");
        qmlRegisterType<DataObject>("DataObject", 1, 0, "DataObject");
        m_view->rootContext()->setContextProperty("myAppMain", this);
        m_view->rootContext()->setContextProperty("myEmployeeModel", m_dataModel);
        m_view->rootContext()->setContextProperty("myEmployeeModel2", m_searchEmployee);
        //init model
//        onUpdateEmployeeList();
        m_dataModel->initModel();
        m_searchEmployee->setDataModel(m_dataModel);



        m_view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
        m_view->setGeometry(0, 0, 550, 950);
        m_view->show();

        //init Service
        ShareMemHelper shmem;
        shmem.readDataFromShareMem();
    }
}

void AppMain::requestToSelectEmployee(const int &_selectedEmployeeId)
{
    this->setSelectedEmployeeId(_selectedEmployeeId);
}

void AppMain::requestGetEmployeeList()
{

}

void AppMain::requestToSearchEmployeeName(const QString &_employeeName)
{
    m_searchEmployee->setFilterEmployeeName(_employeeName);
}

int AppMain::selectedEmployeeId()
{
    return m_selectedEmployeeId;
}

void AppMain::onUpdateEmployeeList()
{
    qDebug("onUpdateEmployeeList");
    QList<DataObject*> employeeListTemp;

    employeeListTemp.push_back(new DataObject(1, "Daisy Deborah", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(2, "Isabel Stella", 2, 2, 5, 3, 1));
    employeeListTemp.push_back(new DataObject(3, "Debra Beverly", 5, 1, 4, 3, 2));
    employeeListTemp.push_back(new DataObject(4, "Vera Angela", 2, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(5, "Lucy Lauren", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(6, "Janet Loretta", 4, 2, 3, 3, 1));
    employeeListTemp.push_back(new DataObject(7, "Tracey Sabrina", 5, 2, 1, 4, 1));
    employeeListTemp.push_back(new DataObject(8, "Melody Chrysta", 5, 4, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(9, "Christina Vicki", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(10, "Molly Alison", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(11, "Miranda Stephanie", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(12, "Leona Katrina", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(13, "Mila Gabriela", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(14, "Williams Harris", 5, 2, 4, 4, 1));
    employeeListTemp.push_back(new DataObject(15, "Thomas Robinson", 5, 2, 3, 5, 1));
    employeeListTemp.push_back(new DataObject(16, "Scott Nelson", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(17, "Mitchell Morgan", 5, 2, 3, 4, 1));
    employeeListTemp.push_back(new DataObject(18, "Davis Howard", 3, 2, 3, 3, 1));
    employeeListTemp.push_back(new DataObject(19, "Miller Martin", 2, 2, 2, 4, 1));
    employeeListTemp.push_back(new DataObject(20, "Smith Anderson", 4, 4, 1, 2, 1));

    m_dataModel->setList(employeeListTemp);
    m_searchEmployee->setDataModel(m_dataModel);
}

void AppMain::setSelectedEmployeeId(const int &_employeeId)
{
    if (m_selectedEmployeeId != _employeeId) {
        m_selectedEmployeeId = _employeeId;
        emit selectedEmployeeIdChanged();
    }
}
