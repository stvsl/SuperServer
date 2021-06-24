#include "configutils.h"


Configutils::Configutils()
{
  DBIniReader();
}

//读取用户数据库配置
void Configutils::DBIniReader()
{
  QSettings settings(inipath,QSettings::IniFormat);
  u_DBStyle = settings.value("DB/DBStyle").toString();
  u_hostName = settings.value("DB/HostName").toString();
  u_port = settings.value("DB/Port").toString();
  u_userName = settings.value("DB/UserName").toString();
  u_passwd = settings.value("DB/Passwd").toString();
  u_DBFileName = settings.value("DB/DBFileName").toString();
}

//写入用户数据库配置
void Configutils::DBIniWriter(QString DBStyle,QString hostName,QString port,QString userName,QString passwd,QString DBFileName)
{
  QSettings settings(inipath,QSettings::IniFormat);
  settings.setValue("DB/DBStyle",DBStyle);
  settings.setValue("DB/HostName",hostName);
  settings.setValue("DB/Port",port);
  settings.setValue("DB/UserName",userName);
  settings.setValue("DB/Passwd",passwd);
  settings.setValue("DB/DBFileName",DBFileName);
}
