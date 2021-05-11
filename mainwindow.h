#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <vector>
#include "Adresse.h"
#include "Clients.h"
#include "Particuliers.h"
#include "Professionnels.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
//using namespace std;

#define DB_FILE_NAME "C:\\Users\\Jerome.RATIER\\Documents\\reskilling\\qt\\prj\\projet_cpp_qt\\BdComptes_test.db"
#define FILE_OUT_OP_ANOMALIES "C:\\Users\\Jerome.RATIER\\Documents\\reskilling\\qt\\prj\\projet_cpp_qt\\Anomalies.log"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radBtnClientsTous_clicked();
    void on_tvClients_doubleClicked(const QModelIndex &index);
    void on_radBtnClientsPart_clicked();
    void on_radBtnClientsProf_clicked();
    void on_pushBtnClientsNom_clicked();
    void on_pushBtnClientsNum_clicked();
    void on_pushBtnImport_clicked();
    void on_radBtnComptesTous_clicked();
    void on_radBtnComptesPart_clicked();
    void on_radBtnComptesProf_clicked();
    void on_pushBtnComptesNum_clicked();

    void on_actionQuitter_triggered();

private:
    Ui::MainWindow *ui;
    void clientsCreer();
    //QSqlDatabase db;
    std::vector<Clients *> vecClients;

};
#endif // MAINWINDOW_H
