package com.example.smartlock;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class SMSMonitor extends BroadcastReceiver {
    private static final String ACTION = "android.provider.Telephony.SMS_RECEIVED";
    @Override
    public void onReceive(Context context, Intent intent) {

    }
}
