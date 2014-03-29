#ifndef QLED_H
#define QLED_H

#include <QDeclarativeItem>

class QLED : public QDeclarativeItem
{
    Q_OBJECT
    Q_DISABLE_COPY(QLED)

public:
    QLED(QDeclarativeItem *parent = 0);
    ~QLED();
};

QML_DECLARE_TYPE(QLED)

#endif // QLED_H

