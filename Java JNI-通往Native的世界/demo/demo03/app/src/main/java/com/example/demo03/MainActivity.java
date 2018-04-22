package com.example.demo03;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private int number = 100;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    static {
        System.loadLibrary("native-lib");
    }

    public void onBtnClick01(View view) {

        setJavaField();

        Log.d("debug", "number=" + number);
    }

    public void onBtnClick02(View view) {

        callJavaMethod();
    }

    public void onBtnClick03(View view) {

        Student student = createJavaObject();

        Log.d("debug", student.toString());
    }

    public int add(int a, int b) {
        Log.d("debug", "我在Native层被调用");
        return a + b;
    }


    public native void setJavaField();

    public native void callJavaMethod();

    public native Student createJavaObject();
}
