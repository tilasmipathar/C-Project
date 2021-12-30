#include "Map.hpp"
#include "TextManager.hpp"

int lvl1[25][30] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,7,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,5,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

Map::Map(){ 
    bumper_30 = TextManager::Loadtexture("../assets/bumper30.png");
    bumper_20 = TextManager::Loadtexture("../assets/bumper20.png");
    bumper_10 = TextManager::Loadtexture("../assets/bumper10.png");
    side = TextManager::Loadtexture("../assets/side_bumper.png");
    hbump = TextManager::Loadtexture("../assets/hbumper.png");
    mulx2 = TextManager::Loadtexture("../assets/multi.png");
    mulx3 = TextManager::Loadtexture("../assets/multi.png");
    mulx5 = TextManager::Loadtexture("../assets/5x.png");

    board = TextManager::Loadtexture("../assets/pinball.png");

    LoadMap(lvl1);

    srcM.x = srcM.y = 0;
    srcM.w = destM.w = 470;
    srcM.h = destM.h = 700;
    destM.x = 150;
    destM.y = 0;

}

void Map::LoadMap(int arr[25][30]){

    for(int row=0;row<20;row++){
        for(int column=0;column<25;column++){
            map[row][column] = arr[row][column]; 
        }
    }
}

void Map::DrawMap(){

    int type = 0;
    
    TextManager::Draw(board,srcM,destM);

    for(int row=0;row<20;row++){
        for(int column=0;column<25;column++){
            type = map[row][column];

                dest.x = column*32;
                dest.y = row* 32;
                switch (type)
                {
                case 0:
                    break;

                case 1:
                    src.x = 60;
                    src.y = 10;
                    src.w = src.h = 350;
                    dest.w =90;
                    dest.h = 90;
                    TextManager::Draw(bumper_10,src,dest);
                    break;

                case 2:
                    src.x = 50;
                    src.y = 10;
                    src.w = src.h = 350;
                    dest.w =90;
                    dest.h = 90;
                    TextManager::Draw(bumper_20,src,dest);
                    break;

                case 3:
                    src.x = 530;
                    src.y = 650;
                    src.w = src.h = 350;
                    dest.w =80;
                    dest.h = 90;
                    TextManager::Draw(bumper_30,src,dest);
                    break;
            
                case 4:
                    src.x = 640;
                    src.y = 550;
                    src.w = src.h = 500;
                    dest.w =100;
                    dest.h = 130;
                    TextManager::Draw(side,src,dest);
                    break;

                case 5:
                    src.x = 500;
                    src.y = 500;
                    src.w = src.h = 500;
                    dest.w =100;
                    dest.h = 130;
                    TextManager::Draw(hbump,src,dest);
                    break;

                case 6:
                    src.x = 110;
                    src.y = 110;
                    src.w = src.h = 150;
                    dest.w = 35;
                    dest.h = 35;
                    TextManager::Draw(mulx2,src,dest);
                    break;

                case 7:
                    src.x = 255;
                    src.y = 140;
                    src.w = 200;
                    src.h = 150;
                    dest.w = 48;
                    dest.h = 35;
                    TextManager::Draw(mulx3,src,dest);
                    break;

                case 8:
                    src.x = 590;
                    src.y = 740;
                    src.w = 300;
                    src.h = 200;
                    dest.w = 70;
                    dest.h = 50;
                    TextManager::Draw(mulx5,src,dest);
                    break;

            default:
                break;
            } 
        }
    }
}