#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "Input.h"
#include <cassert>
#include<math.h>




Matrix4x4 MakeRotateXMatrix(float theta);
Matrix4x4 MakeRotateYMatrix(float theta);

Matrix4x4 MakeRotateZMatrix(float theta);

Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

Vector3 Normalize(const Vector3& v);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, Vector3& translate);

Matrix4x4 Inverse(const Matrix4x4& m);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);
//  ルートの計算に使う->sqrtf()
// ノルム(長さ)
float Length(const Vector3& v);



Vector3 Multiply(float m1, const Vector3& m2);

Vector3 MultiplyT(Vector3 vector, Matrix4x4 matrix);


Vector3 Transform(Vector3 vector, Matrix4x4 matrix);

Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

  // 加算
  Vector3 Add(const Vector3& v1, const Vector3& v2);
// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

Vector3 Add(const Vector3& v1, float v2);


Matrix4x4 MakePerspectiveFoveMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
Matrix4x4 MakeOrthographicMatrix(
    float left, float top, float right, float bottom, float nearClip, float farClip);
Matrix4x4 MakeViewportMatrix(
    float left, float top, float width, float height, float minDepth, float maxDepth);
