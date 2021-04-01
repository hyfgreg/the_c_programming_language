#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y)
{
    struct point tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

struct point addpoint(struct point pt1, struct point pt2)
{
    pt1.x += pt2.x;
    pt1.y += pt2.y;
    return pt1;
}

int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

struct rect canonrect(struct rect r)
{
    struct rect tmp;
    tmp.pt1.x = min(r.pt1.x, r.pt2.x);
    tmp.pt1.y = min(r.pt1.y, r.pt2.y);
    tmp.pt2.x = max(r.pt1.x, r.pt2.x);
    tmp.pt2.y = max(r.pt1.y, r.pt2.y);
    return tmp;
}

main()
{
    struct point origin, *pp;
    origin = makepoint(1, 2);
    pp = &origin;
    printf("origin is (%d, %d)\n", pp->x, pp->y);
}