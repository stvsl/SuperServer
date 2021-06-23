#include "sqlutils.h"
#include "superservermainwindow.h"

void SQLUtils::prepareIni()
{
  //连接系统数据库
  qDebug() << "正在连接系统数据库";
  selfdb = QSqlDatabase::addDatabase("QSQLITE","SYSTEMDB");
  selfdb.setDatabaseName("SYSTEMDB");
//  selfdb.setPassword("jiaocong");
//  selfdb.setUserName("system");
  selfdb.open();
  createConfig();
}

//初始化创建系统数据表操作
void SQLUtils::createConfig()
{
  qDebug() << "开始初始化";
  QSqlQuery query(selfdb);
  QString str = QString("CREATE TABLE SystemConfig ("
                        "DBStyle TEXT，"
                        "s_userHostName TEXT,"
                        "s_userPort INT,"
                        "s_userName TEXT,"
                        "s_userPasswd TEXT,"
                        "s_userDataBaseName TEXT,"
                        ");");
  if(query.exec(str)){
      qDebug() << "未发现系统数据库表，进入初始运行模式，数据库表已创建";
  }else{
      qDebug() << "开始初始化配置信息";
      systemReader();
    }
}

//系统数据库读取
void SQLUtils::systemReader()
{
  qDebug() << "正在读取配置信息";

}

//系统数据库写入
void SQLUtils::systemWriter()
{
  qDebug() << "正在写入配置信息";
  QSqlQuery query;
  QString str = QString("INSERT INTO SystemConfig VALUES ('%1',)");
  query.exec(str);
}
