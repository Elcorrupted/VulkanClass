#ifndef CAMERA_H
#define CAMERA_H

#include "MMath.h"

using namespace MATH;

class Camera {
public:
	Camera();
	~Camera();

	void UpdatePerspective(const float fovy, const float aspectRatio, const float near, const float far);
	void UpdateView(const Vec3& eye, const Vec3& at, const Vec3& up);

	inline Matrix4 GetProjection() const { return proj; }
	inline Matrix4 GetView() const { return view; }

private:
	Matrix4 proj, view, rot, transl;
};
#endif // !CAMERA_H

