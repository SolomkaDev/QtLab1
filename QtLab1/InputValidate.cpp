#include "InputValidate.h"
#include <QString>
#include <QValidator>
#include <QDebug>


InputValidate::InputValidate(QObject* parent)
	: QValidator(parent)
{

}

InputValidate::~InputValidate()
{

}


QValidator::State InputValidate::validate(QString& input, int& pos) const
{
	/*
	if (input.contains(QChar('\d'))) return QValidator::Invalid;
	//if (input.contains(QChar('\\'))) return QValidator::Invalid;
	if (!input.contains(QChar('@'))) return QValidator::Intermediate;
	return QValidator::Acceptable;
	*/

    /*
    bool valid = true;
    QStringList numbers = input.split(",", Qt::SkipEmptyParts);
    foreach(QString number, numbers) {
        QStringList range = number.split("-");
        if (range.size() == 1) {
            if (range[0].toInt() == 0 || range[0].startsWith("0")) {
                valid = false;
                break;
            }
        }
        else if (range.size() == 2) {
            if (range[0].toInt() == 0 || range[1].toInt() == 0 ||
                range[0].startsWith("0") || range[1].startsWith("0") ||
                range[0].toInt() >= range[1].toInt()) {
                valid = false;
                break;
            }
        }
        else {
            valid = false;
            break;
        }
    }

    if (!valid) return QValidator::Intermediate;
    return QValidator::Acceptable;
    */
    
    /*
    bool acceptable = true;
    bool intermediate = false;

    QStringList parts = input.split(",");

    for (const QString& part : parts) {
        if (part.contains("-")) {
            QStringList range = part.split("-");
            if (range.size() != 2) {
                acceptable = false;
                break;
            }
            bool ok1, ok2;
            int start = range[0].toInt(&ok1);
            int end = range[1].toInt(&ok2);
            if (!ok1 || !ok2 || start <= 0 || end <= 0 || start >= end) {
                acceptable = false;
                break;
            }
        }
        else {
            bool ok;
            int number = part.toInt(&ok);
            if (!ok || number <= 0) {
                acceptable = false;
                break;
            }
        }
    }

    if (!acceptable) return QValidator::Invalid;
    if (intermediate) return QValidator::Intermediate;
    return QValidator::Acceptable;
    */
    //if (input.contains(QRegularExpression("A-Za-z"))) return QValidator::Invalid;
    if (!input.contains(QRegularExpression("^\\d+(-\\d+)?(,\\d+(-\\d+)?)*$"))) return QValidator::Intermediate;
    return QValidator::Acceptable;
  
}
