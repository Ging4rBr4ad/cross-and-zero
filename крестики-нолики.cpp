#include <iostream>
#include <cstring>
#include <ctime>
#include <Windows.h>
#include <cstdlib>

void game(short menuitem1, short menuitem2, int arr[][3], std::string arrshow[][3], short cell);
void show(short cell, std::string arrshow[][3]);
void menu(short& menuitem1, short& menuitem2);
int wincheck(int arr[][3], short cell);

int main()
{
    // объявление переменных
    const short cell{3};
     std::string arrshow[cell][cell];
    int arr[cell][cell];
    short menuitem1{}, menuitem2{}, repeat{1};

    do
    {
    menu(menuitem1, menuitem2);

    //заполнение полей
    for (int i{}, k{4}; i < cell; i++, k++)
    {
        for (int j{}; j < cell; j++)
        {
            k++;
            arrshow[i][j] = " ";
            arr[i][j] = k;
        }
    }

    game(menuitem1, menuitem2, arr, arrshow, cell);
    
    std::cout << "Сыграть снова?\n"
                "1 - да!\n"
                "2 - нет\n";
    std::cin >> repeat;
    } while(repeat != 2);

    std::cout << "Хорошего дня!";
    return 0;
}

void game(short menuitem1, short menuitem2, int arr[][3], std::string arrshow[][3], short cell)
{
    short crosscol{}, crossstr{}, zerocol{}, zerostr{}, end{};
    std::srand(std::time(nullptr));

    // игрок против игрока
    if (menuitem1 == 1)
    {
        do
        {
            system("cls");
            show(cell, arrshow);

            std::cout << "\n\nИгрок1 ходит\n";
                do
                {
                    std::cout << "Введите номер столбца: ";
                    std::cin >> crosscol;
                } while (crosscol > 3 || crosscol < 1);
                do
                {
                    std::cout << "Введите номер ряда: ";
                    std::cin >> crossstr;
                } while (crossstr > 3 || crossstr < 1);
            
            crosscol--;
            crossstr--;
            arrshow[crossstr][crosscol] = "X";
            arr[crossstr][crosscol] = 1;

            if (wincheck(arr, cell))
                {
                    system("cls");
                    show(cell, arrshow);
                    std::cout << "Игрок1 выиграл!\n";
                    end = 1;
                    break;
                }

            system("cls");
            show(cell, arrshow);

            std::cout << "\n\nИгрок2 ходит\n";
                do
                {
                    std::cout << "Введите номер столбца: ";
                    std::cin >> zerocol;
                } while (zerocol > 3 || zerocol < 1);
                do
                {
                    std::cout << "Введите номер ряда: ";
                    std::cin >> zerostr;
                } while (zerostr > 3 || zerostr < 1);

            zerocol--;
            zerostr--;
            arrshow[zerostr][zerocol] = "O";
            arr[zerostr][zerocol] = 2;

            if (wincheck(arr, cell))
                {
                    system("cls");
                    show(cell, arrshow);
                    std::cout << "Игрок2 выиграл!\n";
                    end = 1;
                    break;
                }

        } while (end == 0);
    }

    // игрок против компьютера
    if (menuitem1 == 2)
    {
      do
        {
            system("cls");
            show(cell, arrshow);

            std::cout << "\n\nИгрок ходит\n";
                do
                {
                    std::cout << "Введите номер столбца: ";
                    std::cin >> crosscol;
                } while (crosscol > 3 || crosscol < 1);
                do
                {
                    std::cout << "Введите номер ряда: ";
                    std::cin >> crossstr;
                } while (crossstr > 3 || crossstr < 1);
            
            crosscol--;
            crossstr--;
            arrshow[crossstr][crosscol] = "X";
            arr[crossstr][crosscol] = 1;

            if (wincheck(arr, cell))
                {
                    system("cls");
                    show(cell, arrshow);
                    std::cout << "Игрок1 выиграл!\n";
                    end = 1;
                    break;
                }

            system("cls");
            show(cell, arrshow);

            std::cout << "\n\nБот ходит\n     ";
                Sleep(200);
                std::cout << ". ";
                Sleep(200);
                std::cout << ". ";
                Sleep(200);
                std::cout << ". ";
                Sleep(200);

            do
            {
                zerocol = std::rand() % 3;
                zerostr = std::rand() % 3;
            } while (arr[zerostr][zerocol] == 2 || arr[zerostr][zerocol] == 1);

            arrshow[zerostr][zerocol] = "O";
            arr[zerostr][zerocol] = 2;

            if (wincheck(arr, cell))
                {
                    system("cls");
                    show(cell, arrshow);
                    std::cout << "Бот выиграл!\n";
                    end = 1;
                    break;
                }

        } while (end == 0);
    }
    
}

void menu(short& menuitem1, short& menuitem2)
{
    std::cout << "----КРЕСТИКИ-НОЛИКИ----\n";
    do
    {
        std::cout << "Выберите режим игры:\n"
                    "1 - Игрок VS Игрок\n"
                    "2 - Игрок VS Компьютер\n";
        std::cin >> menuitem1;
    } while (menuitem1 < 1 || menuitem1 > 2);
    system("cls");
}

int wincheck(int arr[][3], short cell)
{
    int win{};

    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
        win = 1;
    else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
        win = 1;

    else if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2])
        win = 1;
    else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2])
        win = 1;
    else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2])
        win = 1;

    else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0])
        win = 1;
    else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1])
        win = 1;
    else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2])
        win = 1;

    return win;
}

void show(short cell, std::string arrshow[][3])
{
    std::cout << "\n\n\n\t\t   1    2    3\n"
            "\t\t---------------\n\t\t";
    for (int i{}; i < cell; i++)
    {
        std::cout << (1 + i) << ' ';
        for (int j{}; j < cell; j++)
        {
            std::cout << "| " << arrshow[i][j] << ' ';
        }
        std::cout << "|"
                     "\n\t\t---------------\n\t\t";
    }
}