#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);

signals:
    void changed(double v);

public slots:
    void onChange(double v);

private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue;
    float secondValue;
};

#endif // SPEED_H
