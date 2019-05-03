package com.example.smartlock;

import android.app.Notification;
import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Vibrator;
import android.preference.PreferenceManager;
import android.support.v4.app.NotificationCompat;
import android.support.v4.app.NotificationManagerCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.telephony.SmsMessage;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import java.nio.channels.Channel;

public class MenuActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
        IntentFilter sms=new IntentFilter("android.provider.Telephony.SMS_RECEIVED");
        sms.setPriority(9999999);
        registerReceiver(SMSReceiverr,sms);
    }

    public void sendSMS(String phoneNo, String msg) {
        try {
            SmsManager smsManager = SmsManager.getDefault();
            smsManager.sendTextMessage(phoneNo, null, msg, null, null);
            Toast.makeText(getApplicationContext(), "Message Sent",
                    Toast.LENGTH_LONG).show();
        } catch (Exception ex) {
            Toast.makeText(getApplicationContext(), ex.getMessage().toString(),
                    Toast.LENGTH_LONG).show();
            ex.printStackTrace();
        }
    }


    public void switchlock(android.view.View view) {
        startService(new Intent(this,SMSService.class));
        Toast.makeText(getApplicationContext(), "just a toast", Toast.LENGTH_LONG).show();
        long mills = 1000L;
        Vibrator vibrator = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
        if (vibrator.hasVibrator()) {
            vibrator.vibrate(mills);
        }
    }


    public void opensettings(android.view.View view) {
        Intent intent = new Intent(MenuActivity.this, SettingsActivity.class);
        startActivity(intent);
    }

    public void sendmessage(android.view.View view) {
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(MenuActivity.this);
        TextView txt = (TextView)findViewById(R.id.txt);
        sendSMS(myPreferences.getString("DNUMBER", ""), txt.getText().toString());
    }

    BroadcastReceiver SMSReceiverr = new BroadcastReceiver() {


        @Override
        public void onReceive(Context context, Intent intent) {
            SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(MenuActivity.this);
            if (intent.getAction() == "android.provider.Telephony.SMS_RECEIVED") {
                Toast.makeText(getApplicationContext(), "tost by sms",Toast.LENGTH_LONG).show();
                TextView txt = (TextView)findViewById(R.id.textView5);
                Object[] pduArray = (Object[]) intent.getExtras().get("pdus");
                SmsMessage[] messages = new SmsMessage[pduArray.length];
                for (int i = 0; i < pduArray.length; i++) {
                    messages[i] = SmsMessage.createFromPdu((byte[]) pduArray[i]);
                }
                String sms_from = (messages[0].getDisplayOriginatingAddress());
                String sms_fromD=myPreferences.getString("DNUMBER", "");
                sms_fromD="+7"+sms_fromD.substring(1, sms_fromD.length());
                if (sms_from.equalsIgnoreCase(sms_fromD)) {
                    StringBuilder bodyText = new StringBuilder();
                    for (int i = 0; i < messages.length; i++) {
                        bodyText.append(messages[i].getMessageBody());
                    }
                    String body = bodyText.toString();

                    txt.setText(body);
                }
                }

        }
    };
}



