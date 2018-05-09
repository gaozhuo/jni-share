#include <jni.h>

// 局部引用
static jclass localRef = NULL;
// 全局引用
//static jclass globalRef = NULL;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_demo0501_MainActivity_test(JNIEnv *env, jobject instance) {

    if(localRef == NULL){
        jclass cls = env->GetObjectClass(instance);
        localRef = cls;

    }

//    if(globalRef == NULL){
//        jclass cls = env->GetObjectClass(instance);
//        // 创建全局引用
//        globalRef = (jclass)env->NewGlobalRef(cls);
//    }


    jfieldID fieldID = env->GetFieldID(localRef, "number", "I");

    env->SetIntField(instance, fieldID, 100);

}