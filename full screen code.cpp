#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdio.h>

// Function to draw the sky
void drawSky() {
    setfillstyle(SOLID_FILL, COLOR(135, 206, 250)); // Light blue color for the sky
    bar(0, 0, getmaxx(), getmaxy() /3.3);           // Sky fills the upper half of the screen
}

// Function to draw a single cloud
void drawCloud(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    // Cloud formation: overlapping circles
    fillellipse(x, y, 40, 25);     // Center
    fillellipse(x - 35, y, 30, 20); // Left
    fillellipse(x + 35, y, 30, 20); // Right
    fillellipse(x - 20, y - 20, 30, 20); // Top-left
    fillellipse(x + 20, y - 20, 30, 20); // Top-right
}

// Function to draw multiple clouds
void drawClouds(int offset) {
    drawCloud(150 + offset, 100);  // First cloud
    drawCloud(400 + offset, 120);  // Second cloud
    drawCloud(650 + offset, 90);   // Third cloud
}

// Function to draw a multi-story building
void drawBuilding(int x, int y) {
    // Building Main Body
    setcolor(DARKGRAY);
    rectangle(x, y - 200, x + 150, y);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(x + 1, y - 1, DARKGRAY);

    // Roof
    setcolor(RED);
    rectangle(x, y - 220, x + 150, y - 200); // Roof rectangle
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 1, y - 210, RED);

    // Windows (Top Row)
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, YELLOW);
    for (int i = 0; i < 3; i++) {
        rectangle(x + 20 + i * 40, y - 180, x + 50 + i * 40, y - 150); // Top-row windows
        floodfill(x + 25 + i * 40, y - 160, BLACK);
    }

    // Windows (Bottom Row)
    for (int i = 0; i < 3; i++) {
        rectangle(x + 20 + i * 40, y - 120, x + 50 + i * 40, y - 90); // Bottom-row windows
        floodfill(x + 25 + i * 40, y - 100, BLACK);
    }

    // Door
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(x + 60, y - 70, x + 90, y - 10); // Door rectangle
    floodfill(x + 65, y - 20, BROWN);
}

// Function to draw the road
void drawRoad(int roadY) {
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, roadY, getmaxx(), roadY + 90);

    setcolor(WHITE);
    for (int i = 0; i < getmaxx(); i += 90) {
        setlinestyle(SOLID_LINE,1,3);
        line(i, roadY + 45, i + 60, roadY + 45);

    }
      setlinestyle(SOLID_LINE,1,1);
}

// Function to draw a smaller flower
void drawFlower(int x, int y) {
    // Stem
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, COLOR(146, 208, 80)); // Light green stem
    bar(x - 5, y + 15, x + 5, y + 50);             // Stem rectangle

    // Leaves
    setfillstyle(SOLID_FILL, COLOR(146, 208, 80));
    fillellipse(x - 15, y + 40, 15, 5);             // Left leaf
    fillellipse(x + 15, y + 35, 15, 5);             // Right leaf

    // Flower Petals
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y - 15, 12, 12);                 // Top petal
    fillellipse(x - 15, y, 12, 12);                 // Left petal
    fillellipse(x + 15, y, 12, 12);                 // Right petal
    fillellipse(x - 8, y + 12, 12, 12);             // Bottom-left petal
    fillellipse(x + 8, y + 12, 12, 12);             // Bottom-right petal

    // Flower Center
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, 7, 7);                        // Center of flower
}



// Function to draw the grass area
void drawGrass(int grassY) {
    setfillstyle(SOLID_FILL, COLOR(1, 50, 32)); // Green color for grass
    bar(0, grassY + 30, getmaxx(), grassY +400); // Grass area rectangle
}

// Function to draw a tree
void drawTree(int x, int y) {
    // Tree Trunk
    setfillstyle(SOLID_FILL, BROWN);
    bar(x - 15, y, x + 15, y + 90);  // Trunk
    setcolor(GREEN);
    // Tree Leaves (Crown)
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(x, y - 30, 60, 50);   // Main leaves
    fillellipse(x - 40, y - 50, 40, 40); // Left leaves
    fillellipse(x + 40, y - 50, 40, 40); // Right leaves
    fillellipse(x , y -80, 40, 40); // Right leaves

}

// Function to draw "V"-shaped grass between flowers
void drawVGrass(int x, int y) {
    setcolor(GREEN);
    // Function to draw the "V" shape with a vertical line
     setlinestyle(SOLID_LINE,1,3);
    // Left side of the V
    line(x - 20, y, x, y + 30);
    line(x - 10, y-10, x, y + 30);

    // Right side of the V
    line(x + 20, y, x, y + 30);
    line(x + 10, y-10, x, y + 30);

    // Draw the vertical line between the two points
    line(x, y + 30, x, y - 20); // Vertical line from the bottom of the V
    setlinestyle(SOLID_LINE,1,1);

}



// Function to draw a car
void drawCar(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, RED);
    int body[16] = {x + 20, y, x + 140, y, x + 160, y + 30, x + 0, y + 30};
    fillpoly(4, body);

    int roof[8] = {x + 40, y, x + 120, y, x + 100, y - 20, x + 60, y - 20};
    fillpoly(4, roof);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 40, y + 30, 15);
    floodfill(x + 40, y + 30, BLACK);

    circle(x + 120, y + 30, 15);
    floodfill(x + 120, y + 30, BLACK);

    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    circle(x + 40, y + 30, 6);
    floodfill(x + 40, y + 30, LIGHTGRAY);

    circle(x + 120, y + 30, 6);
    floodfill(x + 120, y + 30, LIGHTGRAY);
}



// Function to animate the car
void moveCar(int speed) {
    int xLeft = -160, roadY = 350, carY = roadY + 40, grassY = roadY + 90;
    int cloudOffset = 0;

    int currentPage = 0, nextPage = 1;
    while (true) {
        setactivepage(currentPage);
        cleardevice();

        drawSky();                     // Draw the sky
        drawClouds(cloudOffset);       // Draw moving clouds
        drawRoad(roadY);               // Draw the road
        drawGrass(grassY);             // Draw the grass area
        // Draw flowers in the grass area

        for (int i = 0; i < 6; i=i+2) {
            drawBuilding(100 + i * 240, roadY-25); // Draw buildings
        }
        for (int i = 0; i < 6; i+=2) {
            drawTree(410 + i * 240, roadY - 113); // Draw tree
        }


        drawCar(xLeft, carY);          // Draw the moving car

        // Draw "V"-shaped grass between flowers
        int fpos =  grassY +180;
        for (int i = 1; i < 20; i=i+2) {
            drawVGrass(60 + i * (getmaxx() / 20),fpos );

        }

            // Function to draw a row of flowers

        int flowerSpacing = getmaxx() / 20; // Space between flowers
        for (int i = 0; i < 20; i=i+2) {      // Draw a maximum of 14 flowers
            drawFlower(60+i * flowerSpacing, fpos);
            }


        currentPage = (currentPage + 1) % 2;
        nextPage = (nextPage + 1) % 2;
        setvisualpage(nextPage);

        xLeft += speed;
        cloudOffset += 2; // Move clouds
        if (xLeft > getmaxx()) xLeft = -160;
        if (cloudOffset > getmaxx()) cloudOffset = 0;

        if (kbhit()) {
            char key = getch();
            if (key == 27) break; // Exit on 'Esc' key
            if (key == 'd' || key == 'D' ) speed = (speed < 50) ? speed + 1 : 50; // Increase speed
            if (key == 'a' || key == 'A') speed = (speed > 5) ? speed - 1 : 5;   // Decrease speed
            if (key == 's' || key == 'S') speed = 12;  // Reset speed to default
            if (key == 'w' || key == 'W'  ) speed = 0;  // Pause Car
        }

        delay(25);
    }
}

// Main function
int main() {
    int gd = DETECT, gm;
    initwindow(1920, 1080, "Car Animation");

    moveCar(12); // Start car animation

    getch();
    closegraph();

    return 0;
}
