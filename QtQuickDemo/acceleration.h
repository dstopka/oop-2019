#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double value
               READ getAcc
               WRITE setAcc
               NOTIFY changed)
public:
    explicit Acceleration(QObject *parent = nullptr);

    Q_INVOKABLE void setAcc(double v);
    Q_INVOKABLE float getAcc();

signals:
    void changed(double v);

public slots:

private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;
    float value;
};

#endif // ACCELERATION_H
