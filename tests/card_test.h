#ifndef CARD_TEST_H
#define CARD_TEST_H

#include <QObject>

class CardTest : public QObject {
    Q_OBJECT

private slots:
    void testSanity();
};

#endif // CARD_TEST_H
