#ifndef THREATMODELV2_H
#define THREATMODELV2_H

#include <QMainWindow>
#include <QCheckBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QSettings>


namespace Ui {
class threatmodelv2;
}

class threatmodelv2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit threatmodelv2(QWidget *parent = 0);
    ~threatmodelv2();



private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_activated(const QModelIndex &index);

    void on_checkBox_29_clicked();

    void on_action_triggered();



    void on_action_2_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::threatmodelv2 *ui;
    QGridLayout*layout;
    QLabel	   *label;
    QSettings* settings;




};

#endif // THREATMODELV2_H
