#pragma once
namespace nk{
void addWallCollisions(float &ball_position_x, float &ball_position_y, int radius, float &velocity_x, float &velocity_y);

void keyboard_movement(float acceleration, float &velocity_x, float &velocity_y);
}
