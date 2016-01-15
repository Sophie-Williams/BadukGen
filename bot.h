#ifndef BOT_H
#define BOT_H

class bot
{
public:
    bot();
    int getDifficulty();
    void setDifficulty(int difficulty);
    void thisMove(int opponentPosX, int opponentPosY, bool tableValues[19][19]);

private:
    int difficulty;
};

#endif