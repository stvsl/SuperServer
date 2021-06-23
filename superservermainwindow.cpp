#include "superservermainwindow.h"
#include "ui_superservermainwindow.h"
#include "SQLUtils/sqlutils.h"

SuperServerMainWindow::SuperServerMainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::SuperServerMainWindow)
{
  ui->setupUi(this);
  //加载初始化数据库
  self = new SQLUtils;
  //执行调用函数
  self->prepareIni();

}

SuperServerMainWindow::~SuperServerMainWindow()
{
  delete ui;
}

//服务器开/关
void SuperServerMainWindow::on_ServerSwitch_clicked()
{

}

//数据库开/关
void SuperServerMainWindow::on_SQLSwitch_clicked()
{

}

//安全服务器开/关（防洪水攻击）
void SuperServerMainWindow::on_SafeDebug_clicked()
{

}

//清空运行日志
void SuperServerMainWindow::on_LogClear_clicked()
{

}

//导出日志
void SuperServerMainWindow::on_LogOutput_clicked()
{

}

//清理异常Socket连接
void SuperServerMainWindow::on_ClearMissSocket_clicked()
{

}

//SQL数据库恢复
void SuperServerMainWindow::on_RecoverSQL_clicked()
{

}

//数据库变化比对
void SuperServerMainWindow::on_SQLComparison_clicked()
{

}

//模拟返回数据
void SuperServerMainWindow::on_SimulationReturn_clicked()
{

}

//数据解析器
void SuperServerMainWindow::on_DataAnalysis_clicked()
{

}

//数据控制
void SuperServerMainWindow::on_DataControl_clicked()
{

}

//本地测试（模拟客户端实现器）
void SuperServerMainWindow::on_LocalTest_clicked()
{

}

//打开数据库设置
void SuperServerMainWindow::on_SQLSetting_triggered()
{
  sqlset.show();
  sqlset.exec();
}

//关闭外连数据库
void SuperServerMainWindow::on_ConnectSQL_triggered()
{

}

//系统异常退出
void SuperServerMainWindow::systemExit()
{
  close();
}
