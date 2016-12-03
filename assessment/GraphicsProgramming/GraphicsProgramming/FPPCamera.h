#ifndef _FPPCAMERA_H
#define _FPPCAMERA_H

#include "glut.h"
#include "Input.h"
#include "Camera.h"

class FPPCamera : public Camera {
public:
	FPPCamera();
	~FPPCamera();

	virtual void update();
	virtual void moveForward(float dt);
	virtual void moveBackwards(float dt);
	virtual void moveSideLeft(float dt);
	virtual void moveSideRight(float dt);

	virtual void addYaw(float dt, float value);
	virtual void subtractYaw(float dt, float value);
	virtual void addPitch(float dt, float value);
	virtual void subtractPitch(float dt, float value);
	virtual void addRoll(float dt, float value);
	virtual void subtractRoll(float dt, float value);

	virtual float getPositionX();
	virtual float getPositionY();
	virtual float getPositionZ();

	virtual float getForwardX();
	virtual float getForwardY();
	virtual float getForwardZ();

	virtual float getLookAtX();
	virtual float getLookAtY();
	virtual float getLookAtZ();

	virtual float getUpX();
	virtual float getUpY();
	virtual float getUpZ();

	virtual float getSideX();
	virtual float getSideY();
	virtual float getSideZ();

	virtual float getYaw();
	virtual float getPitch();
	virtual float getRoll();

	virtual void setLookAtX(float x);
	virtual void setLookAtY(float y);
	virtual void setLookAtZ(float z);

	virtual void setYaw(float arg);
	virtual void setPitch(float arg);
	virtual void setRoll(float arg);

	virtual void updateYaw(int width, int mouseX, int speed);
	virtual void updatePitch(int height, int mouseY, int speed);

	virtual void cameraControll(float dt, int width, int height, Input *input);
private:
	Vector3 position;
	Vector3 lookAt;
	Vector3 forward;
	Vector3 up;
	Vector3 side;
	float Yaw, Pitch, Roll;
	int clamp_value;
	float bottomClamp, topClamp;
	bool moveUp, moveDown;
};

#endif

