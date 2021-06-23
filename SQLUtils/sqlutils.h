#ifndef SQLUTILS_H
#define SQLUTILS_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
  class SQLSETDialog;
  class SuperServerMainWindow;
}

class SQLUtils
{

public:
  //数据库初始化
  void prepareIni();
  //系统数据库表创建
  void createConfig();
  //系统数据库内容读取
  void systemReader();
  //系统数据库内容写入
  void systemWriter();

public:
  /*配置读取器*/
  //数据库主机名
  QString s_userHostName;
  //用户端口号
  short s_userPort;
  //用户名
  QString s_userName;
  //用户密码
  QString s_userPasswd;
  //用户数据库名
  QString s_userDataBaseName;
  //*//
  /*TODO*/
private:
  //内部数据库
  QSqlDatabase selfdb;

};

#endif // SQLUTILS_H
