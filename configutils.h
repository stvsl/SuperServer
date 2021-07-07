#ifndef CONFIGUTILS_H
#define CONFIGUTILS_H

#include <QSettings>
#include <QDebug>
#include <QVector2D>

class Configutils
{
public:
  Configutils();

public:
  /*DBIniReader与DBIniWriter用于读取和写入用户数据库配置文件*/
  //用户数据库配置读取器
  void DBIniReader();
  //用户数据库配置写入器
  void DBIniWriter(QString DBStyle,QString hostName,QString port,QString userName,QString passwd,QString DBFileName);
  /*simulationReader和simulationWriter用于读取和写入模拟数据的相关配置,同时使用重载实现*/
  //模拟数据配置读取器
  void simulationReader();
  //模拟数据配置写入器
  void simulationWriter();
  void simulationWriter(bool status);

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

  /*用户数据库操作功能配置存储*/
  //数据库模拟器开关
  bool db_simulationswitch;
  //模拟数据存放器
  QVector <QString> simulationdata;
};

#endif // CONFIGUTILS_H
