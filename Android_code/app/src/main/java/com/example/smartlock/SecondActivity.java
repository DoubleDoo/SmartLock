package com.example.smartlock;


import android.content.ContentValues;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.DatabaseUtils;
import android.database.sqlite.SQLiteDatabase;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.view.Window;
import android.view.WindowManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second_activity);
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(SecondActivity.this);
        //SharedPreferences.Editor myEditor = myPreferences.edit();
            String name ="name";
            String surname ="surname" ;
            String addres = "addres";
            String number = "number";
           // myEditor.putString("NAME", name);
           // myEditor.putString("SYENAME", surname);
           // myEditor.putString("ADDRESS", addres);
           // myEditor.putString("NUMBER", number);
           // myEditor.commit();
            TextView nm = (TextView)findViewById(R.id.wp);
            TextView sn = (TextView)findViewById(R.id.gg);
            TextView ad = (TextView)findViewById(R.id.editText3);
            TextView nu = (TextView)findViewById(R.id.editText4);
            nm.setText(myPreferences.getString("NAME", "unknown"));
            sn.setText(myPreferences.getString("SYENAME", "unknown"));
            ad.setText(myPreferences.getString("ADDRESS", "unknown"));
            nu.setText(myPreferences.getString("NUMBER", "unknown"));

    }



    public void registerr(android.view.View view)
    {
        TextView nm = (TextView)findViewById(R.id.wp);
        TextView sn = (TextView)findViewById(R.id.gg);
        TextView ad = (TextView)findViewById(R.id.editText3);
        TextView nu = (TextView)findViewById(R.id.editText4);
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(SecondActivity.this);
        SharedPreferences.Editor myEditor = myPreferences.edit();
        myEditor.putString("NAME",nm.getText().toString());
        myEditor.putString("SYENAME",sn.getText().toString() );
        myEditor.putString("ADDRESS",ad.getText().toString() );
        myEditor.putString("NUMBER",nu.getText().toString() );
        myEditor.commit();

        myEditor.putBoolean("NEW",false);

        Intent intent = new Intent(SecondActivity.this, MainMenu.class);
        startActivity(intent);
    }
}

