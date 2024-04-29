#include "Pages.h"
#include "InputValidate.h"
#include <QtWidgets/QApplication>
#include <QValidator>

//1 способ - С возможностью вводить любые символы
bool isValidInput(const QString& input) {
    QStringList sections = input.split(",");
    foreach(QString section, sections) {

        if (section.contains("-")) {
            QStringList range = section.split("-");
            if (range.size() != 2) return QValidator::Invalid;

            bool ok;
            int start = range[0].toInt(&ok);
            if (!ok || start <= 0) return QValidator::Invalid;

            int end = range[1].toInt(&ok);
            if (!ok || end <= 0 || end <= start) return QValidator::Invalid;
        }
        else {
            bool ok;
            int number = section.toInt(&ok);
            if (!ok || number <= 0) return QValidator::Invalid;
        }
    }
    return QValidator::Acceptable;
}


Pages::Pages(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QValidator* ev = new InputValidate(this);
    ui.lineEdit_PageInput->setValidator(ev);

    


    connect(ui.pushButton_OK, SIGNAL(clicked()), this, SLOT(IsOk()));

    
    
    //2 способ - Без возможности вводить любые символы
    //QRegExp regExp("^\\d+(-\\d+)?(,\\d+(-\\d+)?)*$");
    QRegExp regExp("^[1-9]\\d*(-[1-9]\\d*)?(,[1-9]\\d*(-[1-9]\\d*)?)*$");
    ui.lineEdit_PageInput->setValidator(new QRegExpValidator(regExp));
    
    
}


void Pages::IsOk() {
    //if (ui.lineEdit_PageInput->hasAcceptableInput())
    if (isValidInput(ui.lineEdit_PageInput->text()))
        QMessageBox::information(this, "Success", "String is correct");
    else
        QMessageBox::warning(this, "Error", "String is incorrect");
}