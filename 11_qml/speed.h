#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value
               READ getValue
               WRITE setValue
               NOTIFY speedChanged)
public:
    explicit Speed(QObject *parent = nullptr);

        Q_INVOKABLE void setValue(float v);
        Q_INVOKABLE float getValue() const;

signals:
    void speedChanged(float v);

public slots:


private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue = 0;
    float secondValue = 0;
};

#endif // SPEED_H
