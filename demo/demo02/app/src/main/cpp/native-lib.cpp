#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_4);

    jclass cls = env->FindClass("com/example/demo02/MainActivity");

    JNINativeMethod methods[] = {
            {"stringFromJNI", "()Ljava/lang/String;", (void *) stringFromJNI}
    };

    env->RegisterNatives(cls, methods, 1);
    return JNI_VERSION_1_4;
}
