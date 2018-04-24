#include <jni.h>
#include <android/log.h>


/**
 * 设置Java成员变量
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demo03_MainActivity_setJavaField(JNIEnv *env, jobject instance) {
    // 1.根据对象获取类信息
    jclass cls = env->GetObjectClass(instance);

    // 2.获取成员变量ID（参数：类、成员变量名、签名）
    jfieldID fieldID = env->GetFieldID(cls, "number", "I");

    // 3.设置成员变量
    env->SetIntField(instance, fieldID, 200);
}

/**
 * 调用Java方法
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demo03_MainActivity_callJavaMethod(JNIEnv *env, jobject instance) {
    // 1.根据对象获取类信息
    jclass cls = env->GetObjectClass(instance);

    //2.获取方法ID（参数：类、方法名、方法签名）
    jmethodID mid = env->GetMethodID(cls, "add", "(II)I");

    //3.调用方法
    jint sum = env->CallIntMethod(instance, mid, 3, 5);

    // 打印结果
    __android_log_print(ANDROID_LOG_DEBUG, "debug", "sum=%d", sum);

}

/**
 * 创建Java对象
 */
extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_demo03_MainActivity_createJavaObject(JNIEnv *env, jobject instance) {
    // 1.根据对象获取类信息
    jclass cls = env->FindClass("com/example/demo03/Student");
    //2.获取构造方法ID（参数：类、方法名、方法签名）
    jmethodID init = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;I)V");
    //3.创建Java对象
    jobject obj = env->NewObject(cls, init, env->NewStringUTF("张三"), 25);

    return obj;

}