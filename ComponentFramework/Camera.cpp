#include "Camera.h"


Camera::Camera() {
	proj.loadIdentity();
	view.loadIdentity();
}

Camera::~Camera() {}

void Camera::UpdatePerspective(const float fovy, const float aspectRatio, const float near, const float far) {
	proj = MMath::perspective(fovy, aspectRatio, near, far);
}

void Camera::UpdateView(const Vec3& eye, const Vec3& at, const Vec3& up) {
	view = MMath::lookAt(eye, at, up);
}