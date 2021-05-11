#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Listing des clients
    clientsCreer();


    //clients detruire;
    //for(auto val: vecClients){ delete val; val=nullptr; };
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clientsCreer()
{
    //vector prjDemo34
    //std:vector<T>un_vecteur;
    //Clients *ClientObj = new Clients(
    //    1, "n",
    //    "adrLibelle", "adrComplem", 12000, "VILLE", "mail@com" );
    //vecClients.push_back(ClientObj);

    //Particuliers
    //  int, string,  string, string, int, string, string,     int, int, int, string, char);
    //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
    Particuliers *ParticuliersObj1 = new Particuliers
      ( 1, "BETY"   , "12, rue des Oliviers"    , ""       , 94000, "CRETEIL"           , "bety@gmail.com"   , 1985, 11, 12, "Daniel"   , 'M');
    vecClients.push_back(ParticuliersObj1);
    Particuliers *ParticuliersObj2 = new Particuliers
      ( 3, "BODIN"  , "10, rue des Oliviers"    , "Etage 2", 94300, "VINCENNES"         , "bodin@gmail.com"  , 1965, 05, 05, "Justin"   , 'M');
    vecClients.push_back(ParticuliersObj2);
    Particuliers *ParticuliersObj3 = new Particuliers
      ( 5, "BERRIS" , "15, rue de la République", ""       , 94120, "FONTENAY SOUS BOIS", "berris@gmail.com" , 1977, 06, 06, "Karine"   , 'F');
    vecClients.push_back(ParticuliersObj3);
    Particuliers *ParticuliersObj4 = new Particuliers
      ( 7, "ABENIR" , "25, rue de la Paix"      , ""       , 92100, "LA DEFENSE"        , "abenir@gmail.com" , 1977, 04, 12, "Alexandra", 'F');
    vecClients.push_back(ParticuliersObj4);
    Particuliers *ParticuliersObj5 = new Particuliers
      ( 9, "BENSAID", "3, avenue des Parcs"     , ""       , 93500, "ROISSY EN France"  , "bensaid@gmail.com", 1978, 04, 16, "Georgia"  , 'F');
    vecClients.push_back(ParticuliersObj5);
    Particuliers *ParticuliersObj6 = new Particuliers
      (11, "ABABOU" , "3, rue Lecourbe"         , ""       , 93200, "BAGNOLET"          , "ababou@gmail.com" , 1970, 10, 10, "Teddy"    , 'M');
    vecClients.push_back(ParticuliersObj6);

    //Professionnels
    //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
    //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
    Professionnels *ProfessionnelsObj1 = new Professionnels
      ( 2, "AXA"     , "125, rue LaFayette"      , "Digicode 1432", 94120, "FONTENAY SOUS BOIS", "info@axa.fr"        , "12548795641122", "SARL", "125, rue LaFayette"         , "Digicode 1432", 94120, "FONTENAY SOUS BOIS");
    vecClients.push_back(ProfessionnelsObj1);
    Professionnels *ProfessionnelsObj2 = new Professionnels
      ( 4, "PAUL"    , "36, quai des Orfèvres"   , ""             , 93500, "ROISSY EN France"  , "info@paul.fr"       , "87459564455444", "EURL", "10, esplanade de la Défense", ""             , 92060, "LA DEFENSE"        );
    vecClients.push_back(ProfessionnelsObj2);
    Professionnels *ProfessionnelsObj3 = new Professionnels
      ( 6, "PRIMARK" , "32, rue E. Renan"        , "Bat. C"       , 75002, "PARIS"             , "contact@primark.fr" , "08755897458455", "SARL", "32, rue E. Renan"           , "Bat. C"       , 75002, "PARIS"             );
    vecClients.push_back(ProfessionnelsObj3);
    Professionnels *ProfessionnelsObj4 = new Professionnels
      ( 8, "ZARA"    , "23, av P. Valery"        , ""             , 92100, "LA DEFENSE"        , "info@zara.fr"       , "65895874587854", "SA"  , "24, esplanade de la Défense", "Tour Franklin", 92060, "LA DEFENSE"        );
    vecClients.push_back(ProfessionnelsObj4);
    Professionnels *ProfessionnelsObj5 = new Professionnels
      (10, "LEONIDAS", "15, Place de la Bastille", "Fond de Cour" , 75003, "PARIS"             , "contact@leonidas.fr", "91235987456832", "SAS" , "10, rue de la Paix"         , ""             , 75008, "PARIS"             );
    vecClients.push_back(ProfessionnelsObj5);
}

void MainWindow::on_radBtnClientsTous_clicked()
{
    //vecClients Nom Prenom Id
    //vecClients.at(val);

    ui->linEdClientNom->clear();
    ui->linEdClientNum->clear();
    ui->lblClients->clear();


    //headers
    QStandardItemModel *modelClients = new QStandardItemModel;
    modelClients->setHorizontalHeaderItem(0, new QStandardItem("Identifiant"));
    modelClients->setHorizontalHeaderItem(1, new QStandardItem("Nom"));
    modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));

    QString identifiantS;
    QString nom;
    QString prenom;

    string lineIn;
    string clientsField[13];
    for(auto val: vecClients){
        //qDebug() << val;
        //qDebug() << QString::fromStdString(val->ToString());

        QList<QStandardItem *> item;
        istringstream iss(val->ToString());
        int i = 0;
        while (getline(iss, clientsField[i++], ';'));

        Particuliers *Part = dynamic_cast<Particuliers*>(val);
        if (Part != nullptr)
        {
            //Particuliers
            //  int, string,  string, string, int, string, string,     int, int, int, string, char);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            prenom = QString::fromStdString(clientsField[10]);
            //qDebug() << "Particulier " << identifiantS << " " <<nom << " " << prenom;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            item.append(new QStandardItem(prenom));
        }

        Professionnels *Prof = dynamic_cast<Professionnels*>(val);
        if (Prof != nullptr)
        {
            //Professionnels
            //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            //qDebug() << "Professionnel " << identifiantS << " " <<nom ;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
        }
        modelClients->appendRow(item);
    };
    ui->tvClients->setModel(modelClients);
    ui->tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
/*
    //QT13DemoBDD
    //QtExo10_DbTableViewSelect
    db = QSqlDatabase::addDatabase("QSQLITE"); //driverSQLITE
    db.setDatabaseName(DB_FILE_NAME);
    db.open();
    QSqlQueryModel *modelClients = new QSqlQueryModel();
    modelClients->setQuery("select CustomerId as 'Numero', LastName as 'Nom', FirstName as 'Prénom' FROM customers");
    ui->tvClients->setModel(modelClients);
    ui->tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    db.close();
*/
}

void MainWindow::on_tvClients_doubleClicked(const QModelIndex &index)
{

    //Comptes clear
    ui->linEdCompteNum->clear();
    ui->lblComptes->clear();

    //button radio release
    ui->radBtnComptesTous->setAutoExclusive(false);
    ui->radBtnComptesTous->setChecked(false);
    ui->radBtnComptesTous->setAutoExclusive(true);

    ui->radBtnComptesPart->setAutoExclusive(false);
    ui->radBtnComptesPart->setChecked(false);
    ui->radBtnComptesPart->setAutoExclusive(true);

    ui->radBtnComptesProf->setAutoExclusive(false);
    ui->radBtnComptesProf->setChecked(false);
    ui->radBtnComptesProf->setAutoExclusive(true);


    QString numeroSelected = index.siblingAtColumn(0).data().toString();
    //qDebug() << "numeroSelected " << numeroSelected;

    QString identifiantS = "";
    string clientsField[13];
    for(auto val: vecClients){
        //qDebug() << val;
        istringstream iss(val->ToString());
        int i = 0;
        while (getline(iss, clientsField[i++], ';'));
        identifiantS = QString::fromStdString(clientsField[0]);
        if ( numeroSelected != identifiantS )
            continue;
        //qDebug() << "numeroSelected " << numeroSelected;

        ui->lblClients->setText("");
        QString clientsQS;

        Particuliers *Part = dynamic_cast<Particuliers*>(val);
        if (Part != nullptr)
        {
            //Particuliers
            //  int, string,  string, string, int, string, string,     int, int, int, string, char);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
            clientsQS = "Particulier : " + identifiantS + "\n\n\t";
            if ( QString::fromStdString(clientsField[11]) == "M" )
                clientsQS += "M. ";
            else if ( QString::fromStdString(clientsField[11]) == "F" )
                clientsQS += "Mme. ";
            clientsQS += QString::fromStdString(clientsField[1]);   //nom
            clientsQS += " " + QString::fromStdString(clientsField[10]);   //prenom
            clientsQS += "\n\t" + QString::fromStdString(clientsField[2]);   //adrLibelle
            if ( QString::fromStdString(clientsField[3]) != "" )
                clientsQS += "\n\t" + QString::fromStdString(clientsField[3]);   //adrComplem
            clientsQS += "\n\t" + QString::fromStdString(clientsField[4]);   //adrCodPost
            clientsQS += " " + QString::fromStdString(clientsField[5]);   //adrVILLE
            clientsQS += "\n\tAge : " + QString::number(Part->age());
            if (Part->anniversaire())
                clientsQS += " et Bon Anniversaire !";
            clientsQS += "\n\tDate de naissance : " + QString::fromStdString(clientsField[9]);  //parDateNJ
            clientsQS += "/" + QString::fromStdString(clientsField[8]); //parDateNM
            clientsQS += "/" + QString::fromStdString(clientsField[7]); //parDateNA
            clientsQS += "\n\n\tMail : " + QString::fromStdString(clientsField[6]); //mail
        }

        Professionnels *Prof = dynamic_cast<Professionnels*>(val);
        if (Prof != nullptr)
        {
            //Professionnels
            //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
            clientsQS = "Professionnel : " + identifiantS + "\n\n\t";
            clientsQS += "Siret : " + QString::fromStdString(clientsField[7]);   //siret
            clientsQS += "\n\t" + QString::fromStdString(clientsField[8]);   //statut
            clientsQS += " " + QString::fromStdString(clientsField[1]);   //nom
            clientsQS += "\n\t" + QString::fromStdString(clientsField[2]);   //AdrLibelle
            if ( QString::fromStdString(clientsField[3]) != "" )
                clientsQS += "\n\t" + QString::fromStdString(clientsField[3]);   //AdrComplem
            clientsQS += "\n\t" + QString::fromStdString(clientsField[4]);   //AdrCodPost
            clientsQS += " " + QString::fromStdString(clientsField[5]);   //AdrVILLE
            clientsQS += "\n\n\tMail : " + QString::fromStdString(clientsField[6]);   //mail

            //si adr client different adr siege, alors out adr siege
            if (    ( QString::fromStdString(clientsField[2]) != QString::fromStdString(clientsField[9]) )
                 || ( QString::fromStdString(clientsField[3]) != QString::fromStdString(clientsField[10]) )
                 || ( QString::fromStdString(clientsField[4]) != QString::fromStdString(clientsField[11]) )
                 || ( QString::fromStdString(clientsField[5]) != QString::fromStdString(clientsField[12]) )
               ) {
                clientsQS += "\n\nSiege :\n\t" + QString::fromStdString(clientsField[9]);   //pAdrLibelle
                if ( QString::fromStdString(clientsField[10]) != "" )
                    clientsQS += "\n\t" + QString::fromStdString(clientsField[10]);   //pAdrComplem
                clientsQS += "\n\t" + QString::fromStdString(clientsField[11]);   //pAdrCodPost
                clientsQS += " " + QString::fromStdString(clientsField[12]);   //pAdrVILLE
            }
        }
        ui->lblClients->setText(clientsQS);
        break;
    }//for


    //db

    //QString identifiantS = "";
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
    db.setDatabaseName(DB_FILE_NAME);
    if ( db.open() ){
        //qDebug() << "db.open() true";
        QString reqSQL =
            "SELECT numcompte, datecreation, solde, decouvert, numcli"
            " FROM comptes"
            " WHERE numcli = '" + identifiantS + "' "
            " ORDER BY numcompte ;";
        //qDebug() << "reqSQL " << reqSQL;
        QSqlQuery query(reqSQL, db);

        //nom client from vecClients
        QString nom;
        string clientsField[13];
        for(auto val: vecClients){
            //qDebug() << val;
            istringstream iss(val->ToString());
            int i = 0;
            while (getline(iss, clientsField[i++], ';'));
            if ( QString::fromStdString(clientsField[0]) == identifiantS )
            {
                nom = QString::fromStdString(clientsField[1]);
                break;
            }
        }
        //qDebug() << "nom=" << nom;

        //headers
        QStandardItemModel *model = new QStandardItemModel;
        model->setHorizontalHeaderItem(0, new QStandardItem("Numero de compte"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Date creation"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Solde"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Decouvert"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Numero client"));
        model->setHorizontalHeaderItem(5, new QStandardItem("Nom"));

        while(query.next())
        {
            //qDebug() << "query.next()" ;
            QString numcompte = query.value("numcompte").toString();
            QString datecreation = query.value("datecreation").toString();
            QString solde = query.value("solde").toString();
            QString decouvert = query.value("decouvert").toString();
            QString numcli = query.value("numcli").toString();
            //qDebug() << "numcompte=" << numcompte << " datecreation=" << datecreation
            //         << " solde=" << solde    << " decouvert=" << decouvert
            //         << " numcli=" << numcli  ;
            QList<QStandardItem *> item;
            item.append(new QStandardItem(numcompte));
            item.append(new QStandardItem(datecreation));
            item.append(new QStandardItem(solde));
            item.append(new QStandardItem(decouvert));
            item.append(new QStandardItem(numcli));
            item.append(new QStandardItem(nom));
            model->appendRow(item);

        }//while

        ui->tvComptes->setModel(model);
        ui->tvComptes->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tvComptes->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tvComptes->setEditTriggers(QAbstractItemView::NoEditTriggers);

        db.close();
    }else{
        //qDebug() << "Erreur db.open() false";
        ui->lblClients->setText("Erreur db.open() false");
    }

/*
    db.open();
    QSqlQuery query(db);
    QString reqSQL = "SELECT CustomerId, LastName, FirstName, Address, city, Country, Email "
                     "from customers where CustomerId = :pNumero ";
    query.prepare(reqSQL);
    query.bindValue(":pNumero", numeroSelected);
    bool queryOk = query.exec();
    qDebug() << "queryOk " <<queryOk;
    bool repOK =  query.next();
    //qDebug() << "repOK " <<  repOK;
    //bool repOK = true;
    if (repOK == true)
    {
        QString infos  = QString("Client N°%1\n%2 %3\n%4\n%5 %6\n%7")
                            .arg(query.value("CustomerId").toString())
                            .arg(query.value("LastName").toString())
                            .arg(query.value("FirstName").toString())
                            .arg(query.value("Address").toString())
                            .arg(query.value("city").toString())
                            .arg(query.value("Country").toString())
                            .arg(query.value("Email").toString());
        ui->lblClients->setText(infos);
    }
    db.close();
*/
}

void MainWindow::on_radBtnClientsPart_clicked()
{
    //vecClients Nom Prenom Id
    //vecClients.at(val);

    ui->linEdClientNom->clear();
    ui->linEdClientNum->clear();
    ui->lblClients->clear();

    //headers
    QStandardItemModel *modelClients = new QStandardItemModel;
    modelClients->setHorizontalHeaderItem(0, new QStandardItem("Identifiant"));
    modelClients->setHorizontalHeaderItem(1, new QStandardItem("Nom"));
    modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));

    QString identifiantS;
    QString nom;
    QString prenom;

    string lineIn;
    string clientsField[13];
    for(auto val: vecClients){
        //qDebug() << val;
        //qDebug() << QString::fromStdString(val->ToString());

        QList<QStandardItem *> item;
        istringstream iss(val->ToString());
        int i = 0;
        while (getline(iss, clientsField[i++], ';'));

        Particuliers *Part = dynamic_cast<Particuliers*>(val);
        if (Part != nullptr)
        {
            //Particuliers
            //  int, string,  string, string, int, string, string,     int, int, int, string, char);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            prenom = QString::fromStdString(clientsField[10]);
            //qDebug() << "Particulier " << identifiantS << " " <<nom << " " << prenom;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            item.append(new QStandardItem(prenom));
            modelClients->appendRow(item);
        }
/*
        Professionnels *Prof = dynamic_cast<Professionnels*>(val);
        if (Prof != nullptr)
        {
            //Professionnels
            //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            //qDebug() << "Professionnel " << identifiantS << " " <<nom ;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
        }
        modelClients->appendRow(item);
*/
    };
    //ui->tvClients->reset();
    ui->tvClients->setModel(modelClients);
    ui->tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_radBtnClientsProf_clicked()
{
    //vecClients Nom Prenom Id
    //vecClients.at(val);

    ui->linEdClientNom->clear();
    ui->lblClients->clear();

    //headers
    QStandardItemModel *modelClients = new QStandardItemModel;
    modelClients->setHorizontalHeaderItem(0, new QStandardItem("Identifiant"));
    modelClients->setHorizontalHeaderItem(1, new QStandardItem("Nom"));
    //modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));

    QString identifiantS;
    QString nom;
    //QString prenom;

    string lineIn;
    string clientsField[13];
    for(auto val: vecClients){
        //qDebug() << val;
        //qDebug() << QString::fromStdString(val->ToString());

        QList<QStandardItem *> item;
        istringstream iss(val->ToString());
        int i = 0;
        while (getline(iss, clientsField[i++], ';'));

/*
        Particuliers *Part = dynamic_cast<Particuliers*>(val);
        if (Part != nullptr)
        {
            //Particuliers
            //  int, string,  string, string, int, string, string,     int, int, int, string, char);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            prenom = QString::fromStdString(clientsField[10]);
            //qDebug() << "Particulier " << identifiantS << " " <<nom << " " << prenom;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            item.append(new QStandardItem(prenom));
            modelClients->appendRow(item);
        }
*/

        Professionnels *Prof = dynamic_cast<Professionnels*>(val);
        if (Prof != nullptr)
        {
            //Professionnels
            //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            //qDebug() << "Professionnel " << identifiantS << " " <<nom ;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            modelClients->appendRow(item);
        }
    };
    //ui->tvClients->reset();
    ui->tvClients->setModel(modelClients);
    ui->tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_pushBtnClientsNom_clicked()
{
    //linEdClientNom

    //button radio release
    ui->radBtnClientsTous->setAutoExclusive(false);
    ui->radBtnClientsTous->setChecked(false);
    ui->radBtnClientsTous->setAutoExclusive(true);

    ui->radBtnClientsPart->setAutoExclusive(false);
    ui->radBtnClientsPart->setChecked(false);
    ui->radBtnClientsPart->setAutoExclusive(true);

    ui->radBtnClientsProf->setAutoExclusive(false);
    ui->radBtnClientsProf->setChecked(false);
    ui->radBtnClientsProf->setAutoExclusive(true);

    QString valNom = (ui->linEdClientNom->text()).toUpper();
    //qDebug() <<"valNom="<<valNom;
    ui->linEdClientNom->clear();
    ui->linEdClientNum->clear();
    ui->lblClients->clear();

    if ( valNom.isEmpty() )
    {
        //qDebug() << "Nom vide";
        ui->lblClients->setText("Nom vide");
        return;
    }

    //headers
    QStandardItemModel *modelClients = new QStandardItemModel;
    modelClients->setHorizontalHeaderItem(0, new QStandardItem("Identifiant"));
    modelClients->setHorizontalHeaderItem(1, new QStandardItem("Nom"));
    //modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));

    QString identifiantS = "";
    QString nom = "";
    QString prenom;

    string lineIn;
    string clientsField[13];
    for(auto val: vecClients){
        //qDebug() << val;
        //qDebug() << QString::fromStdString(val->ToString());

        QList<QStandardItem *> item;
        istringstream iss(val->ToString());
        int i = 0;
        while (getline(iss, clientsField[i++], ';'));

        Particuliers *Part = dynamic_cast<Particuliers*>(val);
        if (    ( Part != nullptr )
             && ( valNom == QString::fromStdString(clientsField[1]) )
           )
        {
            modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));
            //Particuliers(
            //  int, string,  string, string, int, string, string,     int, int, int, string, char);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            prenom = QString::fromStdString(clientsField[10]);
            //qDebug() << "Particulier " << identifiantS << " " <<nom << " " << prenom;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            item.append(new QStandardItem(prenom));
            modelClients->appendRow(item);
            break;
        }

        Professionnels *Prof = dynamic_cast<Professionnels*>(val);
        if (    ( Prof != nullptr )
             && ( valNom == QString::fromStdString(clientsField[1]) )
           )
        {
            //Professionnels(
            //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            //qDebug() << "Professionnel " << identifiantS << " " <<nom ;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            modelClients->appendRow(item);
            break;
        }
    } //for

    if ( nom != "" )
    {
        //ui->tvClients->reset();
        ui->tvClients->setModel(modelClients);
        ui->tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tvClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }else{
        //qDebug() << "Nom \"" + valNom  + "\" absent";
        ui->lblClients->setText("Nom \"" + valNom  + "\" absent");
        ui->tvClients->reset();
    }
}

void MainWindow::on_pushBtnClientsNum_clicked()
{
    //linEdClientNum

    //button radio release
    ui->radBtnClientsTous->setAutoExclusive(false);
    ui->radBtnClientsTous->setChecked(false);
    ui->radBtnClientsTous->setAutoExclusive(true);

    ui->radBtnClientsPart->setAutoExclusive(false);
    ui->radBtnClientsPart->setChecked(false);
    ui->radBtnClientsPart->setAutoExclusive(true);

    ui->radBtnClientsProf->setAutoExclusive(false);
    ui->radBtnClientsProf->setChecked(false);
    ui->radBtnClientsProf->setAutoExclusive(true);

    QString valNum = ui->linEdClientNum->text();
    //qDebug() <<"valNum="<<valNum;

    ui->linEdClientNom->clear();
    ui->linEdClientNum->clear();
    ui->lblClients->clear();

    if ( valNum.isEmpty() )
    {
        //qDebug() << "Numero vide";
        ui->lblClients->setText("Numero vide");
        return;
    }
    valNum = valNum.rightJustified(5, '0');
    //qDebug() <<"valNum="<<valNum;

    //headers
    QStandardItemModel *modelClients = new QStandardItemModel;
    modelClients->setHorizontalHeaderItem(0, new QStandardItem("Identifiant"));
    modelClients->setHorizontalHeaderItem(1, new QStandardItem("Nom"));
    //modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));

    QString identifiantS = "";
    QString nom = "";
    QString prenom;

    string lineIn;
    string clientsField[13];
    for(auto val: vecClients){
        //qDebug() << val;
        //qDebug() << QString::fromStdString(val->ToString());

        QList<QStandardItem *> item;
        istringstream iss(val->ToString());
        int i = 0;
        while (getline(iss, clientsField[i++], ';'));

        Particuliers *Part = dynamic_cast<Particuliers*>(val);
        if (    ( Part != nullptr )
             && ( valNum == QString::fromStdString(clientsField[0]) )
           )
        {
            modelClients->setHorizontalHeaderItem(2, new QStandardItem("Prenom"));
            //Particuliers
            //  int, string,  string, string, int, string, string,     int, int, int, string, char);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            prenom = QString::fromStdString(clientsField[10]);
            //qDebug() << "Particulier " << identifiantS << " " <<nom << " " << prenom;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            item.append(new QStandardItem(prenom));
            modelClients->appendRow(item);
            break;
        }

        Professionnels *Prof = dynamic_cast<Professionnels*>(val);
        if (    ( Prof != nullptr )
             && ( valNum == QString::fromStdString(clientsField[0]) )
           )
        {
            //Professionnels
            //  int, string,  string, string, int, string, string,           string, string, string string, int, string);
            //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail siret statut pAdrLibelle pAdrComplem pAdrCodPost pAdrVILLE
            identifiantS = QString::fromStdString(clientsField[0]);
            nom = QString::fromStdString(clientsField[1]);
            //qDebug() << "Professionnel " << identifiantS << " " <<nom ;
            item.append(new QStandardItem(identifiantS));
            item.append(new QStandardItem(nom));
            modelClients->appendRow(item);
            break;
        }
    } //for

    if ( nom != "" )
    {
        //ui->tvClients->reset();
        ui->tvClients->setModel(modelClients);
        ui->tvClients->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tvClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tvClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }else{
        //qDebug() << "Numero \"" + valNum  + "\" absent";
        ui->lblClients->setText("Numero \"" + valNum  + "\" absent");
        ui->tvClients->reset();
    }
}


void MainWindow::on_pushBtnImport_clicked()
{
    //ui->txtbOp

    ostringstream oss;

    //fileIn
//QString fileInNameQs = "C:\\Users\\Jerome.RATIER\\Documents\\reskilling\\qt\\prj\\projet_cpp_qt\\Operations.txt";
    QString fileInNameQs = QFileDialog::getOpenFileName(
        this,
        "Selectionner fichier Operations.txt",
        "",
        "Operations (*.txt)");
    //qDebug() << "fileInNameQs=" << fileInNameQs;
    string fileInName = fileInNameQs.toStdString();
    //oss.str(""); oss << "fileInName=" << fileInName;
    //qDebug() << QString::fromStdString(oss.str());
    if (fileInName == "")
        return;
    ifstream fileIn(fileInName);
    if( !fileIn )
    {
        //qDebug() << "Erreur open fichier entree \" + fileInNameQs + "\"";
        ui->txtbOp->clear();
        ui->txtbOp->setText("Erreur open fichier entree \"" + fileInNameQs + "\"");
        return;
    }

    //fileOut
    string fileOutName = FILE_OUT_OP_ANOMALIES;
    //ofstream fileOut(fileOutName);
    ofstream fileOut;
    fileOut.open(fileOutName, ios_base::app);
    if ( ! fileOut )
    {
        //qDebug() << "Erreur open fichier sortie anomalies \" + QString::fromStdString(fileOutName) + "\"";
        ui->txtbOp->clear();
        ui->txtbOp->setText("Erreur open fichier sortie anomalies \"" + QString::fromStdString(fileOutName) + "\"");
        return;
    }

    bool txtbOp_used = false;

    string numcli;
    string nom;
    string prenom;
    string sexe;

    int i;
    int compte;
    //int an;
    //int mois;
    //int jour;
    int codeOp;
    double montant;
    int compteCourant=-1;   //init debut: pas de compteCourant
    double soldeDelta=0.0;
    double retraitTot=0.0;
    double depotTot=0.0;
    double carteTot=0.0;
    double soldeDeb=0.0;
    double soldeFin=0.0;
    string lineIn;
    string fieldInArr[4];   // par ligne ou record, 4 champs
    while (getline(fileIn, lineIn))
    {
        //oss.str(""); oss << "lineIn= " <<lineIn<<endl;
        //qDebug() << QString::fromStdString(oss.str());
        istringstream iss(lineIn);
        i = 0;
        while (getline(iss, fieldInArr[i++], ';'));
        //for (int i = 0; i < 4; i++){       //affichage champs
        //    oss.str(""); oss << "fieldInArr["<< i << "]= " << fieldInArr[i] << endl; }
        numcli = "";
        nom = "";
        prenom = "";
        sexe = "";

        compte  = stoi( fieldInArr[0] );
        //an      = stoi( fieldInArr[1].substr(0,4) );
        //mois    = stoi( fieldInArr[1].substr(4,2) );
        //jour    = stoi( fieldInArr[1].substr(6,2) );
        codeOp  = stoi( fieldInArr[2] );
        montant = stod( fieldInArr[3] );
        //oss.str(""); oss
        //     << "compte: "       << compte
        //     << " , an: "        << an
        //     << " , mois: "      << mois
        //     << " , jour: "      << jour
        //     << " , codeOp: "    << codeOp
        //     << " , montant: "   << montant
        //     << endl;
        //qDebug() << QString::fromStdString(oss.str());


        // compte change, compteCourant precedent a utiliser
        if (compteCourant != compte)
        {

            if (compteCourant != -1)    //utiliser resultats, afficher
            {

                //Avec compteCourant, obtenir dans db : solde numcli
                //SELECT solde decouvert numcli from comptes WHERE compteCourant = numcompte ;
                QSqlDatabase db;
                db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
                db.setDatabaseName(DB_FILE_NAME);
                if ( db.open() ){
                    //qDebug() << "db.open() true";
                    QString reqSQL =
                        "SELECT solde, numcli "
                        " FROM comptes"
                        " WHERE numcompte = '" + QString::number(compteCourant) + "' "
                        " ;";
                    //qDebug() << "reqSQL " << reqSQL;
                    QSqlQuery query(db);
                    query.prepare(reqSQL);
                    query.exec();
                    numcli = "";
                    while(query.next())
                    {
                        soldeDeb = query.value("solde").toDouble();
                        //qDebug() << "soldeDeb= " << soldeDeb;
                        numcli = ( query.value("numcli").toString().rightJustified(5,'0') ).toStdString();
                        //qDebug() << "numcli= " << QString::fromStdString(numcli);
                    }
                    //qDebug() << "numcli= " << QString::fromStdString(numcli);


                    //Avec numcli, obtenir dans vecClients nom prenom sexe
                    //nom client from vecClients
                    string clientsField[13];
                    for(auto val: vecClients){
                        istringstream iss(val->ToString());
                        i = 0;
                        while (getline(iss, clientsField[i++], ';'));
                        if ( clientsField[0] == numcli ){

                            nom = clientsField[1];
                            //qDebug() << "nom " << QString::fromStdString(nom);

                            // Clients, Particuliers Professionnels debut
                            // si Clients Particuliers alors obtenir prenom sexe
                            Particuliers *Part = dynamic_cast<Particuliers*>(val);
                            if ( Part != nullptr )
                            {
                                //Particuliers
                                //  int, string,  string, string, int, string, string,     int, int, int, string, char);
                                //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
                                prenom = clientsField[10];
                                sexe = clientsField[11];
                            }
                            else
                            {
                                prenom = "";
                                sexe = "";
                            }
                            //qDebug() << "prenom " << QString::fromStdString(prenom);
                            // Clients, Particuliers Professionnels fin

                            break;  //for exit
                        }
                    }//for
                    //qDebug() << "nom= " << QString::fromStdString(nom);


                    //soldeDeb=0;     //from db
                    soldeDelta = ( depotTot - retraitTot ) - carteTot;
                    soldeFin= soldeDeb + soldeDelta;


                    // db soldeFin update
                    reqSQL =
                        " UPDATE comptes"
                        " SET solde = '" + QString::number(soldeFin) + "' "
                        " WHERE numcompte = '" + QString::number(compteCourant) + "' "
                        " ;";
                    //qDebug() << "reqSQL " << reqSQL;
                    query.prepare(reqSQL);
                    query.exec(reqSQL);

                    db.close();

                }else{
                    //qDebug() << "Erreur db.open() false";
                    ui->txtbOp->setText("Erreur db.open() false");
                    soldeDeb = 0.0;
                    numcli = "";
                    nom = "";
                    prenom = "";
                    sexe = "";
                }


                // formulaire txtbOp out
                oss.str("");
                if ( txtbOp_used )
                    oss<< "\n\t----------------------------------------\n\n";
                txtbOp_used = true;
                oss << "\tTitulaire : ";
                if (sexe == "M" ){
                    oss << "M. ";
                }else if (sexe == "F" ){
                    oss << "Mme. ";
                }
                oss << nom
                    << " " << prenom
                    << "\n\n\tCompte Numéro : " << compteCourant
                    << "\n\t\tTotal Retrait de " << retraitTot << " Euros"
                    << "\n\t\tTotal Dépôt de " << depotTot << " Euros"
                    << "\n\t\tTotal Carte Bleue de " << carteTot << " Euros"
                    << "\n\n\tSolde Avant Mise à jour : " << soldeDeb << " Euros"
                    << "\n\tSolde Après Mise à jour : " << soldeFin << " Euros";
                //qDebug() << QString::fromStdString(oss.str());
                ui->txtbOp->setTabStopDistance(25);
                ui->txtbOp->append( QString::fromStdString(oss.str()) );

            }//if


            //init, nouveau compte
            compteCourant = compte;
            retraitTot    = 0;
            depotTot      = 0;
            carteTot      = 0;
        }


        //additionner data
        if (compteCourant == compte)
        {
            //1=dabRetrait 2=cartePaiement 3=depot >=4anomalie
            switch (codeOp)
            {
            case 1:     //1=dabRetrait
                retraitTot+=montant;
                break;
            case 2:     //2=cartePaiement
                carteTot+=montant;
                break;
            case 3:     //3=depot
                depotTot+=montant;
                break;
            default:    //anomalie
                fileOut << lineIn << endl;
                break;
            }
        }

    }//while



    //derniere line lue
    if (compteCourant != -1)    //utiliser resultats, afficher
    {

        //Avec compteCourant, obtenir dans db : solde numcli
        //SELECT solde decouvert numcli from comptes WHERE compteCourant = numcompte ;
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
        db.setDatabaseName(DB_FILE_NAME);
        if ( db.open() ){
            //qDebug() << "db.open() true";
            QString reqSQL =
                "SELECT solde, numcli "
                " FROM comptes"
                " WHERE numcompte = '" + QString::number(compteCourant) + "' "
                " ;";
            //qDebug() << "reqSQL " << reqSQL;
            QSqlQuery query(db);
            query.prepare(reqSQL);
            query.exec();
            numcli = "";
            while(query.next())
            {
                soldeDeb = query.value("solde").toDouble();
                //qDebug() << "soldeDeb= " << soldeDeb;
                numcli = ( query.value("numcli").toString().rightJustified(5,'0') ).toStdString();
                //qDebug() << "numcli= " << QString::fromStdString(numcli);
            }
            //qDebug() << "numcli= " << QString::fromStdString(numcli);


            //Avec numcli, obtenir dans vecClients nom prenom sexe
            //nom client from vecClients
            string clientsField[13];
            for(auto val: vecClients){
                istringstream iss(val->ToString());
                i = 0;
                while (getline(iss, clientsField[i++], ';'));
                if ( clientsField[0] == numcli ){

                    nom = clientsField[1];
                    //qDebug() << "nom " << QString::fromStdString(nom);

                    // Clients, Particuliers Professionnels debut
                    // si Clients Particuliers alors obtenir prenom sexe
                    Particuliers *Part = dynamic_cast<Particuliers*>(val);
                    if ( Part != nullptr )
                    {
                        //Particuliers
                        //  int, string,  string, string, int, string, string,     int, int, int, string, char);
                        //identifiant NOM adrLibelle adrComplem adrCodPost adrVILLE mail parDateNA parDateNM parDateNJ parPrenom parSexe
                        prenom = clientsField[10];
                        sexe = clientsField[11];
                    }
                    else
                    {
                        prenom = "";
                        sexe = "";
                    }
                    //qDebug() << "prenom " << QString::fromStdString(prenom);
                    // Clients, Particuliers Professionnels fin

                    break;  //for exit
                }
            }//for
            //qDebug() << "nom= " << QString::fromStdString(nom);


            //soldeDeb=0;     //from db
            soldeDelta = ( depotTot - retraitTot ) - carteTot;
            soldeFin= soldeDeb + soldeDelta;


            // db soldeFin update
            reqSQL =
                " UPDATE comptes"
                " SET solde = '" + QString::number(soldeFin) + "' "
                " WHERE numcompte = '" + QString::number(compteCourant) + "' "
                " ;";
            //qDebug() << "reqSQL " << reqSQL;
            query.prepare(reqSQL);
            query.exec(reqSQL);

            db.close();

        }else{
            //qDebug() << "Erreur db.open() false";
            ui->txtbOp->setText("Erreur db.open() false");
            soldeDeb = 0.0;
            numcli = "";
            nom = "";
            prenom = "";
            sexe = "";
        }


        // formulaire txtbOp out
        oss.str("");
        if ( txtbOp_used )
            oss<< "\n\t----------------------------------------\n\n";
        txtbOp_used = true;
        oss << "\tTitulaire : ";
        if (sexe == "M" ){
            oss << "M. ";
        }else if (sexe == "F" ){
            oss << "Mme. ";
        }
        oss << nom
            << " " << prenom
            << "\n\n\tCompte Numéro : " << compteCourant
            << "\n\t\tTotal Retrait de " << retraitTot << " Euros"
            << "\n\t\tTotal Dépôt de " << depotTot << " Euros"
            << "\n\t\tTotal Carte Bleue de " << carteTot << " Euros"
            << "\n\n\tSolde Avant Mise à jour : " << soldeDeb << " Euros"
            << "\n\tSolde Après Mise à jour : " << soldeFin << " Euros";
        //qDebug() << QString::fromStdString(oss.str());
        ui->txtbOp->setTabStopDistance(25);
        ui->txtbOp->append( QString::fromStdString(oss.str()) );

    }


    fileOut.close();
    fileIn.close();
}


void MainWindow::on_radBtnComptesTous_clicked()
{
    ui->linEdCompteNum->clear();
    ui->lblComptes->clear();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
    db.setDatabaseName(DB_FILE_NAME);
    if ( db.open() ){
        //qDebug() << "db.open() true";
        QString reqSQL =
            "SELECT numcompte, datecreation, solde, decouvert, numcli"
            " FROM comptes"
            " ORDER BY numcompte ;";
        //qDebug() << "reqSQL " << reqSQL;
        QSqlQuery query(db);
        query.prepare(reqSQL);
        query.exec();

        //headers
        QStandardItemModel *model = new QStandardItemModel;
        model->setHorizontalHeaderItem(0, new QStandardItem("Numero de compte"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Date creation"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Solde"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Decouvert"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Numero client"));
        model->setHorizontalHeaderItem(5, new QStandardItem("Nom"));

        //nom client from vecClients
        QString nom;
        string clientsField[13];
        int i;
        while(query.next())
        {
            //qDebug() << "query.next()" ;
            QString numcompte = query.value("numcompte").toString();
            QString datecreation = query.value("datecreation").toString();
            QString solde = query.value("solde").toString();
            QString decouvert = query.value("decouvert").toString();
            QString numcli = query.value("numcli").toString();
            //qDebug() << "numcompte=" << numcompte << " datecreation=" << datecreation
            //         << " solde=" << solde    << " decouvert=" << decouvert
            //         << " numcli=" << numcli  ;

            //Avec numcli, obtenir nom dans vecClients
            //nom client from vecClients
            nom = "";
            for(auto val: vecClients){
                //qDebug() << val;
                istringstream iss(val->ToString());
                i = 0;
                while (getline(iss, clientsField[i++], ';'));
                if (    QString::fromStdString(clientsField[0])
                     == numcli.rightJustified(5,'0')
                   )
                {
                    nom = QString::fromStdString(clientsField[1]);
                    break;
                }
            }
            //qDebug() << "nom=" << nom;


            QList<QStandardItem *> item;
            item.append(new QStandardItem(numcompte));
            item.append(new QStandardItem(datecreation));
            item.append(new QStandardItem(solde));
            item.append(new QStandardItem(decouvert));
            item.append(new QStandardItem(numcli));
            item.append(new QStandardItem(nom));
            model->appendRow(item);

        }//while

        ui->tvComptes->setModel(model);
        ui->tvComptes->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tvComptes->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tvComptes->setEditTriggers(QAbstractItemView::NoEditTriggers);

        db.close();
    }else{
        //qDebug() << "Erreur db.open() false";
        ui->lblClients->setText("Erreur db.open() false");
    }
}

void MainWindow::on_radBtnComptesPart_clicked()
{
    ui->linEdCompteNum->clear();
    ui->lblComptes->clear();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
    db.setDatabaseName(DB_FILE_NAME);
    if ( db.open() ){
        //qDebug() << "db.open() true";
        QString reqSQL =
            "SELECT numcompte, datecreation, solde, decouvert, numcli"
            " FROM comptes"
            " ORDER BY numcompte ;";
        //qDebug() << "reqSQL " << reqSQL;
        QSqlQuery query(db);
        query.prepare(reqSQL);
        query.exec();

        //headers
        QStandardItemModel *model = new QStandardItemModel;
        model->setHorizontalHeaderItem(0, new QStandardItem("Numero de compte"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Date creation"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Solde"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Decouvert"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Numero client"));
        model->setHorizontalHeaderItem(5, new QStandardItem("Nom"));

        //nom client from vecClients
        QString nom;
        string clientsField[13];
        int i;
        while(query.next())
        {
            //qDebug() << "query.next()" ;

            QString numcli = query.value("numcli").toString();

            //Avec vecClients Particuliers,
            //Avec numcli, obtenir nom dans vecClients
            //nom client from vecClients
            nom = "";
            for(auto val: vecClients){
                //qDebug() << val;
                Particuliers *Part = dynamic_cast<Particuliers*>(val);
                if (Part != nullptr){
                    istringstream iss(val->ToString());
                    i = 0;
                    while (getline(iss, clientsField[i++], ';'));
                    if (    QString::fromStdString(clientsField[0])
                         == numcli.rightJustified(5,'0')            )
                    {
                        nom = QString::fromStdString(clientsField[1]);
                        break;
                    }
                }
            }
            //qDebug() << "nom=" << nom;

            if ( nom != "")
            {
                QString numcompte = query.value("numcompte").toString();
                QString datecreation = query.value("datecreation").toString();
                QString solde = query.value("solde").toString();
                QString decouvert = query.value("decouvert").toString();
                //qDebug() << "numcompte=" << numcompte << " datecreation=" << datecreation
                //         << " solde=" << solde    << " decouvert=" << decouvert
                //         << " numcli=" << numcli  ;
                QList<QStandardItem *> item;
                item.append(new QStandardItem(numcompte));
                item.append(new QStandardItem(datecreation));
                item.append(new QStandardItem(solde));
                item.append(new QStandardItem(decouvert));
                item.append(new QStandardItem(numcli));
                item.append(new QStandardItem(nom));
                model->appendRow(item);
            }

        }//while

        ui->tvComptes->setModel(model);
        ui->tvComptes->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tvComptes->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tvComptes->setEditTriggers(QAbstractItemView::NoEditTriggers);

        db.close();
    }else{
        //qDebug() << "Erreur db.open() false";
        ui->lblClients->setText("Erreur db.open() false");
    }
}

void MainWindow::on_radBtnComptesProf_clicked()
{
    ui->linEdCompteNum->clear();
    ui->lblComptes->clear();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
    db.setDatabaseName(DB_FILE_NAME);
    if ( db.open() ){
        //qDebug() << "db.open() true";
        QString reqSQL =
            "SELECT numcompte, datecreation, solde, decouvert, numcli"
            " FROM comptes"
            " ORDER BY numcompte ;";
        //qDebug() << "reqSQL " << reqSQL;
        QSqlQuery query(db);
        query.prepare(reqSQL);
        query.exec();

        //headers
        QStandardItemModel *model = new QStandardItemModel;
        model->setHorizontalHeaderItem(0, new QStandardItem("Numero de compte"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Date creation"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Solde"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Decouvert"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Numero client"));
        model->setHorizontalHeaderItem(5, new QStandardItem("Nom"));

        //nom client from vecClients
        QString nom;
        string clientsField[13];
        int i;
        while(query.next())
        {
            //qDebug() << "query.next()" ;

            QString numcli = query.value("numcli").toString();

            //Avec vecClients Professionnels,
            //Avec numcli, obtenir nom dans vecClients
            //nom client from vecClients
            nom = "";
            for(auto val: vecClients){
                //qDebug() << val;
                Professionnels *Prof = dynamic_cast<Professionnels*>(val);
                if (Prof != nullptr){
                    istringstream iss(val->ToString());
                    i = 0;
                    while (getline(iss, clientsField[i++], ';'));
                    if (    QString::fromStdString(clientsField[0])
                         == numcli.rightJustified(5,'0')            )
                    {
                        nom = QString::fromStdString(clientsField[1]);
                        break;
                    }
                }
            }
            //qDebug() << "nom=" << nom;

            if ( nom != "")
            {
                QString numcompte = query.value("numcompte").toString();
                QString datecreation = query.value("datecreation").toString();
                QString solde = query.value("solde").toString();
                QString decouvert = query.value("decouvert").toString();
                //qDebug() << "numcompte=" << numcompte << " datecreation=" << datecreation
                //         << " solde=" << solde    << " decouvert=" << decouvert
                //         << " numcli=" << numcli  ;
                QList<QStandardItem *> item;
                item.append(new QStandardItem(numcompte));
                item.append(new QStandardItem(datecreation));
                item.append(new QStandardItem(solde));
                item.append(new QStandardItem(decouvert));
                item.append(new QStandardItem(numcli));
                item.append(new QStandardItem(nom));
                model->appendRow(item);
            }

        }//while

        ui->tvComptes->setModel(model);
        ui->tvComptes->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tvComptes->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tvComptes->setEditTriggers(QAbstractItemView::NoEditTriggers);

        db.close();
    }else{
        //qDebug() << "Erreur db.open() false";
        ui->lblClients->setText("Erreur db.open() false");
    }
}

void MainWindow::on_pushBtnComptesNum_clicked()
{
    ui->lblComptes->clear();

    //button radio release
    ui->radBtnComptesTous->setAutoExclusive(false);
    ui->radBtnComptesTous->setChecked(false);
    ui->radBtnComptesTous->setAutoExclusive(true);

    ui->radBtnComptesPart->setAutoExclusive(false);
    ui->radBtnComptesPart->setChecked(false);
    ui->radBtnComptesPart->setAutoExclusive(true);

    ui->radBtnComptesProf->setAutoExclusive(false);
    ui->radBtnComptesProf->setChecked(false);
    ui->radBtnComptesProf->setAutoExclusive(true);


    QString valNum = ui->linEdCompteNum->text();
    //valNum = valNum.rightJustified(5, '0');
    //qDebug() <<"valNum="<<valNum;
    ui->linEdCompteNum->clear();

    if ( valNum.isEmpty() )
    {
        //qDebug() << "Numero vide";
        ui->lblComptes->setText("Numero vide");
        return;
    }
    //qDebug() <<"valNum="<<valNum;
    ui->tvComptes->reset();

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE"); //driver SQLITE
    db.setDatabaseName(DB_FILE_NAME);
    if ( db.open() ){
        //qDebug() << "db.open() true";
        QString reqSQL =
            "SELECT numcompte, datecreation, solde, decouvert, numcli"
            " FROM comptes"
            " WHERE numcompte = '" + valNum + "' "
            " ORDER BY numcompte ;";
        //qDebug() << "reqSQL " << reqSQL;
        QSqlQuery query(db);
        query.prepare(reqSQL);
        query.exec();


        //headers
        QStandardItemModel *model = new QStandardItemModel;
        model->setHorizontalHeaderItem(0, new QStandardItem("Numero de compte"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Date creation"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Solde"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Decouvert"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Numero client"));
        model->setHorizontalHeaderItem(5, new QStandardItem("Nom"));

        //nom client from vecClients
        QString nom;
        string clientsField[13];
        int i;
        int queryNextCpt = 0;
        while(query.next())
        {
            queryNextCpt++;
            //qDebug() << "query.next()" ;

            QString numcli = query.value("numcli").toString();

            //Avec numcli, obtenir nom dans vecClients
            //nom client from vecClients
            nom = "";
            for(auto val: vecClients){
                //qDebug() << val;
                istringstream iss(val->ToString());
                i = 0;
                while (getline(iss, clientsField[i++], ';'));
                if (    QString::fromStdString(clientsField[0])
                     == numcli.rightJustified(5,'0')            )
                {
                    nom = QString::fromStdString(clientsField[1]);
                    break;
                }
            }
            //qDebug() << "nom=" << nom;


            QString numcompte = query.value("numcompte").toString();
            QString datecreation = query.value("datecreation").toString();
            QString solde = query.value("solde").toString();
            QString decouvert = query.value("decouvert").toString();
            //qDebug() << "numcompte=" << numcompte << " datecreation=" << datecreation
            //         << " solde=" << solde    << " decouvert=" << decouvert
            //         << " numcli=" << numcli  ;
            QList<QStandardItem *> item;
            item.append(new QStandardItem(numcompte));
            item.append(new QStandardItem(datecreation));
            item.append(new QStandardItem(solde));
            item.append(new QStandardItem(decouvert));
            item.append(new QStandardItem(numcli));
            item.append(new QStandardItem(nom));
            model->appendRow(item);

        }//while
        if ( queryNextCpt != 0 )
        {
            ui->tvComptes->setModel(model);
            ui->tvComptes->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->tvComptes->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tvComptes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            //qDebug() << "Numero compte \"" + valNum  + "\" absent";
            ui->lblComptes->setText("Numero compte \"" + valNum  + "\" absent");
            ui->tvComptes->reset();
        }


        db.close();

    }else{
        //qDebug() << "Erreur db.open() false";
        ui->lblComptes->setText("Erreur db.open() false");
    }
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}
