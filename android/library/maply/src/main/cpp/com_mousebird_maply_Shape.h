/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_Shape */

#ifndef _Included_com_mousebird_maply_Shape
#define _Included_com_mousebird_maply_Shape
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_Shape
 * Method:    getSelectID
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_mousebird_maply_Shape_getSelectID
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    setSelectID
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Shape_setSelectID
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    isSelectable
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_Shape_isSelectable
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    setSelectable
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Shape_setSelectable
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    setColor
 * Signature: (FFFF)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Shape_setColor
  (JNIEnv *, jobject, jfloat, jfloat, jfloat, jfloat);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    getColor
 * Signature: ()[F
 */
JNIEXPORT jfloatArray JNICALL Java_com_mousebird_maply_Shape_getColor
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    setClipCoords
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Shape_setClipCoords
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_mousebird_maply_Shape
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_Shape_nativeInit
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
