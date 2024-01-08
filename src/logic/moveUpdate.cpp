#include "gameLogic.h"

namespace gameLogic{
    void updateGameMatrix(int v[4][4], int width, int height, Direction direct){
        switch(direct){
            case Up:
                for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        for(int x = j-1; x >= 0; x--){
                            if(v[x][i] != 0 && v[j][i] != v[x][i])
                                break;
                            else if(v[j][i] == v[x][i]){
                                v[x][i] *= 2;
                                v[j][i] = 0;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(v[j][i] == 0)
                            for(int x = j+1; x < 4; x++)
                                if(v[x][i] != 0){
                                    v[j][i] = v[x][i];
                                    v[x][i] = 0;
                                    break;
                                }
            break;

            case Down:
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        for(int x = j+1; x < 4; x++){
                            if(v[x][i] != 0 && v[j][i] != v[x][i])
                                break;
                            else if(v[j][i] == v[x][i]){
                                v[x][i] *= 2;
                                v[j][i] = 0;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        if(v[j][i] == 0)
                            for(int x = j-1; x >= 0; x--)
                                if(v[x][i] != 0){
                                    v[j][i] = v[x][i];
                                    v[x][i] = 0;
                                    break;
                                }
                break;
            
            case Left:
            	for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        for(int x = j-1; x >= 0; x--){
                            if(v[i][x] != 0 && v[i][j] != v[i][x])
                                break;
                            else if(v[i][j] == v[i][x]){
                                v[i][x] *= 2;
                                v[i][j] = 0;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(v[i][j] == 0)
                            for(int x = j+1; x < 4; x++)
                                if(v[i][x] != 0){
                                    v[i][j] = v[i][x];
                                    v[i][x] = 0;
                                    break;
                                }
            break;

            case Right:
            	for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        for(int x = j+1; x < 4; x++){
                            if(v[i][x] != 0 && v[i][j] != v[i][x])
                                break;
                            else if(v[i][j] == v[i][x]){
                                v[i][x] *= 2;
                                v[i][j] = 0;
                            }
                        }

                for(int i = 0; i < 4; i++)
                    for(int j = 3; j >= 0; j--)
                        if(v[i][j] == 0)
                            for(int x = j-1; x >= 0; x--)
                                if(v[i][x] != 0){
                                    v[i][j] = v[i][x];
                                    v[i][x] = 0;
                                    break;
                                }
            break;
        }
    }
}