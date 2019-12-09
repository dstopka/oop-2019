#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

signals:
    void changed(double v);

public slots:
    void onChange(double v);
private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;
};

#endif // ACCELERATION_H
