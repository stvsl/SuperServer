#include "sqlsetdialog.h"
#include "ui_sqlsetdialog.h"

SQLSETDialog::SQLSETDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SQLSETDialog)
{
  ui->setupUi(this);
  sqlstatus = false;
}

SQLSETDialog::~SQLSETDialog()
{
  delete ui;
}

//尝试连接数据库
void SQLSETDialog::on_sqlset_tryconnect_clicked()
{   if(sqlstatus == false){
    /*数据库连接匹配*/
    if(ui->sqlset_SQLmodel->currentIndex() == 0 ){
        db = QSqlDatabase::addDatabase("QMYSQL");
      }else if(ui->sqlset_SQLmodel->currentIndex() == 1){
        db = QSqlDatabase::addDatabase("QMYSQL");
      }else if(ui->sqlset_SQLmodel->currentIndex() == 2){
        db = QSqlDatabase::addDatabase("QSQLITE");
      }
    if(ui->sqlset_hostname->text() != ""){
        db.setHostName(ui->sqlset_hostname->text());
      }
    if(ui->sqlset_port->text() != ""){
        db.setPort(ui->sqlset_port->text().toShort());
      }
    if(ui->sqlset_username->text() != ""){
        db.setUserName(ui->sqlset_username->text());
      }
    if(ui->sqlset_passwd->text() != ""){
        db.setPassword(ui->sqlset_passwd->text());
      }
    db.setDatabaseName(ui->sqlset_sqlfilename->text());
    if(db.open()){
        ui->sqlset_log->addItem("数据库连接成功！");
        ui->sqlset_savesetting->setEnabled(true);
        ui->sqlset_creattable->setEnabled(true);
        ui->sqlset_cleartable->setEnabled(true);
        ui->sqlset_deletetable->setEnabled(true);
        ui->sqlset_simulationswitch->setEnabled(true);
        ui->sqlset_inquire->setEnabled(true);
        ui->sqlset_tryconnect->setText("断开连接");
        sqlstatus = true;
      }else{
        ui->sqlset_log->addItem("数据库连接失败！");
      }
    }else{
      db.close();
      sqlstatus = false;
      ui->sqlset_log->addItem("数据库已断开！");
      ui->sqlset_savesetting->setEnabled(false);
      ui->sqlset_creattable->setEnabled(false);
      ui->sqlset_cleartable->setEnabled(false);
      ui->sqlset_deletetable->setEnabled(false);
      ui->sqlset_simulationswitch->setEnabled(false);
      ui->sqlset_inquire->setEnabled(false);
      ui->sqlset_tryconnect->setText("尝试连接");
    }

}

//创建表
void SQLSETDialog::on_sqlset_creattable_clicked()
{
  QSqlQuery dbquery;
     if(dbquery.exec(ui->sqlset_inputer->text())){
        ui->sqlset_log->addItem("表创建成功" + ui->sqlset_inputer->text());
        }else{
        ui->sqlset_log->addItem("表创建失败，请检查语法！" + ui->sqlset_inputer->text());
     }
}

//清空输入框
void SQLSETDialog::on_sqlset_inputclear_clicked()
{
    ui->sqlset_inputer->setText("");
}

//清空表数据
void SQLSETDialog::on_sqlset_cleartable_clicked()
{
   QMessageBox msg(QMessageBox::Question,"警告！","此操作将会清空表中的所有内容且不可撤销或还原，确定继续吗？",QMessageBox::Yes|QMessageBox::No);
   if (msg.exec() == QMessageBox::Yes){
      QSqlQuery dbquery;
      QString str = QString("DELETE FROM %1").arg(ui->sqlset_inputer->text());
      if(dbquery.exec(str)){
          ui->sqlset_log->addItem("数据库中的" + ui->sqlset_inputer->text() + "表已清空");
          }else{
          ui->sqlset_log->addItem("清空表"+ ui->sqlset_inputer->text() +"数据失败，请检查此表是否存在");
         }
    }else{
      ui->sqlset_log->addItem("清空操作已取消" + ui->sqlset_inputer->text());
    }
}

//删除表
void SQLSETDialog::on_sqlset_deletetable_clicked()
{
  QMessageBox msg(QMessageBox::Question,"警告！","此操作将会删除此表且所有内容",QMessageBox::Yes|QMessageBox::No);
  if(msg.exec()){
      QSqlQuery dbquery;
      if(dbquery.exec("DROP TABLE "+ui->sqlset_inputer->text()+";")){
          ui->sqlset_log->addItem("删除表" + ui->sqlset_inputer->text() +"成功！");
        }else{
          ui->sqlset_log->addItem("删除表" + ui->sqlset_inputer->text() + "失败，请检查表是否存在");
        }
    }else{
      ui->sqlset_log->addItem("清空操作已取消" + ui->sqlset_inputer->text());
    }
}

//进入查询模式
void SQLSETDialog::on_sqlset_inquire_clicked()
{
  ui->sqlset_datasqllist->setEnabled(true);
  ui->sqlset_sqlread->setEnabled(true);
  ui->sqlset_refreash->setEnabled(true);
  nextreadtable = ui->sqlset_inputer->text();
  model.setQuery("SELECT * FROM " + nextreadtable);
  ui->sqlset_datasqllist->setModel(&model);
}

