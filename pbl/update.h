#ifndef UPDATE_H
#define UPDATE_H

extern float camera_x;
extern float camera_y;
extern int last_frame_time;
extern int lastValidDirection;
extern int currentLevel;

float calculateDistance(int x1, int y1, int x2, int y2);
void update();
void updateEnemies(float delta_time);
#endif // UPDATE_H
