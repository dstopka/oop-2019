#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double value
               READ getDisplacement
               WRITE setDisplacement
               NOTIFY displacementChanged)
public:
    explicit Displacement(QObject *parent = nullptr);

   Q_INVOKABLE void setDisplacement(double v);
   double getDisplacement() const;

signals:
    void displacementChanged(double v);

public slots:

private:
    double value;
};

#endif // DISPLACEMENT_H
