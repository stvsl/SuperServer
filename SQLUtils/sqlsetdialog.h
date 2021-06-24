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
  QSqlDatabase *db;
  //保存查询结果
  QSqlQueryModel model;
  //数据库连接状态
  bool sqlstatus;
  //配置管理器
  Configutils configutils;

private slots:
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

  void on_sqlset_inquire_clicked();

  void on_sqlset_savesetting_clicked();
  void on_sqlset_deleteconfig_clicked();
};

#endif // SQLSETDIALOG_H
