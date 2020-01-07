#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value
               READ getValue
               WRITE setValue
               NOTIFY accelerationChanged)
public:
    explicit Acceleration(QObject *parent = nullptr);

    Q_INVOKABLE void setValue(float v);
    Q_INVOKABLE float getValue();

signals:
    void accelerationChanged(float v);

public slots:

private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue = 0;
    float secondValue = 0;
};

#endif // ACCELERATION_H
