#ifndef SIMPLISTIC_SRC_CORE_H_
#define SIMPLISTIC_SRC_CORE_H_

#include "Precision.h"

namespace simplistic {

class Vector3 {
 public:
  Vector3() : x_position_(0), y_position_(0), z_position_(0) {}
  Vector3(const real x, const real y, const real z) 
      : x_position_(x), y_position_(y), z_position_(z) {} 
 
 
  /** Return the magnitude of the vector. */
  real Magnitude() const;
 
  /** Return the square of the magnitude. */
  real SquareMagnitude() const;
 
  /** Return a new normalized vector of unit length */
  Vector3 Normalize();

  inline real GetX() const { return x_position_; }
  inline real GetY() const { return y_position_; }
  inline real GetZ() const { return z_position_; }

  /** Compute the dot product between this and another vector. */
  inline real DotProduct(const Vector3& vector) {
    return (
        x_position_ * vector.GetX() +
        y_position_ * vector.GetY() + 
        z_position_ * vector.GetZ());
  }

  /** 
   * Compute the component product of this vector with another and return a 
   * new vector. 
   */
  inline Vector3 ComponentProductNew(const Vector3& vector) const {
    return Vector3(
        x_position_ * vector.GetX(),
        y_position_ * vector.GetY(),
        z_position_ * vector.GetZ());
  }

  /** 
   * Compute the component product of this vector with another and apply it to
   * this vector. 
   */
  inline void ComponentProduct(const Vector3& vector) {
    x_position_ *= vector.GetX();
    y_position_ *= vector.GetY();
    z_position_ *= vector.GetZ();
  }

  /** Take the vector product and return a new one. */
  inline Vector3 VectorProductNew(const Vector3& vector) const {
    return Vector3(
        y_position_ * vector.GetZ() - z_position_ * vector.GetY(),
        z_position_ * vector.GetX() - x_position_ * vector.GetZ(),
        x_position_ * vector.GetY() - y_position_ * vector.GetX());
  }

  /** 
   * Update this vector be the result of the vector product of itself with
   * another vector.
   */
  inline void VectorProduct(const Vector3& vector) {
    x_position_ = y_position_ * vector.GetZ() - z_position_ * vector.GetY();
    y_position_ = z_position_ * vector.GetX() - x_position_ * vector.GetZ();
    z_position_ = x_position_ * vector.GetY() - y_position_ * vector.GetX();
  }

  /** Invert the vector */
  inline void Invert() {
    x_position_ = -x_position_;
    y_position_ = -y_position_;
    z_position_ = -z_position_;
  }

  /**
   * Add a vector scaled by a scalar to the current vector.
   */
  inline void AddScaledVector(const Vector3& vector, real scale) {
    x_position_ += vector.GetX() * scale;
    y_position_ += vector.GetY() * scale;
    z_position_ += vector.GetZ() * scale;
  }

   
  /** Add another vector to the current one in place. */
  inline void operator+=(const Vector3& vector) {
     x_position_ += vector.GetX();
     y_position_ += vector.GetY();
     z_position_ += vector.GetZ();
  }
  
  /** Add another vector to a copy of the of the current vector. */
  inline Vector3 operator+(const Vector3& vector) {
    return Vector3(
        x_position_ + vector.GetX(),
        y_position_ + vector.GetY(),
        z_position_ + vector.GetZ());
  }
   
   /** Add a scalar to a copy of the of the current vector. */
   inline Vector3 operator+(const real value) {
     return Vector3(
         x_position_ + value,
         y_position_ + value,
         z_position_ + value);
   }
 
   inline void operator-=(const Vector3& vector) {
     x_position_ -= vector.GetX();
     y_position_ -= vector.GetY();
     z_position_ -= vector.GetZ();
   }

  inline Vector3 operator-(const Vector3& vector) const {
    return Vector3(
        x_position_ - vector.GetX(),
        y_position_ - vector.GetY(),
        z_position_ - vector.GetZ());
  }

  /** Multiply the vector by a scalar in place. */
  inline void operator*=(const real value) {
    x_position_ *= value;
    y_position_ *= value;
    z_position_ *= value;
  }

  /** Multiply the current vector by a scalar and return a new vector. */
  inline Vector3 operator*(const real value) const {
    return Vector3(
        x_position_ * value, y_position_ * value, z_position_ * value);
  }

  /** --------------------- Component Product operations -------------------- */

  inline void operator*=(const Vector3& vector) { ComponentProduct(vector); }
  inline Vector3 operator*(const Vector3& vector) const {
    return ComponentProductNew(vector); }

  /** ---------------------- Vector Product operations ---------------------- */

  inline void operator%=(const Vector3& vector) { VectorProduct(vector); }
  inline Vector3 operator%(const Vector3& vector) const {
    return VectorProductNew(vector); }
 private:
  real x_position_, y_position_, z_position_;
  real pad_;
};

}  // namespace simplistic

#endif  // SIMPLISTIC_SRC_CORE_H_
