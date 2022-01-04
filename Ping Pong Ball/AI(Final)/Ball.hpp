bool PointIntersection(SDL_Rect temp, int x, int y)
{
    if(x > temp.x && y > temp.y && x < temp.x + temp.w && y < temp.y + temp.h)
    {
        return true;
    }
    return false;
}

bool CollisionChecker(SDL_Rect temp1, SDL_Rect temp2)
{
    if(PointIntersection(temp2, temp1.x, temp1.y) || PointIntersection(temp2, temp1.x + temp1.w, temp1.y) || PointIntersection(temp2, temp1.x, temp1.y + temp1.h) || PointIntersection(temp2, temp1.x + temp1.w, temp1.y + temp1.h))
    {
        return true;
    }
    return false;
}

void ResetBall()
{
    Ball.x = ball_x;
    Ball.y = ball_y;

    velX = GenerateRandomNum(2, -2);
    velY = GenerateRandomNum(2, -2);
}
