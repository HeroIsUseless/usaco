/*
ID:22920179
PROB:castle
LANG:C++
*/
#include <iostream>
#include "cstring"
#include "algorithm"
using namespace std;

typedef struct Room{
    bool isUsed = false;
    bool northWall = false;
    bool southWall = false;
    bool westWall = false;
    bool eastWall = false;
} Room;
int m, n;
Room room[55][55]; // 房间单位
int roomCount, roomSize[2600], roomsize;
void dfs(int ci, int cj){
    if(room[ci][cj].isUsed == true){
        return;
    }else{
        roomsize++;
        room[ci][cj].isUsed = true;
        if(room[ci][cj].eastWall==false && cj<m){
            dfs(ci, cj+1);
        }
        if(room[ci][cj].westWall==false && cj>1){
            dfs(ci, cj-1);
        }
        if(room[ci][cj].southWall==false && ci<n){
            dfs(ci+1, cj);
        }
        if(room[ci][cj].northWall==false && ci>1){
            dfs(ci-1, cj);
        }
    }
}
int theSizeOfRoom(){
    roomCount = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            room[i][j].isUsed = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(room[i][j].isUsed == false){
                dfs(i, j); // 一次深搜获得一个房间
                roomSize[roomCount++] = roomsize;
                roomsize = 0;
            }
        }
    }
    sort(roomSize, roomSize+roomCount);
    return roomSize[roomCount-1];
}
int main(){
    FILE *pFile1 = fopen("castle.in", "r");
    FILE *pFile2 = fopen("castle.out", "w");
    fscanf(pFile1, "%d%d", &m, &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int t;
            fscanf(pFile1, "%d", &t);
            if(t >= 8){
                t -= 8;
                room[i][j].southWall = true;
            }
            if( t >= 4){
                t -= 4;
                room[i][j].eastWall = true;
            }
            if( t >= 2){
                t -= 2;
                room[i][j].northWall = true;
            }
            if(t >= 1){
                t -= 1;
                room[i][j].westWall = true;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(room[i][j].isUsed == false){
                dfs(i, j); // 一次深搜获得一个房间
                roomSize[roomCount++] = roomsize;
                roomsize = 0;
            }
        }
    }
    sort(roomSize, roomSize+roomCount);
    cout << roomCount << endl;
    cout << roomSize[roomCount-1] << endl;
    fprintf(pFile2, "%d\n", roomCount);
    fprintf(pFile2, "%d\n", roomSize[roomCount-1]);
    int lagestRoom = 2;
    bool isN = true;
    int posX=n, posY=1;
    for(int j=m; j>=1; j--){
        for(int i=1; i<=n; i++){
            if(j!=m && room[i][j].eastWall){ // 拆右面的
                room[i][j].eastWall = false;
                room[i][j+1].westWall = false;
                int t = theSizeOfRoom();
                if(t >= lagestRoom){
                    lagestRoom = t;
                    posX = i; posY = j;
                    isN = false;
                }
                room[i][j].eastWall = true;
                room[i][j+1].westWall = true;
            }
            if(i!=1 && room[i][j].northWall){ // 拆上面的
                room[i][j].northWall = false;
                room[i-1][j].southWall = false;
                int t = theSizeOfRoom();
                if(t >= lagestRoom){
                    lagestRoom = t;
                    posX = i; posY = j;
                    isN = true;
                }
                room[i][j].northWall = true;
                room[i-1][j].southWall = true;
            }
        }
    }
    cout << lagestRoom <<endl;
    cout << posX <<" "<< posY <<" "<< (isN?"N":"E") <<endl;
    fprintf(pFile2, "%d\n", lagestRoom);
    fprintf(pFile2, "%d %d %s\n", posX, posY, (isN?"N":"E"));
    fclose(pFile1); fclose(pFile2);
	return 0;
}
