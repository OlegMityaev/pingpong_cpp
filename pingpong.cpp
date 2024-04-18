#include <iostream>
#include <cmath>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#define	  stop __asm nop

//system("cls");
int main()
{
    /*
    int score = 0;
    int button = _getch();
    printf("%d", button);
    //getch();*/

    bool game_flag = true;
    std::string str_bot = "_______";
    std::string str_player = "_______";
    std::string probel_bot = "";
    std::string probel_player = "";
    std::string sharik = "*";
    std::string x_sharik = "";
    std::string y_sharik = "\n";

    int znak[] = { -1, 1 };

    int y_sharik_c = 1;
    int x_sharik_c = 0;
    int delta_y = 1;
    int delta_x = 1;
    char ent;
    int i = 0;

    std::string width = "";
    std::string height = "";
    std::string horizontal_line = "";
    std::string vertical_line = "";
    for (int i = 0; i < 48; ++i)
    {
        width += " ";
    }
    for (int i = 0; i < 21; ++i)
    {
        height += "\n";
    }
    for (int i = 0; i < 48; ++i)
    {
        horizontal_line += "_";
    }
    for (int i = 0; i < 21; ++i)
    {
        vertical_line += width + "|\n";
    }

    //std::cout << vertical_line ;
    int x_player = 0;
    while (game_flag)
    {
        //sharik

        while (!_kbhit())
        {
            std::cout << probel_player + str_player;

            std::cout << y_sharik << x_sharik << sharik;
            if (delta_x > 0)
            {
                for (int j = 0; j < delta_x; ++j)
                {
                    x_sharik += " ";
                }
            }
            else
            {
                for (int j = 0; j < abs(delta_x); ++j)
                {
                    if (x_sharik.size() > 0)
                    {
                        x_sharik.pop_back();
                    }
                }
            }
            if (delta_y > 0)
            {
                y_sharik += "\n";
            }
            else
            {
                y_sharik.pop_back();
            }

            y_sharik_c += delta_y;
            x_sharik_c += delta_x;

            if (y_sharik_c >= 20)
            {
                delta_y = -1;
                delta_x = znak[std::rand() % 2] * (std::rand() % 3 + 1);
            }
            if (x_sharik_c >= 47)
            {
                delta_x = -(std::rand() % 3 + 1);
            }
            if (y_sharik_c <= 1)
            {
                if (x_sharik_c < x_player || x_sharik_c > x_player + 6)
                {
                    system("cls");
                    game_flag = false;
                    std::cout << "You lose, loh ebaniy hahahahahah" << std::endl;
                    break;
                }

                delta_y = 1;
                delta_x = znak[std::rand() % 2] * (std::rand() % 3 + 1);
            }
            if (x_sharik_c <= 0)
            {
                delta_x = (std::rand() % 3 + 1);
            }


            Sleep(100);
            system("cls");
        }

        //player

        ent = _getch();

        if (ent == 'd')
        {
            if (x_player >= 50)
            {
                continue;
            }
            if (probel_player.size() < 50)
            {
                probel_player += "   ";
                x_player += 3;
            }
        }
        else if (ent == 'a')
        {
            if (x_player <= 0)
            {
                continue;
            }
            if (probel_player.size() > 1)
            {
                probel_player.pop_back();
                probel_player.pop_back();
                probel_player.pop_back();
                x_player -= 3;
            }
        }
    }
    return 0;
}
