#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <string.h>
#include "life.h"

/* Be sure to read life.h and the other given source files to understand
 * what they provide and how they fit together.  You don't have to
 * understand all of the code, but you should understand how to call
 * parse_life() and clearterm().
 */

/* This is where your program will start.  You should make sure that it
 * is capable of accepting either one or two arguments; the first
 * argument (which is required) is a starting state in one of the Life
 * formats supported by parse_life(), and the second (which is optional)
 * is a number of generations to run before printing output and stopping.
 *
 * The autograder will always call your program with two arguments.  The
 * one-argument format (as described in the handout) is for your own
 * benefit!
 */
int main(int argc, char *argv[])
{
    if(argc == 3){
    int generation = atoi(argv[2]);
    char **a = parse_life(argv[1]);
    void use_matrix(char grid[GRIDY+2][GRIDX+2]);
    char grids[2][GRIDY+2][GRIDX+2];//GRIDY+2=26;GRIDX+2=82

    for(int i = 0;i<24;i++){
        for (int j = 0; j<80;j++){
            grids[0][i+1][j+1] = a[i][j];
        }
    }
    for(int i = 0;i<24;i++){
        for (int j = 0; j<80;j++){
            grids[1][i+1][j+1] = a[i][j];
        }
    }
    for(int si = 0; si<82;si++){
        grids[0][0][si] = DEAD;// x shangde siwang di1pai
        grids[0][25][si] = DEAD;//di25pai zuihouyipai
        grids[1][0][si] = DEAD;
        grids[1][25][si] = DEAD;
    }
    for(int wang = 0; wang<26;wang++){
        grids[0][wang][0] = DEAD;//y shangde siwang di1pai
        grids[0][wang][81]= DEAD;//di81pai zuihouyipai
        grids[1][wang][0] = DEAD;
        grids[1][wang][81] = DEAD;
    }

    if(generation == 0){
        for(int i = 0; i < 24; i ++){
            for(int j = 0; j < 80; j++){
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    else if(generation<0){
        printf("should input postive number");
        return 1;
    }
    else if (generation>0){
        for(int times=0;times<generation;times++){
            for(int i = 1;i<25;i++){
                for(int j = 1;j<81;j++){
                    int countL = 0;
                    for(int time = 1;time<2;time++){//for 1 ci
                        if(grids[0][i-1][j-1]==LIVE){countL++;}
                        if(grids[0][i-1][j]==LIVE){countL++;}
                        if(grids[0][i-1][j+1]==LIVE){countL++;}
                        if(grids[0][i][j-1]==LIVE){countL++;}
                        if(grids[0][i][j+1]==LIVE){countL++;}
                        if(grids[0][i+1][j-1]==LIVE){countL++;}
                        if(grids[0][i+1][j]==LIVE){countL++;}
                        if(grids[0][i+1][j+1]==LIVE){countL++;}
                    }
                    if(grids[0][i][j]==LIVE){//if cell is live // change [1] for putchar
                        if(countL < 2){
                            grids[1][i][j]=DEAD;
                        }
                        else if(countL>3){
                            grids[1][i][j]=DEAD;
                        }
                        else if(countL==2||countL==3){
                            grids[1][i][j]=LIVE;
                        }
                    }
                    else if(grids[0][i][j]==DEAD){//if cell is dead
                        if(countL==3){
                            grids[1][i][j]=LIVE;}
                    }
                }
            }
            for(int i = 0;i<26;i++){
                for(int j = 0;j<82;j++){
                    grids[0][i][j]=grids[1][i][j];
                }
                    }
        }
        char nowgrids[GRIDY][GRIDX];
        for(int i = 0;i<24;i++){
            for (int j = 0; j<80;j++){
                nowgrids[i][j] = grids[1][i+1][j+1];
            }
        }
        for(int i = 0;i<24;i++){
            for(int j = 0;j<80;j++){
                a[i][j] = nowgrids[i][j];
            }
        }
        for(int i = 0; i < 24; i ++){
            for(int j = 0; j < 80; j++){
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
}
    else{
        printf("ERROR\n");
        return 1;
    }
    return 0;
}
