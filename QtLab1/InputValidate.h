#pragma once

#define EXAMPLEVALIDATOR_H

#include <QValidator>

class InputValidate : public QValidator
{
	Q_OBJECT
public:
	InputValidate(QObject* parent);
	~InputValidate();
	QValidator::State validate(QString& input, int& pos) const;
private:
};

