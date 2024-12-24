//
// Created by wu on 24-12-16.
//
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define WALL '#'
#define PATH ' '
#define USER 'O'
#define END 'E'

void set_difficulty(int *len);
void init_maze(char **maze, int len);
void generate_maze(char **maze, int len, int x, int y);
void draw_maze(char **maze, int len);
void move(char **maze, int x, int y, char direction);
char get_key();
void update_maze(char **maze, int len);
void finish_maze();

struct {
    int x;
    int y;
}user_loc, end_loc;

int main(){
    // set the random seed
    srand((unsigned)time(NULL));
    // init the difficulty of the maze
    int length = 0;
    set_difficulty(&length);
    char **maze = malloc(length * sizeof(char *));
    for (int i = 0; i < length; i++){
        maze[i] = malloc(length * sizeof(char));
    }
    // init the maze
    init_maze(maze, length);
    // update the maze according to the user's input
    update_maze(maze, length);
    // finish the maze game
    finish_maze();
    // free the memory
    for (int i = 0; i < length; i++){
        free(maze[i]);
    }
    free(maze);
    // pause the screen
    system("pause");

    return 0;
}

void set_difficulty(int *len){
    printf("press w, a, s, d to move, and press b to quit.\n");
    printf("Please set the difficulty of the maze\n1\tEasy(9x9)\n2\tmedium(19x19)\n3\tHard(29x29)\n4\tAsian(49x49)\nwrite the number:");
    int difficulty = 0;
    scanf("%d", &difficulty);
    switch (difficulty) {
        case 1:
            *len = 11;
            break;
        case 2:
            *len = 21;
            break;
        case 3:
            *len = 31;
            break;
        case 4:
            *len = 51;
            break;
        default:
            system("cls");
            printf("Wrong input\n");
            set_difficulty(len);
    }
}

void init_maze(char **maze, const int len){
    // clear the screen
    system("cls");
    // init the wall around the maze
    for (int i = 0; i < len; i++){
        for (int ii = 0; ii < len; ii++){
            maze[i][ii] = WALL;
        }
    }
    // generate the entrance and the user's init location
    user_loc.x = 0;
    user_loc.y = 1;
    maze[user_loc.x][user_loc.y] = USER;
    // generate the maze
    generate_maze(maze, len, 1, 1);
    // generate the exit
    for (int i = len - 1; i > 0; i--){
        if (maze[i][len - 2] == PATH){
            maze[i][len - 1] = END;
            end_loc.x = i;
            end_loc.y = len - 1;
            break;
        }
    }
    // print the maze
    draw_maze(maze, len);
}

void generate_maze(char **maze, const int len, int x, int y){
    // make the current position a path
    maze[x][y] = PATH;
    // set four random directions
    int directions[4][2] = {
        {-1, 0}, // up
        {1, 0}, // down
        {0, -1}, // left
        {0, 1} // right
    };
    for (int i = 0; i < 4; i++){
        int rand_num = rand() % 4;
        int temp_x = directions[i][0];
        int temp_y = directions[i][1];
        directions[i][0] = directions[rand_num][0];
        directions[rand_num][0] = temp_x;
        directions[i][1] = directions[rand_num][1];
        directions[rand_num][1] = temp_y;
    }
    // generate the maze
    for (int i = 0; i < 4; i++){
        int new_x = x + directions[i][0] * 2;
        int new_y = y + directions[i][1] * 2;
        if (new_x > 0 && new_x < len - 1 && new_y > 0 && new_y < len - 1 && maze[new_x][new_y] == WALL){
            maze[x + directions[i][0]][y + directions[i][1]] = PATH;
            generate_maze(maze, len, new_x, new_y);
        }
    }
}

void draw_maze(char **maze, const int len){
    for (int i = 0; i < len; i++){
        for (int ii = 0; ii < len; ii++){
            if (maze[i][ii] == WALL){
                // set the wall background color to cyan
                printf("\033[46m%c\033[0m", maze[i][ii]);
            } else if (maze[i][ii] == PATH){
                // set the path background color to white
                printf("\033[47m%c\033[0m", maze[i][ii]);
            } else if (i == end_loc.x && ii == end_loc.y){
                // set the exit background color to red
                printf("\033[41m%c\033[0m", maze[i][ii]);
            } else if (maze[i][ii] == USER){
                // set the user front color to yellow
                printf("\033[47;30m%c\033[0m", maze[i][ii]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void move(char **maze, const int x, const int y, const char direction){
    switch (direction) {
        case 'w':
            if (maze[x - 1][y] != WALL){
                maze[x][y] = PATH;
                user_loc.x = x - 1;
                user_loc.y = y;
                maze[user_loc.x][user_loc.y] = USER;
            }
            break;
        case 'a':
            if (maze[x][y - 1] != WALL){
                maze[x][y] = PATH;
                user_loc.x = x;
                user_loc.y = y - 1;
                maze[user_loc.x][user_loc.y] = USER;
            }
            break;
        case 's':
            if (maze[x + 1][y] != WALL){
                maze[x][y] = PATH;
                user_loc.x = x + 1;
                user_loc.y = y;
                maze[user_loc.x][user_loc.y] = USER;
            }
            break;
        case 'd':
            if (maze[x][y + 1] != WALL){
                maze[x][y] = PATH;
                user_loc.x = x;
                user_loc.y = y + 1;
                maze[user_loc.x][user_loc.y] = USER;
            }
            break;
        default:
            break;
    }
}

char get_key(){
    int key_1 = 0;
    char key = '0';
    switch (key_1 = getch()) {
        case 119:
            key = 'w';
            break;
        case 97:
            key = 'a';
            break;
        case 115:
            key = 's';
            break;
        case 100:
            key = 'd';
            break;
        case 98:
            key = 'b';
            break;
        default:
            break;
    }
    return key;
}

void update_maze(char **maze, const int len){
    while(1){
        char direct = get_key();
        if (direct == 'b'){
            break;
        }
        move(maze, user_loc.x, user_loc.y, direct);
        // clear the screen
        system("cls");
        draw_maze(maze, len);
        // check if the user reaches the exit
        if (user_loc.x == end_loc.x && user_loc.y == end_loc.y){
            break;
        }
    }
}

void finish_maze(){
    if (user_loc.x == end_loc.x && user_loc.y == end_loc.y){
        printf("You reach the end!\n");
    } else {
        printf("You quit!\n");
    }
}
