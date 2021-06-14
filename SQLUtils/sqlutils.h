#ifndef SQLUTILS_H
#define SQLUTILS_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

namespace Ui {
  class SQLSETDialog;
  class SuperServerMainWindow;
}

class SQLUtils
{

public:
  void prepareIni();

private:
  //内部数据库
  QSqlDatabase selfdb;
};

#endif // SQLUTILS_H
