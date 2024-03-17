#include <stdio.h>

struct Point {
    float x;
    float y;
};

void modifyPoint(struct Point *ptr, float newX, float newY) {
    ptr->x = newX;
    ptr->y = newY;
}

struct Rectangle {
    struct Point topLeft;
    struct Point bottomRight;
};

float calculateArea(struct Rectangle rect) {
    float width = rect.bottomRight.x - rect.topLeft.x;
    float height = rect.topLeft.y - rect.bottomRight.y;
    return width * height;
}

float calculatePerimeter(struct Rectangle rect) {
    float width = rect.bottomRight.x - rect.topLeft.x;
    float height = rect.topLeft.y - rect.bottomRight.y;
    return 2 * (width + height);
}

int main() {
    struct Point point = {2.5, 3.5};

    modifyPoint(&point, 5.0, 7.0);

    printf("Modified coordinates of the point: (%.2f, %.2f)\n", point.x, point.y);

    struct Rectangle rectangle = {{1.0, 4.0}, {6.0, 1.0}};

    printf("Area of the rectangle: %.2f\n", calculateArea(rectangle));
    printf("Perimeter of the rectangle: %.2f\n", calculatePerimeter(rectangle));

    return 0;
}
