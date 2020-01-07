#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value
               READ getDisplacement
               WRITE setDisplacement
               NOTIFY displacementChanged)
public:
    explicit Displacement(QObject *parent = nullptr);

   Q_INVOKABLE void setDisplacement(float v);
   float getDisplacement() const;

signals:
    void displacementChanged(float v);

public slots:

private:
    float value;
};

#endif // DISPLACEMENT_H
