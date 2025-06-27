#include <QtTest>
#include "card_test.h"
#include "deck_test.h"
#include "player_test.h"

int main(int argc, char** argv) {
    int result = 0;

    CardTest cardTest;
    result |= QTest::qExec(&cardTest, argc, argv);

    DeckTest deckTest;
    result |= QTest::qExec(&deckTest, argc, argv);

    PlayerTest playerTest;
    result |= QTest::qExec(&playerTest, argc, argv);

    return result;
}
