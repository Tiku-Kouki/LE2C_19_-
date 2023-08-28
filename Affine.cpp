#include "Affine.h"

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {

	Matrix4x4 A = {};
	A.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] +
	            m1.m[0][3] * m2.m[3][0];
	A.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] +
	            m1.m[1][3] * m2.m[3][0];
	A.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] +
	            m1.m[2][3] * m2.m[3][0];
	A.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] +
	            m1.m[3][3] * m2.m[3][0];

	A.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] +
	            m1.m[0][3] * m2.m[3][1];
	A.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] +
	            m1.m[1][3] * m2.m[3][1];
	A.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] +
	            m1.m[2][3] * m2.m[3][1];
	A.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] +
	            m1.m[3][3] * m2.m[3][1];

	A.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] +
	            m1.m[0][3] * m2.m[3][2];
	A.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] +
	            m1.m[1][3] * m2.m[3][2];
	A.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] +
	            m1.m[2][3] * m2.m[3][2];
	A.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] +
	            m1.m[3][3] * m2.m[3][2];

	A.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] +
	            m1.m[0][3] * m2.m[3][3];
	A.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] +
	            m1.m[1][3] * m2.m[3][3];
	A.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] +
	            m1.m[2][3] * m2.m[3][3];
	A.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] +
	            m1.m[3][3] * m2.m[3][3];

	return A;
}

Vector3 Multiply(float m1, const Vector3& m2) {

	Vector3 A = {};
	A.x = m2.x * m1;
	A.y = m2.y * m1;
	A.z = m2.z * m1;

	return A;
}

Matrix4x4 MakeRotateXMatrix(float theta) {
	Matrix4x4 A = {};

	A.m[0][0] = 1.0f;
	A.m[0][1] = 0.0f;
	A.m[0][2] = 0.0f;
	A.m[0][3] = 0.0f;

	A.m[1][0] = 0.0f;
	A.m[1][1] = std::cos(theta);
	A.m[1][2] = std::sin(theta);
	A.m[1][3] = 0.0f;

	A.m[2][0] = 0.0f;
	A.m[2][1] = -std::sin(theta);
	A.m[2][2] = std::cos(theta);
	A.m[2][3] = 0.0f;

	A.m[3][0] = 0.0f;
	A.m[3][1] = 0.0f;
	A.m[3][2] = 0.0f;
	A.m[3][3] = 1.0f;

	return A;
}
Matrix4x4 MakeRotateYMatrix(float theta) {
	Matrix4x4 A = {};

	A.m[0][0] = std::cos(theta);
	A.m[0][1] = 0.0f;
	A.m[0][2] = -std::sin(theta);
	A.m[0][3] = 0.0f;

	A.m[1][0] = 0.0f;
	A.m[1][1] = 1.0f;
	A.m[1][2] = 0.0f;
	A.m[1][3] = 0.0f;

	A.m[2][0] = std::sin(theta);
	A.m[2][1] = 0.0f;
	A.m[2][2] = std::cos(theta);
	A.m[2][3] = 0.0f;

	A.m[3][0] = 0.0f;
	A.m[3][1] = 0.0f;
	A.m[3][2] = 0.0f;
	A.m[3][3] = 1.0f;

	return A;
}
Matrix4x4 MakeRotateZMatrix(float theta) {
	Matrix4x4 A = {};

	A.m[0][0] = std::cos(theta);
	A.m[0][1] = -std::sin(theta);
	A.m[0][2] = 0.0f;
	A.m[0][3] = 0.0f;

	A.m[1][0] = std::sin(theta);
	A.m[1][1] = std::cos(theta);
	A.m[1][2] = 0.0f;
	A.m[1][3] = 0.0f;

	A.m[2][0] = 0.0f;
	A.m[2][1] = 0.0f;
	A.m[2][2] = 1.0f;
	A.m[2][3] = 0.0f;

	A.m[3][0] = 0.0f;
	A.m[3][1] = 0.0f;
	A.m[3][2] = 0.0f;
	A.m[3][3] = 1.0f;

	return A;
}

Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m) {
	Vector3 result{

	    v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0],
	    v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1],
	    v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2]};

	return result;
}
// 内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float A;

	A = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return A;
}
//  ルートの計算に使う->sqrtf()
// ノルム(長さ)
float Length(const Vector3& v) {
	float A;

	A = sqrtf(Dot(v, v));

	return A;
}

Vector3 Normalize(const Vector3& v) {
	float length = Length(v);

	assert(length != 0.0f);

	return {v.x / length, v.y / length, v.z / length};
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, Vector3& translate) {
	Matrix4x4 A = {};

	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rot.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rot.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rot.z);
	Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

	A.m[0][0] = scale.x * rotateXYZMatrix.m[0][0];
	A.m[0][1] = scale.x * rotateXYZMatrix.m[0][1];
	A.m[0][2] = scale.x * rotateXYZMatrix.m[0][2];
	A.m[0][3] = 0.0f;

	A.m[1][0] = scale.y * rotateXYZMatrix.m[1][0];
	A.m[1][1] = scale.y * rotateXYZMatrix.m[1][1];
	A.m[1][2] = scale.y * rotateXYZMatrix.m[1][2];
	A.m[1][3] = 0.0f;

	A.m[2][0] = scale.z * rotateXYZMatrix.m[2][0];
	A.m[2][1] = scale.z * rotateXYZMatrix.m[2][1];
	A.m[2][2] = scale.z * rotateXYZMatrix.m[2][2];
	A.m[2][3] = 0.0f;

	A.m[3][0] = translate.x;
	A.m[3][1] = translate.y;
	A.m[3][2] = translate.z;
	A.m[3][3] = 1.0f;
	return A;
}

Matrix4x4 Inverse(const Matrix4x4& m) {
	Matrix4x4 A = {};
	float determinant;
	determinant = +m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] +
	              m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] +
	              m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]

	              - m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1] -
	              m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3] -
	              m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]

	              - m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3] -
	              m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1] -
	              m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]

	              + m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] +
	              m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] +
	              m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]

	              + m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] +
	              m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1] +
	              m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]

	              - m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1] -
	              m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3] -
	              m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]

	              - m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0] -
	              m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0] -
	              m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]

	              + m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0] +
	              m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] +
	              m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];

	assert(determinant != 0.0f);
	float determinantRecp = 1.0f / determinant;

	A.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] +
	             m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][3] * m.m[2][2] * m.m[3][1] -
	             m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][1] * m.m[2][3] * m.m[3][2]) *
	            determinantRecp;
	A.m[0][1] = (-m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] -
	             m.m[0][3] * m.m[2][1] * m.m[3][2] + m.m[0][3] * m.m[2][2] * m.m[3][1] +
	             m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][2]) *
	            determinantRecp;
	A.m[0][2] = (m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] +
	             m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][3] * m.m[1][2] * m.m[3][1] -
	             m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[3][2]) *
	            determinantRecp;
	A.m[0][3] = (-m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] -
	             m.m[0][3] * m.m[1][1] * m.m[2][2] + m.m[0][3] * m.m[1][2] * m.m[2][1] +
	             m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][2]) *
	            determinantRecp;

	A.m[1][0] = (-m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] -
	             m.m[1][3] * m.m[2][0] * m.m[3][2] + m.m[1][3] * m.m[2][2] * m.m[3][0] +
	             m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][0] * m.m[2][3] * m.m[3][2]) *
	            determinantRecp;
	A.m[1][1] = (m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] +
	             m.m[0][3] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[2][2] * m.m[3][0] -
	             m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][2]) *
	            determinantRecp;
	A.m[1][2] = (-m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] -
	             m.m[0][3] * m.m[1][0] * m.m[3][2] + m.m[0][3] * m.m[1][2] * m.m[3][0] +
	             m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][0] * m.m[1][3] * m.m[3][2]) *
	            determinantRecp;
	A.m[1][3] = (m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] +
	             m.m[0][3] * m.m[1][0] * m.m[2][2] - m.m[0][3] * m.m[1][2] * m.m[2][0] -
	             m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][2]) *
	            determinantRecp;

	A.m[2][0] = (m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] +
	             m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][0] -
	             m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][0] * m.m[2][3] * m.m[3][1]) *
	            determinantRecp;
	A.m[2][1] = -(m.m[0][0] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][0] +
	              m.m[0][3] * m.m[2][0] * m.m[3][1] - m.m[0][3] * m.m[2][1] * m.m[3][0] -
	              m.m[0][1] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][1]) *
	            determinantRecp;
	A.m[2][2] = (m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] +
	             m.m[0][3] * m.m[1][0] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[3][0] -
	             m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[3][1]) *
	            determinantRecp;
	A.m[2][3] = -(m.m[0][0] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][0] +
	              m.m[0][3] * m.m[1][0] * m.m[2][1] - m.m[0][3] * m.m[1][1] * m.m[2][0] -
	              m.m[0][1] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][1]) *
	            determinantRecp;

	A.m[3][0] = -(m.m[1][0] * m.m[2][1] * m.m[3][2] + m.m[1][1] * m.m[2][2] * m.m[3][0] +
	              m.m[1][2] * m.m[2][0] * m.m[3][1] - m.m[1][2] * m.m[2][1] * m.m[3][0] -
	              m.m[1][1] * m.m[2][0] * m.m[3][2] - m.m[1][0] * m.m[2][2] * m.m[3][1]) *
	            determinantRecp;

	A.m[3][1] = (m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] +
	             m.m[0][2] * m.m[2][0] * m.m[3][1] - m.m[0][2] * m.m[2][1] * m.m[3][0] -
	             m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][2] * m.m[3][1]) *
	            determinantRecp;
	A.m[3][2] = -(m.m[0][0] * m.m[1][1] * m.m[3][2] + m.m[0][1] * m.m[1][2] * m.m[3][0] +
	              m.m[0][2] * m.m[1][0] * m.m[3][1] - m.m[0][2] * m.m[1][1] * m.m[3][0] -
	              m.m[0][1] * m.m[1][0] * m.m[3][2] - m.m[0][0] * m.m[1][2] * m.m[3][1]) *
	            determinantRecp;
	A.m[3][3] = (m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] +
	             m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] -
	             m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1]) *
	            determinantRecp;

	return A;
}

Matrix4x4 MakePerspectiveFoveMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {

	Matrix4x4 A = {};

	A.m[0][0] = (1.0f / aspectRatio) * (1 / (tanf(fovY / 2)));
	A.m[0][1] = 0.0f;
	A.m[0][2] = 0.0f;
	A.m[0][3] = 0.0f;

	A.m[1][0] = 0.0f;
	A.m[1][1] = 1 / (tanf(fovY / 2));
	A.m[1][2] = 0.0f;
	A.m[1][3] = 0.0f;

	A.m[2][0] = 0.0f;
	A.m[2][1] = 0.0f;
	A.m[2][2] = farClip / (farClip - nearClip);
	A.m[2][3] = 1.0f;

	A.m[3][0] = 0.0f;
	A.m[3][1] = 0.0f;
	A.m[3][2] = -(nearClip * farClip) / (farClip - nearClip);
	A.m[3][3] = 0.0f;

	return A;
}
Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip, float farClip) {

	Matrix4x4 A = {};

	A.m[0][0] = 2.0f / (right - left);
	A.m[0][1] = 0.0f;
	A.m[0][2] = 0.0f;
	A.m[0][3] = 0.0f;

	A.m[1][0] = 0.0f;
	A.m[1][1] = 2.0f / (top - bottom);
	A.m[1][2] = 0.0f;
	A.m[1][3] = 0.0f;

	A.m[2][0] = 0.0f;
	A.m[2][1] = 0.0f;
	A.m[2][2] = 1.0f / (farClip - nearClip);
	A.m[2][3] = 0.0f;

	A.m[3][0] = (left + right) / (left - right);
	A.m[3][1] = (top + bottom) / (bottom - top);
	A.m[3][2] = nearClip / (nearClip - farClip);
	A.m[3][3] = 1.0f;

	return A;
}
Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth) {

	Matrix4x4 A = {};

	A.m[0][0] = width / 2;
	A.m[0][1] = 0.0f;
	A.m[0][2] = 0.0f;
	A.m[0][3] = 0.0f;

	A.m[1][0] = 0.0f;
	A.m[1][1] = -(height / 2);
	A.m[1][2] = 0.0f;
	A.m[1][3] = 0.0f;

	A.m[2][0] = 0.0f;
	A.m[2][1] = 0.0f;
	A.m[2][2] = maxDepth - minDepth;
	A.m[2][3] = 0.0f;

	A.m[3][0] = left + (width / 2);
	A.m[3][1] = top + (height / 2);
	A.m[3][2] = minDepth;
	A.m[3][3] = 1.0f;
	return A;
}

Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 A = {};
	A.m[0][0] = m.m[0][0];
	A.m[0][1] = m.m[1][0];
	A.m[0][2] = m.m[2][0];
	A.m[0][3] = m.m[3][0];
	A.m[1][0] = m.m[0][1];
	A.m[1][1] = m.m[1][1];
	A.m[1][2] = m.m[2][1];
	A.m[1][3] = m.m[3][1];
	A.m[2][0] = m.m[0][2];
	A.m[2][1] = m.m[1][2];
	A.m[2][2] = m.m[2][2];
	A.m[2][3] = m.m[3][2];
	A.m[3][0] = m.m[0][3];
	A.m[3][1] = m.m[1][3];
	A.m[3][2] = m.m[2][3];
	A.m[3][3] = m.m[3][3];

	return A;
}

Vector3 Transform(Vector3 vector, Matrix4x4 matrix) {
	Vector3 result = {};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] + matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] + matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] + matrix.m[3][2];
	 float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] + matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}

Vector3 MultiplyT(Vector3 vector, Matrix4x4 matrix) {
	Vector3 result = {};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[0][1] + vector.z * matrix.m[0][2] + matrix.m[0][3];
	result.y = vector.x * matrix.m[1][0] + vector.y * matrix.m[1][1] + vector.z * matrix.m[1][2] + matrix.m[1][3];
	result.z = vector.x * matrix.m[2][0] + vector.y * matrix.m[2][1] + vector.z * matrix.m[2][2] + matrix.m[2][3];

	return result;
}

Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {

	Matrix4x4 A = {};
	A.m[0][0] = m1.m[0][0] - m2.m[0][0];
	A.m[0][1] = m1.m[0][1] - m2.m[0][1];
	A.m[0][2] = m1.m[0][2] - m2.m[0][2];
	A.m[0][3] = m1.m[0][3] - m2.m[0][3];
	A.m[1][0] = m1.m[1][0] - m2.m[1][0];
	A.m[1][1] = m1.m[1][1] - m2.m[1][1];
	A.m[1][2] = m1.m[1][2] - m2.m[1][2];
	A.m[1][3] = m1.m[1][3] - m2.m[1][3];
	A.m[2][0] = m1.m[2][0] - m2.m[2][0];
	A.m[2][1] = m1.m[2][1] - m2.m[2][1];
	A.m[2][2] = m1.m[2][2] - m2.m[2][2];
	A.m[2][3] = m1.m[2][3] - m2.m[2][3];
	A.m[3][0] = m1.m[3][0] - m2.m[3][0];
	A.m[3][1] = m1.m[3][1] - m2.m[3][1];
	A.m[3][2] = m1.m[3][2] - m2.m[3][2];
	A.m[3][3] = m1.m[3][3] - m2.m[3][3];

	return A;
}

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 A = {};

	A.x = v1.x + v2.x;
	A.y = v1.y + v2.y;
	A.z = v1.z + v2.z;

	return A;
}



// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 A = {};

	A.x = v1.x - v2.x;
	A.y = v1.y - v2.y;
	A.z = v1.z - v2.z;

	return A;
}

Vector3 Add(const Vector3& v1, float v2) {
	Vector3 A = {};

	A.x = v1.x + v2;
	A.y = v1.y + v2;
	A.z = v1.z + v2;

	return A;
}
