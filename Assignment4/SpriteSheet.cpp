#include "SpriteSheet.h"
#include "Matrix.h"

SheetSprite::SheetSprite() {}

SheetSprite::SheetSprite(float spriteIndex, int spriteCountX, int spriteCountY) {
	u = (float)(((int)spriteIndex) % spriteCountX) / (float)spriteCountX;
	v = (float)(((int)spriteIndex) / spriteCountY) / (float)spriteCountY;
	width = 1.0 / (float)spriteCountX;
	height = 1.0 / (float)spriteCountY;
}

void SheetSprite::draw(ShaderProgram& program, Matrix&modelMatrix, GLuint textureId, float objWidth, float objHeight, float x, float y, float scale) {
	//Blend
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	modelMatrix.Translate(x, y, 0);
	glTranslated(x, y, 0);
	
	GLfloat vertices[] = 
	{    
		objWidth * scale, objHeight * scale,// 1, 1,
		-objWidth * scale, objHeight * scale,// -1, 1,
		-objWidth * scale, -objHeight * scale,//-1, -1,
		objWidth * scale, objHeight * scale,// 1, 1,
		-objWidth * scale, -objHeight * scale,//-1, -1,
		objWidth * scale, -objHeight * scale,//1, -1
	};

	glVertexAttribPointer(program.positionAttribute, 2, GL_FLOAT, false, 0, vertices);
	glEnableVertexAttribArray(program.positionAttribute);

	GLfloat coords[] = {  
		u, v,//00
		u + width, v,//10
		u, v + height,//11
		u, v,//00
		u + width, v + height,//11
		u, v + height//01
	};
	glVertexAttribPointer(program.texCoordAttribute, 2, GL_FLOAT, false, 0, coords);
	glEnableVertexAttribArray(program.texCoordAttribute);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(program.positionAttribute);
	glDisableVertexAttribArray(program.texCoordAttribute);
	glDisable(GL_TEXTURE_2D);

}