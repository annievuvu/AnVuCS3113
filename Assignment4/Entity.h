#ifndef ENTITY_H
#define ENTITY_H
#ifdef _WINDOWS
#include <GL/glew.h>
#endif
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

#include "Matrix.h"
#include "SpriteSheet.h"

class Entity{
public:

	Entity();

	void update(float elapsed);
	void render(ShaderProgram&program, Matrix&viewMatrix);
	bool collides(Entity* e);
	void fixedUpdate();
	void drawSprite();
	void drawFromSprite(int spriteX, int spriteY);
	float lerp(float v0, float v1, float t);

	SheetSprite sprite;
	float spriteIndex;
	GLuint textureId;
	/*int spriteCountX;
	int spriteCountY;*/
	float x;
	float y;

	float width;
	float height;
	float velocity_x;
	float velocity_y;
	float acceleration_x;
	float acceleration_y;
	float friction_x;
	float friction_y;
	float mass;
	bool isStatic;

	bool enableCollisions;

	bool collidedTop;
	bool collidedBottom;
	bool collidedLeft;
	bool collidedRight;

};

#endif