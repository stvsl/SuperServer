#ifndef CONFIGUTILS_H
#define CONFIGUTILS_H

#include <QSettings>
#include <QDebug>

class Configutils
{
public:
  Configutils();

public:
  //配置读取器
  void DBIniReader();
  //配置写入器
  void DBIniWriter(QString DBStyle,QString hostName,QString port,QString userName,QString passwd,QString DBFileName);

private:
  QString inipath = "./config";

public:
  /*用户数据库配置参数存储*/
  //数据库类型
  QString u_DBStyle;
  //主机名
  QString u_hostName;
  //端口号
  QString u_port;
  //用户名
  QString u_userName;
  //密码
  QString u_passwd;
  //数据库文件名
  QString u_DBFileName;
};

#endif // CONFIGUTILS_H
