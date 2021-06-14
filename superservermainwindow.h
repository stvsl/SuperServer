#ifndef SUPERSERVERMAINWINDOW_H
#define SUPERSERVERMAINWINDOW_H

#include <QMainWindow>
//数据库处理工具
#include "SQLUtils/sqlsetdialog.h"
#include "NetWorkUtils/NetWorkUtils.h"
#include "SQLUtils/sqlutils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SuperServerMainWindow; }
QT_END_NAMESPACE

class SuperServerMainWindow : public QMainWindow, public SQLUtils
{
  Q_OBJECT

public:
  SuperServerMainWindow(QWidget *parent = nullptr);
  ~SuperServerMainWindow();

private slots:
  //服务器开/关
  void on_ServerSwitch_clicked();

  //数据库开/关
  void on_SQLSwitch_clicked();

  //安全服务器开/关（防洪水攻击）
  void on_SafeDebug_clicked();

  //清空运行日志
  void on_LogClear_clicked();

  //导出日志
  void on_LogOutput_clicked();

  //清理异常Socket连接
  void on_ClearMissSocket_clicked();

  //SQL数据库恢复
  void on_RecoverSQL_clicked();

  //数据库变化比对
  void on_SQLComparison_clicked();

  //模拟返回数据
  void on_SimulationReturn_clicked();

  //数据分析
  void on_DataAnalysis_clicked();

  //数据控制
  void on_DataControl_clicked();

  //本地测试（模拟客户端实现器）
  void on_LocalTest_clicked();

  void on_SQLSetting_triggered();

  void on_ConnectSQL_triggered();

private:
  Ui::SuperServerMainWindow *ui;
  bool serverstatus;
  bool SQLstatus;
  bool safeserverstatus;
  //创建服务器对象
  QTcpServer server;
  //创建无符号整形16比特位的端口保存变量
  quint16 port;
  //保存套接字列表的容器
  QList<QTcpSocket*> tcpClientList;
  //数据库设置界面
  SQLSETDialog sqlset;
};
#endif // SUPERSERVERMAINWINDOW_H

/*矫聪 我爱你*/
