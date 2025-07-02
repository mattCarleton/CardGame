#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <QObject>

class PlayerTest : public QObject {
    Q_OBJECT

private slots:
    void testPlayerCreation(void);
    void testPlayerAdd(void);
    void testPlayerDraw(void);
    void testPlayerStand(void);
    void testPlayerScore(void);
    void testAce(void);
    void testBlackjack(void);
};

#endif // PLAYER_TEST_H
