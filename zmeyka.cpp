#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

struct StructSnake {
    int x, y;
    StructSnake* next;
};

class Snake {
private:
    StructSnake* head;
    int width, height;
    int foodX, foodY;
    bool dead = false;
    char currentDirection;
public:
    bool up = true, down = true, left = true, right = true;
    int score = 0;
    Snake(int n, int m) : width(m), height(n) {
        head = nullptr;
        currentDirection = 'd';
        srand(time(0));
        foodX = rand() % (width - 2) + 1;
        foodY = rand() % (height - 2) + 1;
        initSnake();
    }

    void initSnake() {
        head = new StructSnake{ width / 2, height / 2, nullptr };
    }

    void Field() {
        system("cls");
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height - 1)
                    cout << "O";
                else if (j == 0 || j == width - 1) 
                    cout << "O";
                else if (i == foodY && j == foodX)
                    cout << "$";
                else if (isSnake(j, i))
                    cout << "+";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }

    bool isSnake(int x, int y) {
        StructSnake* curr = head;
        while (curr != nullptr) {
            if (curr->x == x && curr->y == y) 
                return true;
            curr = curr->next;
        }
        return false;
    }

    bool isdead() {
        if (dead)
            cout << "game over.";
        return dead;
    }

    void update() {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
                currentDirection = ch;
        }
        int newX = head->x, newY = head->y;
        switch (currentDirection) {
        case 'w': {
            if (up) {
                newY--;
                up = true;
                down = false;
                left = true;
                right = true;
            }
            else
                newY++;
            break;
        }
        case 'a': {
            if (left) {
                newX--;
                up = true;
                down = true;
                left = true;
                right = false;
            }
            else
                newX++;
            break; 
        }
        case 's': {
            if (down) {
                newY++;
                up = false;
                down = true;
                left = true;
                right = true;
            }
            else
                newY--;
            break;
        }
        case 'd': {
            if (right) {
                newX++;
                up = true;
                down = true;
                left = false;
                right = true;
            }
            else
                newX--;
            break;
        }
        }
        if (newX == 0 || newX == width - 1 || newY == 0 || newY == height - 1 || isSnake(newX, newY)) {
            dead = true;
            return;
        }
        StructSnake* newHead = new StructSnake{ newX, newY, head };
        head = newHead;
        if (newX == foodX && newY == foodY) {
            score++;
            foodX = rand() % (width - 2) + 1;
            foodY = rand() % (height - 2) + 1;
        }
        else {
            StructSnake* curr = head;
            StructSnake* prev = nullptr;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            delete curr;
            prev->next = nullptr;
        }
        cout << endl;
        cout << "score: " << score;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    /*int difficult, n = 1, m = 1;
    cout << "выберите сложность\n1 - легко\n2 - средне\n3 - сложно" << endl;
    cin >> difficult;
    switch (difficult)
    {
    case 1: {
        n = 10, m = 20;
        break;
    }
    case 2: {
        n = 20, m = 40;
        break;
    }
    case 3: {
        n = 30, m = 60;
        break;
    }
    default:
        cout << "error";
        return 1;
    }
    Snake snake(n, m);
    while (!snake.isdead()) {
        snake.Field();
        snake.update();
        Sleep(100);
    }*/

    struct point {
        int x, y;
    };
    point p;
    p.x = 23;
    p.y = 2;
    int b;
    cout << &p << endl;
    point* n;
    n = &p;
    cout << n->x << endl;

    return 0;
}