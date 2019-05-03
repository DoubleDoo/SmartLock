package com.example.smartlock;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;


public class SMSService extends Service {
    public SMSService() {
    }


    public void onCreate() {
        super.onCreate();
    }

    public int onStartCommand(Intent intent, int flags, int startId) {

        someTask();
        return super.onStartCommand(intent, flags, startId);
    }

    public void onDestroy() {
        super.onDestroy();

    }

    public IBinder onBind(Intent intent) {
        return null;
    }

    void someTask() {
    }
}
