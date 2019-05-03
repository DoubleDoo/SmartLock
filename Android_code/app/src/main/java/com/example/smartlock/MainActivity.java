package com.example.smartlock;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
       // setContentView(R.layout.activity_main);
    }

    @Override
    protected void onStart ()
    {
        super.onStart();
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(MainActivity.this);
        if(myPreferences.getBoolean("NEW", true))
        {
            Intent intent = new Intent(MainActivity.this, StartRegActivity.class);
            startActivity(intent);
        }
        else
        {
            Intent intent = new Intent(MainActivity.this, MenuActivity.class);
            startActivity(intent);
        }
    }



}

