#ifndef SQLSETDIALOG_H
#define SQLSETDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "configutils.h"

namespace Ui {
  class SQLSETDialog;
}

class SQLSETDialog : public QDialog
{
  Q_OBJECT

public:
  explicit SQLSETDialog(QWidget *parent = nullptr);
  ~SQLSETDialog();


private:
  Ui::SQLSETDialog *ui;
  //外部数据库连接器
  QSqlDatabase db;
  //查询请求器
  QSqlQueryModel model;
  //数据库连接状态
  bool sqlstatus;
  //数据库操作器
  QSqlQuery query;
  //配置管理器
  Configutils configutils;

private slots:
  //初始化
  void initialization();
  //尝试连接
  void on_sqlset_tryconnect_clicked();
  //创建表
  void on_sqlset_creattable_clicked();
  //清空输入框
  void on_sqlset_inputclear_clicked();
  //清空表
  void on_sqlset_cleartable_clicked();
  //删除表
  void on_sqlset_deletetable_clicked();
  //查询表
  void on_sqlset_inquire_clicked();
  //保存配置功能
  void on_sqlset_savesetting_clicked();
  //删除配置功能
  void on_sqlset_deleteconfig_clicked();
  //模拟数据开关
  void on_sqlset_simulationswitch_clicked();
};

#endif // SQLSETDIALOG_H
