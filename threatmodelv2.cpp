#include "threatmodelv2.h"
#include "ui_threatmodelv2.h"
#include <QString>
#include <QMessageBox>
#include <string>
#include<QString>
#include<QRegExp>
#include<QtGui>
#include<QAxObject>
#include<QAxWidget>
#include<QApplication>
#include<QStringList>
#include<QStandardItemModel>
#include<QFile>
#include <QListWidget>
#include <QFileDialog>


QString file1("thrlist.xlsx"); //thrlist original
QString Result("Threatmodel.xlsx");

QString Saveload(":/new/prefix1/settings.ini");




int stroka=220;

void Aktual();
void Excel();

threatmodelv2::threatmodelv2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::threatmodelv2)
{

    ui->setupUi(this);
    //название программы
    this->setWindowTitle("Моделирование угроз безопасности информации");
    ui->pushButton_3->hide();

    settings=new QSettings(Saveload);

    //стили
    QFile styleF;
    styleF.setFileName(":/new/prefix1/css.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();
    qApp->setStyleSheet(qssStr);
    styleF.close();




}

threatmodelv2::~threatmodelv2()
{
    delete ui;
}


int k=0; //счетчик страниц

bool da=false;

float high=0; //подсчет характеристик ИС
float mid=0;
float low=0;

float Mid=0; //подсчет процентов безопасности ИС
float Low=0;
float High=0;

bool outsider=false; //внешний с высоким
bool insider=false; //внутренний свысоким
bool outLow=false;
bool inLow=false;
bool outMid=false;
bool inMid=false;

QString Konf[220]={"low","low"};
QString Cel[220]={"low","low"};
QString Dost[220]={"low","low"};
QString Yj;
QString X[220];
QString A;

bool Actual[220];
int b=0;
int Y1=0; // 0-low 1-mid 2 high защищенность системы
int Y2=0; //потенцевал нарушителя




void threatmodelv2::on_action_triggered()
{

        settings->beginGroup("page");
        settings->setValue("RadioButton_1", ui->radioButton ->isChecked());
        settings->setValue("RadioButton_2",ui->radioButton_2->isChecked());
        settings->setValue("RadioButton_3",ui->radioButton_3->isChecked());
        qDebug()<<settings->value("RadioButton_1").toBool();
        qDebug()<<settings->value("RadioButton_2").toBool();
        qDebug()<<settings->value("RadioButton_3").toBool();
        settings->endGroup();
        settings->sync();

        settings->setValue("CheckBoxState",ui->checkBox  ->isChecked());
        settings->setValue("CheckBoxState1",ui->checkBox_2->isChecked());
        settings->setValue("CheckBoxState2",ui->checkBox_3->isChecked());
        settings->setValue("CheckBoxState3",ui->checkBox_4->isChecked());
        settings->setValue("CheckBoxState4",ui->checkBox_5->isChecked());
        settings->setValue("CheckBoxState5",ui->checkBox_6->isChecked());
        settings->setValue("CheckBoxState6",ui->checkBox_7->isChecked());
        settings->setValue("CheckBoxState7",ui->checkBox_8->isChecked());
        settings->setValue("CheckBoxState8",ui->checkBox_9->isChecked());
        settings->setValue("CheckBoxState9",ui->checkBox_21->isChecked());
        settings->setValue("CheckBoxState0",ui->checkBox_22->isChecked());
        settings->setValue("CheckBoxState11",ui->checkBox_23->isChecked());
        settings->setValue("CheckBoxState12",ui->checkBox_24->isChecked());
        settings->setValue("CheckBoxState13",ui->checkBox_25->isChecked());
        settings->setValue("CheckBoxState14",ui->checkBox_26->isChecked());
        settings->setValue("CheckBoxState15",ui->checkBox_27->isChecked());
        settings->setValue("CheckBoxState16",ui->checkBox_28->isChecked());
        settings->setValue("CheckBoxState17",ui->checkBox_29->isChecked());
        settings->setValue("CheckBoxState18",ui->checkBox_30->isChecked());
        settings->setValue("CheckBoxState31",ui->checkBox_31->isChecked());
        settings->setValue("CheckBoxState32",ui->checkBox_32->isChecked());
        settings->setValue("CheckBoxState19",ui->checkBox_10->isChecked());
        settings->setValue("CheckBoxState20",ui->checkBox_11->isChecked());
        settings->setValue("CheckBoxState21",ui->checkBox_12->isChecked());
        settings->setValue("CheckBoxState22",ui->checkBox_13->isChecked());
        settings->setValue("CheckBoxState23",ui->checkBox_14->isChecked());
        settings->setValue("CheckBoxState24",ui->checkBox_15->isChecked());
        settings->setValue("CheckBoxState25",ui->checkBox_16->isChecked());
        settings->setValue("CheckBoxState26",ui->checkBox_17->isChecked());
        settings->setValue("CheckBoxState27",ui->checkBox_18->isChecked());
        settings->setValue("CheckBoxState28",ui->checkBox_19->isChecked());
        settings->setValue("CheckBoxState29",ui->checkBox_20->isChecked());

        settings->setValue("RadioButton_5",ui->radioButton_5->isChecked());
        settings->setValue("RadioButton_4",ui->radioButton_4->isChecked());
        settings->setValue("RadioButton_8",ui->radioButton_8->isChecked());
        settings->setValue("RadioButton_7",ui->radioButton_7->isChecked());
        settings->setValue("RadioButton_6",ui->radioButton_6->isChecked());
        settings->setValue("RadioButton_9",ui->radioButton_9 ->isChecked());
        settings->setValue("RadioButton_10",ui->radioButton_10->isChecked());
        settings->setValue("RadioButton_11",ui->radioButton_11->isChecked());
        settings->setValue("RadioButton_12",ui->radioButton_12->isChecked());
        settings->setValue("RadioButton_13",ui->radioButton_13->isChecked());
        settings->setValue("RadioButton_14",ui->radioButton_14->isChecked());
        settings->setValue("RadioButton_15",ui->radioButton_15->isChecked());

        settings->setValue("RadioButton_16",ui->radioButton_16->isChecked());
        settings->setValue("RadioButton_17",ui->radioButton_17->isChecked());
       settings->setValue("RadioButton_18",ui->radioButton_18 ->isChecked());
       settings->setValue("RadioButton_19",ui->radioButton_19 ->isChecked());
       settings->setValue("RadioButton_20",ui->radioButton_20 ->isChecked());
       settings->setValue("RadioButton_21",ui->radioButton_21 ->isChecked());
       settings->setValue("RadioButton_22",ui->radioButton_22 ->isChecked());
       settings->setValue("RadioButton_23",ui->radioButton_23 ->isChecked());
       settings->setValue("RadioButton_24",ui->radioButton_24 ->isChecked());
       settings->setValue("RadioButton_25",ui->radioButton_25 ->isChecked());
       settings->setValue("RadioButton_26",ui->radioButton_26 ->isChecked());

     QMessageBox::warning(0,"Warning","Настройки сохранились","ok");
}

void threatmodelv2::on_action_2_triggered()
{


    settings->beginGroup("page");
    qDebug()<<settings->value("RadioButton_1").toBool();
    ui->radioButton->setChecked(settings->value("RadioButton_1").toBool());
    ui->radioButton_2->setChecked(settings->value("RadioButton_2").toBool());
    ui->radioButton_3->setChecked(settings->value("RadioButton_3").toBool());
    settings->endGroup();

    ui->checkBox  ->setChecked(settings->value("CheckBoxState").toBool());
    ui->checkBox_2->setChecked(settings->value("CheckBoxState1").toBool());
    ui->checkBox_3->setChecked(settings->value("CheckBoxState2").toBool());
    ui->checkBox_4->setChecked(settings->value("CheckBoxState3").toBool());
    ui->checkBox_5->setChecked(settings->value("CheckBoxState4").toBool());
    ui->checkBox_6->setChecked(settings->value("CheckBoxState5").toBool());
    ui->checkBox_7->setChecked(settings->value("CheckBoxState6").toBool());
    ui->checkBox_8->setChecked(settings->value("CheckBoxState7").toBool());
    ui->checkBox_9->setChecked(settings->value("CheckBoxState8").toBool());
    ui->checkBox_21->setChecked(settings->value("CheckBoxState9").toBool());
    ui->checkBox_22->setChecked(settings->value("CheckBoxState0").toBool());
    ui->checkBox_23->setChecked(settings->value("CheckBoxState11").toBool());
    ui->checkBox_24->setChecked(settings->value("CheckBoxState12").toBool());
    ui->checkBox_25->setChecked(settings->value("CheckBoxState13").toBool());
    ui->checkBox_26->setChecked(settings->value("CheckBoxState14").toBool());
    ui->checkBox_27->setChecked(settings->value("CheckBoxState15").toBool());
    ui->checkBox_28->setChecked(settings->value("CheckBoxState16").toBool());
    ui->checkBox_29->setChecked(settings->value("CheckBoxState17").toBool());
    ui->checkBox_30->setChecked(settings->value("CheckBoxState18").toBool());
    ui->checkBox_31->setChecked(settings->value("CheckBoxState31").toBool());
    ui->checkBox_32->setChecked(settings->value("CheckBoxState32").toBool());
    ui->checkBox_10->setChecked(settings->value("CheckBoxState19").toBool());
    ui->checkBox_11->setChecked(settings->value("CheckBoxState20").toBool());
    ui->checkBox_12->setChecked(settings->value("CheckBoxState21").toBool());
    ui->checkBox_13->setChecked(settings->value("CheckBoxState22").toBool());
    ui->checkBox_14->setChecked(settings->value("CheckBoxState23").toBool());
    ui->checkBox_15->setChecked(settings->value("CheckBoxState24").toBool());
    ui->checkBox_16->setChecked(settings->value("CheckBoxState25").toBool());
    ui->checkBox_17->setChecked(settings->value("CheckBoxState26").toBool());
    ui->checkBox_18->setChecked(settings->value("CheckBoxState27").toBool());
    ui->checkBox_19->setChecked(settings->value("CheckBoxState28").toBool());
    ui->checkBox_20->setChecked(settings->value("CheckBoxState29").toBool());

    ui->radioButton_5->setChecked(settings->value("RadioButton_5").toBool());
    ui->radioButton_4->setChecked(settings->value("RadioButton_4").toBool());
    ui->radioButton_8->setChecked(settings->value("RadioButton_8").toBool());
    ui->radioButton_7->setChecked(settings->value("RadioButton_7").toBool());
    ui->radioButton_6->setChecked(settings->value("RadioButton_6").toBool());
    ui->radioButton_9->setChecked(settings->value("RadioButton_9").toBool());
    ui->radioButton_10->setChecked(settings->value("RadioButton_10").toBool());
    ui->radioButton_11->setChecked(settings->value("RadioButton_11").toBool());
    ui->radioButton_12->setChecked(settings->value("RadioButton_12").toBool());
    ui->radioButton_13->setChecked(settings->value("RadioButton_13").toBool());
    ui->radioButton_14->setChecked(settings->value("RadioButton_14").toBool());
    ui->radioButton_15->setChecked(settings->value("RadioButton_15").toBool());

   ui->radioButton_16->setChecked(settings->value("RadioButton_16").toBool());
   ui->radioButton_17->setChecked(settings->value("RadioButton_17").toBool());
   ui->radioButton_18->setChecked(settings->value("RadioButton_18").toBool());
   ui->radioButton_19->setChecked(settings->value("RadioButton_19").toBool());
   ui->radioButton_20->setChecked(settings->value("RadioButton_20").toBool());
   ui->radioButton_21->setChecked(settings->value("RadioButton_21").toBool());
   ui->radioButton_22->setChecked(settings->value("RadioButton_22").toBool());
   ui->radioButton_23->setChecked(settings->value("RadioButton_23").toBool());
   ui->radioButton_24->setChecked(settings->value("RadioButton_24").toBool());
   ui->radioButton_25->setChecked(settings->value("RadioButton_25").toBool());
   ui->radioButton_26->setChecked(settings->value("RadioButton_26").toBool());



    settings->sync();

}


void threatmodelv2::on_pushButton_clicked()
{


bool page[15]={false,false};


    qDebug()<<"Страница "<<k;

    k++;
    ui->stackedWidget->setCurrentIndex(k);
    question:
    if(k<15){
                ui->pushButton->setText("Далее");
             }

    if(k==14){
                ui->pushButton->setText("Готово");
             }

    //Расчет защищенности ИС
    if(k==15){




    //tab1
    if(ui->radioButton ->isChecked()){high++; da=true; qDebug()<<ui->radioButton ->isChecked(); page[0]=true;}
    if(ui->radioButton_2->isChecked()){mid++; page[0]=true; }
    if(ui->radioButton_3->isChecked()){low++;  page[0]=true;}



page[1]=true;
    //tab2 еще возвращаться будем
    if(ui->checkBox  ->isChecked()){low++; }
    if(ui->checkBox_2->isChecked()){low++; }
    if(ui->checkBox_3->isChecked()){low++; }
    if(ui->checkBox_4->isChecked()){low++; }
    if(ui->checkBox_5->isChecked()){low++; }
    if(ui->checkBox_6->isChecked()){low++; }
    if(ui->checkBox_7->isChecked()){low++; }
    if(ui->checkBox_8->isChecked()){low++; }
    if(ui->checkBox_9->isChecked()){mid++; }

page[2]=true;
    //tab3 пропустил
    if(ui->checkBox_21->isChecked()){high++; }
    if(ui->checkBox_22->isChecked()){mid++;  }
    if(ui->checkBox_23->isChecked()){low++;  }
    if(ui->checkBox_24->isChecked()){low++;  }
    if(ui->checkBox_25->isChecked()){low++;  }
    if(ui->checkBox_26->isChecked()){mid++;  }
    if(ui->checkBox_27->isChecked()){mid++;  }
    if(ui->checkBox_28->isChecked()){mid++;  }


    //tab4
    if(ui->radioButton_5->isChecked()){mid++; page[3]=true;}
    if(ui->radioButton_4->isChecked()){low++;page[3]=true;}

    //tab5 и подключение к сети
    if(ui->radioButton_8->isChecked()){high++;page[4]=true;}
    if(ui->radioButton_7->isChecked()){mid++; page[4]=true;}
    if(ui->radioButton_6->isChecked()){low++;page[4]=true; }
    else page[3]=true;

    //tab6
    if(ui->radioButton_9 ->isChecked()){high++;page[5]=true;}
    if(ui->radioButton_10->isChecked()){mid++; page[5]=true;}
    if(ui->radioButton_11->isChecked()){low++; page[5]=true;}

    //tab7
    if(ui->radioButton_12->isChecked()){high++;page[6]=true;}
    if(ui->radioButton_13->isChecked()){low++; page[6]=true;}


    //tab8
    if(ui->radioButton_14->isChecked()){low++;page[7]=true; }
    if(ui->radioButton_15->isChecked()){mid++; page[7]=true;}

    //tab9
    //checkbox
    if(ui->checkBox_29->isChecked()){low++; page[8]=true;}
    if(ui->checkBox_30->isChecked()){mid++;page[8]=true; }
    if(ui->checkBox_31->isChecked()){mid++;page[8]=true; }
    if(ui->checkBox_32->isChecked()){mid++; page[8]=true;}


    //tab10
    if(ui->radioButton_16->isChecked()){low++; page[9]=true;}
    if(ui->radioButton_17->isChecked()){mid++; page[9]=true;}



    High=high/(high+mid+low)*100;
    Mid=mid/(high+mid+low)*100;
    Low=low/(high+mid+low)*100;


//опредение внещних внутренних злоумшленников


    if(ui->checkBox_10->isChecked()){outLow=true;page[10]=true;}//низкий
    if(ui->checkBox_11->isChecked()){outLow=true;page[10]=true;}//низкий
    if(ui->checkBox_12->isChecked()){inLow=true;page[10]=true;}//низкий
    if(ui->checkBox_13->isChecked()){inLow=true;page[10]=true;}//ybprbq
    if(ui->checkBox_14->isChecked()){inLow=true;page[10]=true;}//низкий
    if(ui->checkBox_15->isChecked()){inMid=true;page[10]=true;}//средний
    if(ui->checkBox_16->isChecked()){outMid=true;page[11]=true;}//средний
    if(ui->checkBox_17->isChecked()){outMid=true;page[11]=true;}//средний
    if(ui->checkBox_18->isChecked()){outMid=true;page[11]=true;}//средний
    if(ui->checkBox_19->isChecked()){outMid=true;page[11]=true;}//средний
    if(ui->checkBox_20->isChecked()){outsider=true; insider=true;page[11]=true;}//высокий


    //Отключение от сети(внешние не учитываются)
    if(ui->radioButton_8->isChecked()){outsider=false; outLow=false; outMid=false;}

    //цикл оч противный но он необходим
    for (int i=0;i<stroka;i++){
                         if(ui->radioButton_18 ->isChecked()){Konf[i]="low";page[12]=true;}
                         if(ui->radioButton_19 ->isChecked()){Konf[i]="mid";page[12]=true;}
                         if(ui->radioButton_20 ->isChecked()){Konf[i]="high";page[12]=true;}


                         if(ui->radioButton_21 ->isChecked()){Cel[i]="low";page[13]=true;}
                         if(ui->radioButton_22 ->isChecked()){Cel[i]="mid";page[13]=true;}
                         if(ui->radioButton_23 ->isChecked()){Cel[i]="high";page[13]=true;}


                         if(ui->radioButton_24 ->isChecked()){Dost[i]="low";page[14]=true;}
                         if(ui->radioButton_25 ->isChecked()){Dost[i]="mid";page[14]=true;}
                         if(ui->radioButton_26 ->isChecked()){Dost[i]="high";page[14]=true;}

                        }


for(int j=0;j<14;++j)
   {
    qDebug()<<page[j]<<j;
    for(int l=0;l<15;l++)
    {
        if(page[l]==false)
       {
        k=l;
        ui->stackedWidget->setCurrentIndex(k);
        QMessageBox::warning(0,"Внимание","Пожалуйста ответьте на все вопросы  ","Переход на страницу");
        goto question;
       }
     }

    if(page[j]==true)
        {

    //QAxObject + excel Thrlist.xlsx original

    QAxObject *excel=new QAxObject("Excel.Application",this);
    excel->dynamicCall("SetVisible(bool)",false);
    QString tmp_s = QApplication::applicationDirPath();
    QAxObject *workbooks=excel->querySubObject("Workbooks");
    QAxObject *workbook=workbooks->querySubObject("Open(const QString&)",tmp_s+"\\thrlist.xlsx");
    QAxObject* sheets=workbook->querySubObject("Sheets");
    QAxObject* sheet = sheets->querySubObject("Item(int)", 1);

    int count=sheets->dynamicCall("Count()").toInt();
    qDebug()<<"Kolvo listov: "<<count;

    //Threatmodel1.xlsx
    QAxObject *excelResult=new QAxObject("Excel.Application",this);
    excelResult->dynamicCall("SetVisible(bool)",false);
    QAxObject *workbooksResult=excelResult->querySubObject("Workbooks");
    QAxObject *workbookResult=workbooksResult->querySubObject("Open(const QString&)",tmp_s+"\\Threatmodel.xlsx");
    QAxObject* sheetsResult=workbookResult->querySubObject("Sheets");
    QAxObject* sheetResult = sheetsResult->querySubObject("Item(int)", 1);
    excelResult->setProperty("DisplayAlerts", false);

    //строки
    QAxObject* usedRange = sheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    int countRows = rows->property("Count").toInt();

    //столбцы
    QAxObject* usedRange1 = sheet->querySubObject("UsedRange");
   QAxObject* columns = usedRange1->querySubObject("Columns");
   int countCols = columns->property("Count").toInt();

    //Определение последствий угрозы
    for (int row = 2; row <= countRows; row++ ){
       // for ( int column = 6; column < 8; column++ ){
            int column = 6;
            QAxObject* cell = sheet->querySubObject("Cells(int,int)",row  , column );
            QVariant value = cell->property("Value");
            int a[3]={0,0};
            a[0]=value.toInt();//konf
            qDebug()<<"string a="<<a[0];

            if(a[0]==0)Konf[row-2]="low";

            column = 7;
            cell = sheet->querySubObject("Cells(int,int)",row  , column );
            value = cell->property("Value");
            a[1]=value.toInt();//cel
            qDebug()<<"string a1="<<a[1];

            if(a[1]==0)Cel[row-2]="low";

            column = 8;
            cell = sheet->querySubObject("Cells(int,int)", row  , column );
            value = cell->property("Value");
            a[2]=value.toInt();//dost
            qDebug()<<"string a2= "<<a[2];

            if(a[2]==0)Dost[row-2]="low";



            qDebug()<<"Конф"<<Konf[row-2];
            qDebug()<<"Cel"<<Cel[row-2];
            qDebug()<<"Dost"<<Dost[row-2];


             //Степень угрозы
            if(Konf[row-2]=="mid"||Cel[row-2]=="mid"||Dost[row-2]=="mid") {X[row-2]="mid";}
            if(Konf[row-2]=="high"||Cel[row-2]=="high"||Dost[row-2]=="high") {X[row-2]="high";}
            if(Konf[row-2]=="low" & Cel[row-2]=="low" & Dost[row-2]=="low"){X[row-2]="low";}
            qDebug()<<"Конф-цел-дост строки номер "<<row<<" ="<<X[row-2];
    }

    //Определение реализации угрозы
    Aktual();


    //Actuality
    for(int i=2;i<countRows;i++){
        if(Yj=="high")              {Actual[i-2]=true;}
        if(Yj=="mid"&&X[i-2]=="mid")  {Actual[i-2]=true;}
        if(Yj=="mid"&&X[i-2]=="high") {Actual[i-2]=true;}
        if(Yj=="low"&& X[i-2]=="high"){Actual[i-2]=true;}
        else {Actual[i]=false;}
    }



    //проверка на тоенциал нарушителя
    for (int row=2; row<countRows; row++)
        {
            int column = 4;
            QAxObject* cell = sheet->querySubObject("Cells(int,int)", row  , column );
            QVariant value = cell->property("Value");
            QStringList valuev=value.toStringList();
            QStringList lowValue=valuev.filter(QRegExp("низким"));
            QStringList midValue=valuev.filter(QRegExp("средним"));
            QStringList filtredValue=valuev.filter(QRegExp("Внешний нарушитель"));

            bool LV=false;
            bool MV=false;
            bool FV=false;

            QString filtredstring=filtredValue.join("");
            QString MidValue=midValue.join("");
            QString LowValue=lowValue.join("");


            LV=LowValue.contains("низким",Qt::CaseInsensitive);
            MV=MidValue.contains("средним",Qt::CaseInsensitive);
            FV=filtredstring.contains("Внешний нарушитель",Qt::CaseInsensitive);






            qDebug()<<"Midvalue-"<<MV;
            qDebug()<<"LowValue-"<<LV;

            qDebug()<<"Внешний есть?- "<<row<<" "<<FV;


            if(Y2==1 && LV==true){Actual[row-2]=false;}
            if(Y2==2 && MV==true){Actual[row-2]=false;}
            if(Y2==2 && LV==true){Actual[row-2]=false;}
            if(ui->radioButton_8->isChecked()&& FV==true ) { Actual[row-2]=false;}

            qDebug()<<"Актуальность есть?- "<<row<<" "<<Actual[row-2];










        }

//беспровод - беспровод первый столбец отдельно ищем
    for(int row=2;row<countRows;row++)
    {
     int column = 2;
     QAxObject* cell = sheet->querySubObject("Cells(int,int)", row  , column );
     QVariant value = cell->property("Value");
     QStringList valuev=value.toStringList();
     QStringList besprovod=valuev.filter(QRegExp("беспровод"));
     if(ui->checkBox_3->checkState() == Qt::Unchecked && besprovod.contains("беспровод",Qt::CaseInsensitive)==true){Actual[row]=false;}

    }
//веб

    for(int row=2;row<countRows;row++)
    {
     int column = 1;
     QAxObject* cell = sheet->querySubObject("Cells(int,int)", row  , column );
     QVariant value = cell->property("Value");
     QStringList valuev=value.toStringList();
     QStringList Grid=valuev.filter(QRegExp("16"));
     QStringList Grid1=valuev.filter(QRegExp("17"));
     QStringList Grid2=valuev.filter(QRegExp("26"));
     QStringList Grid3=valuev.filter(QRegExp("41"));
     QStringList Grid4=valuev.filter(QRegExp("42"));
     QStringList Grid5=valuev.filter(QRegExp("62"));
     QStringList Grid6=valuev.filter(QRegExp("151"));
     QStringList Grid7=valuev.filter(QRegExp("159"));
     QStringList Grid8=valuev.filter(QRegExp("173"));
     QStringList Grid9=valuev.filter(QRegExp("174"));

     if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid.contains("16",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid1.contains("17",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid2.contains("26",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid3.contains("41",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid4.contains("42",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid5.contains("62",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid6.contains("151",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid7.contains("159",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid8.contains("173",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_3->checkState() == Qt::Unchecked && Grid9.contains("174",Qt::CaseInsensitive)==true){Actual[row]=false;}

    }



//отсечение не используемых технологий
   for(int row=2;row<countRows;row++)
   {
    int column = 5;
    QAxObject* cell = sheet->querySubObject("Cells(int,int)", row  , column );
    QVariant value = cell->property("Value");
    QStringList valuev=value.toStringList();
    QStringList Grid=valuev.filter(QRegExp("грид"));
    QStringList Virtual=valuev.filter(QRegExp("виртуал"));
    QStringList Oblaco=valuev.filter(QRegExp("Облач"));
    QStringList Supercomp=valuev.filter(QRegExp("суперкомпьютер"));
    QStringList BigData1=valuev.filter(QRegExp("Хранилище больших данных"));// и еще 38
    QStringList WindowsPhone=valuev.filter(QRegExp(" Мобильное устройство"));

    if(ui->checkBox->checkState() == Qt::Unchecked && Grid.contains("грид",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_2->checkState() == Qt::Unchecked && Virtual.contains("виртуал",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_5->checkState() == Qt::Unchecked && Oblaco.contains("Облач",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_6->checkState() == Qt::Unchecked && Supercomp.contains("суперкомпьютер",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_7->checkState() == Qt::Unchecked && BigData1.contains("Хранилище больших данных",Qt::CaseInsensitive)==true){Actual[row]=false;}
    if(ui->checkBox_8->checkState() == Qt::Unchecked && WindowsPhone.contains("Мобильное устройство",Qt::CaseInsensitive)==true){Actual[row]=false;}


   }



         //вывод в новую таблицу уже в xlsx ^_^ а txt для Галочки оставил

         QFile mFile("MyFile.txt");
         mFile.open(QIODevice::WriteOnly);

         int schotchik=1;//счетчик строки в записываемой таблице

         for (int lol = 0; lol <= countRows-2; lol++ )
                    {
                  if(Actual[lol]==true)
                        {
                      for(int Colis=1;Colis<11;Colis++)
                            {

                            QAxObject* columnresult=sheetResult->querySubObject("Columns(int)",Colis);

                            QAxObject* cell = sheet->querySubObject("Cells(int,int)", lol+2  , Colis );
                            QVariant value = cell->property("Value");
                            QStringList valuev=value.toStringList();
                            QAxObject* cellResult = sheetResult->querySubObject("Cells(int,int)",schotchik,Colis);
                            if(schotchik==1)
                            {
                                if(Colis==1) cellResult->dynamicCall("SetValue(const QString&)", "Идентификатор УБИ");
                                if(Colis==2) cellResult->dynamicCall("SetValue(const QString&)", "Наименование УБИ");
                                if(Colis==3) cellResult->dynamicCall("SetValue(const QString&)", "Описание");
                                if(Colis==4) cellResult->dynamicCall("SetValue(const QString&)", "Источник угрозы (характеристика и потенциал нарушителя)");
                                if(Colis==5) cellResult->dynamicCall("SetValue(const QString&)", "Объект воздействия");
                                if(Colis==6) cellResult->dynamicCall("SetValue(const QString&)", "Нарушение конфиденциальности");
                                if(Colis==7) cellResult->dynamicCall("SetValue(const QString&)", "Нарушение целостности");
                                if(Colis==8) cellResult->dynamicCall("SetValue(const QString&)", "Нарушение доступности"); //
                                if(Colis==9) cellResult->dynamicCall("SetValue(const QString&)", "Дата включения угрозы в БДУ");
                                if(Colis==10) cellResult->dynamicCall("SetValue(const QString&)", "Дата последнего изменения данных");
                            }
                            else
                            {
                                qDebug()<<"dynamiccall "<<lol;
                                cellResult->dynamicCall("SetValue(const QVariant&)", value);
                            }

                            columnresult->dynamicCall("setColumnWidth(int)",27); //14,4

                            }

                            QAxObject* rowresult=sheetResult->querySubObject("Rows(int)",schotchik);
                            rowresult->dynamicCall("setRowHeight(int)",14);
                            b++;
                            schotchik++;
                        }
                    }


         qDebug()<<"after dynamiccall ";
         workbookResult->dynamicCall("Save()");
         workbookResult->dynamicCall("Close()");
         excelResult->dynamicCall("Quit()");
         qDebug()<<"after quit ";

         void Excel();
          QTextStream writeStream(&mFile); // Создаем объект класса QTextStream
          writeStream <<schotchik<<"\n";
          A=QString::number(b);
          QMessageBox::warning(this,"The end","Все угрозы буду представлены в файле формата .xlsx");
          mFile.close();
          workbook->dynamicCall("Close()");
          excel->dynamicCall("Quit()");

          ui->pushButton_2->hide();
          ui->pushButton->hide();
          ui->listWidget->hide();


          break;


}

 }

    }


}

void threatmodelv2::on_pushButton_2_clicked()
{
    k--;
    ui->stackedWidget->setCurrentIndex(k);
    if(k<0){k=0;}
    if(k<14){
                ui->pushButton->setText("Далее");
             }
}

void Aktual(){


    //if (Low0) Y1=0;
    if (High>=45) {Y1=2;}
    else if (Mid>=40) {Y1=1;}
    else Y1=0;


    //отсеивание внешних изза отсутствия доступа к сети

    //потанцевал нарушителя

    if(outMid==true||inMid==true) {Y2=1;}
    else if(outsider==true||insider==true) {Y2=2;}
    else if(outLow==true||inLow==true) Y2=0;

    //угрозы
    if (Y1==0)         Yj="high";

    if (Y1==1&& Y2==0) Yj="mid" ;
    if (Y1==1&& Y2==1) Yj="high";
    if (Y1==1&& Y2==2) Yj="high";

    if (Y1==2&& Y2==0) Yj="low" ;
    if (Y1==2&& Y2==1) Yj="mid" ;
    if (Y1==2&& Y2==2) Yj="high";

    //актуальность
    qDebug()<<"Y1= "<<Y1;
    qDebug()<<"Y2= "<<Y2;
    qDebug()<<"Yj="<<Yj;


}

void threatmodelv2::on_listWidget_activated(const QModelIndex &index)
{


    k=index.row();

    ui->stackedWidget->setCurrentIndex(k);
    if(k==14){
                ui->pushButton->setText("Готово");
             }

    if(k<14) {
                ui->pushButton->setText("Далее");
             }
}

void threatmodelv2::on_checkBox_29_clicked()
{
    if(ui->checkBox_29->isChecked())
    {
        ui->checkBox_30->setEnabled(false);
        ui->checkBox_31->setEnabled(false);
        ui->checkBox_32->setEnabled(false);

    }
    else
    {
        ui->checkBox_30->setEnabled(true);
        ui->checkBox_31->setEnabled(true);
        ui->checkBox_32->setEnabled(true);
    }
}



void threatmodelv2::on_pushButton_3_clicked()
{

    QVariant AppDir = QFileDialog::getSaveFileName(0, "Open Dialog", "", "*.xlsx");


}


void Excel(){

    QAxObject *excel=new QAxObject("Excel.Application",0);
    excel->dynamicCall("SetVisible(bool)",false);
    QString tmp_s = QApplication::applicationDirPath();
    QAxObject *workbooks=excel->querySubObject("Workbooks");
    QAxObject *workbook=workbooks->querySubObject("Open(const QString&)",tmp_s+"\\thrlist.xlsx");
    QAxObject* sheets=workbook->querySubObject("Sheets");
    QAxObject* sheet = sheets->querySubObject("Item(int)", 1);

    int count=sheets->dynamicCall("Count()").toInt();
    qDebug()<<"Kolvo listov: "<<count;

    //модельугроз.xlsx
    QAxObject *excelResult=new QAxObject("Excel.Application",0);
    excelResult->dynamicCall("SetVisible(bool)",false);
    QAxObject *workbooksResult=excelResult->querySubObject("Workbooks");
    QAxObject *workbookResult=workbooksResult->querySubObject("Add()");
    qDebug()<<"После того как нашел";
    QAxObject* sheetsResult=workbookResult->querySubObject("Sheets");
    qDebug()<<"Лист1 или всетаки shit?";
    QAxObject* sheetResult = sheetsResult->querySubObject("Item(int)", 1);
    excelResult->setProperty("DisplayAlerts", false);

    //строки
    QAxObject* usedRange = sheet->querySubObject("UsedRange");
    QAxObject* rows = usedRange->querySubObject("Rows");
    int countRows = rows->property("Count").toInt();

    int schotchik=1;//счетчик строки в записываемой таблице

    for (int lol = 0; lol <= countRows-2; lol++ )
               {
             if(Actual[lol]==true)
                   {
                 for(int Colis=1;Colis<11;Colis++)
                       {

                       QAxObject* columnresult=sheetResult->querySubObject("Columns(int)",Colis);

                       QAxObject* cell = sheet->querySubObject("Cells(int,int)", lol+2  , Colis );
                       QVariant value = cell->property("Value");
                       QStringList valuev=value.toStringList();
                       QAxObject* cellResult = sheetResult->querySubObject("Cells(int,int)",schotchik,Colis);
                       if(schotchik==1)
                       {
                           if(Colis==1) cellResult->dynamicCall("SetValue(const QString&)", "Идентификатор УБИ");
                           if(Colis==2) cellResult->dynamicCall("SetValue(const QString&)", "Наименование УБИ");
                           if(Colis==3) cellResult->dynamicCall("SetValue(const QString&)", "Описание");
                           if(Colis==4) cellResult->dynamicCall("SetValue(const QString&)", "Источник угрозы (характеристика и потенциал нарушителя)");
                           if(Colis==5) cellResult->dynamicCall("SetValue(const QString&)", "Объект воздействия");
                           if(Colis==6) cellResult->dynamicCall("SetValue(const QString&)", "Нарушение конфиденциальности");
                           if(Colis==7) cellResult->dynamicCall("SetValue(const QString&)", "Нарушение целостности");
                           if(Colis==8) cellResult->dynamicCall("SetValue(const QString&)", "Нарушение доступности"); //
                           if(Colis==9) cellResult->dynamicCall("SetValue(const QString&)", "Дата включения угрозы в БДУ");
                           if(Colis==10) cellResult->dynamicCall("SetValue(const QString&)", "Дата последнего изменения данных");
                       }
                       else
                       {
                           qDebug()<<"dynamiccall "<<lol;
                           cellResult->dynamicCall("SetValue(const QVariant&)", value);
                       }

                       columnresult->dynamicCall("setColumnWidth(int)",27); //14,4

                       }

                       QAxObject* rowresult=sheetResult->querySubObject("Rows(int)",schotchik);
                       rowresult->dynamicCall("setRowHeight(int)",14);
                       b++;
                       schotchik++;
                   }
               }


    qDebug()<<"after dynamiccall ";
    workbookResult->dynamicCall("SaveAs(const QString&)","Модель угроз");
    workbookResult->dynamicCall("Close()");
    excelResult->dynamicCall("Quit()");
    qDebug()<<"after quit ";
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");

}
