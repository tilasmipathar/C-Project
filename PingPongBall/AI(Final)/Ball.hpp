bool PointIntersection1(SDL_Rect temp, int x, int y)
{
    if(x > temp.x && y > temp.y && x < temp.x + temp.w && y < temp.y + temp.h)
    {
        return true;
    }
    return false;
}

bool CollisionChecker1(SDL_Rect temp1, SDL_Rect temp2)
{
    if(PointIntersection1(temp2, temp1.x, temp1.y) || PointIntersection1(temp2, temp1.x + temp1.w, temp1.y) || PointIntersection1(temp2, temp1.x, temp1.y + temp1.h) || PointIntersection1(temp2, temp1.x + temp1.w, temp1.y + temp1.h))
    {
        return true;
    }
    return false;
}

void ResetBall1()
{
    Ball.x = ball_x;
    Ball.y = ball_y;

    velX = GenerateRandomNum(2, -2);
    velY = GenerateRandomNum(2, -2);
}
