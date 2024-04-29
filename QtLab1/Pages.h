#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Pages.h"
#include <QMainWindow>
#include <QMessageBox>

class Pages : public QMainWindow
{
    Q_OBJECT

public:
    Pages(QWidget *parent = Q_NULLPTR);

private:
    Ui::PagesClass ui;
private slots:
    void IsOk();
};
