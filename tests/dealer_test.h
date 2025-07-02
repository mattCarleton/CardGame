#ifndef DEALER_TEST_H
#define DEALER_TEST_H

#include <QObject>

class DealerTest : public QObject {
    Q_OBJECT

private slots:
    void testAutoHit(void);
    void testAutoStand(void);
};

#endif // DEALER_TEST_H
