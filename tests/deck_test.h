#ifndef DECK_TEST_H
#define DECK_TEST_H

#include <QObject>

class DeckTest : public QObject {
    Q_OBJECT

private slots:
    void testDeckGenerate(void);
    void testShuffler(void);
    void testDraw(void);
};

#endif // DECK_TEST_H
