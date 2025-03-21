#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime=GetTime();
    if(currentTime-lastUpdateTime>=interval)
    {
        lastUpdateTime=currentTime;
        return true;
    }
    return false;
}
int main()
{
    InitWindow(500, 620, "raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/Exo2.ttf", 64, 0, 0);



    Game game=Game();

    while(!WindowShouldClose())
    {
        game.HandleInput();
        if(EventTriggered(0.2))
            game.MoveBlockDown();
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365,15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365,175}, 38, 2, WHITE);
        if(game.gameOver)
            DrawTextEx(font, "Game Over", {320,450}, 38, 2, WHITE);
        DrawRectangleRounded({320,55,170,60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText,"%d",game.score);
        Vector2 textSize= MeasureTextEx(font, scoreText,38,2);

        DrawTextEx(font, scoreText, {320 + (170-textSize.x)/2,65}, 38, 2, WHITE);
        DrawRectangleRounded({320,215,170,180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}