#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double value
               READ getSpeed
               WRITE setSpeed
               NOTIFY changed)
public:
    explicit Speed(QObject *parent = nullptr);

        Q_INVOKABLE void setSpeed(double v);
        Q_INVOKABLE float getSpeed();

signals:
    void changed(double v);

public slots:


private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue;
    float secondValue;
    float value;
};

#endif // SPEED_H
