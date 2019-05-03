package com.example.smartlock;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class SettingsActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(SettingsActivity.this);
        TextView nm = (TextView)findViewById(R.id.editText13);
        TextView sn = (TextView)findViewById(R.id.editText14);
        TextView ad = (TextView)findViewById(R.id.editText11);
        TextView nu = (TextView)findViewById(R.id.editText12);
        TextView dn = (TextView)findViewById(R.id.textView7);
        nm.setText(myPreferences.getString("NAME", ""));
        sn.setText(myPreferences.getString("SYENAME", ""));
        ad.setText(myPreferences.getString("ADDRESS", ""));
        nu.setText(myPreferences.getString("NUMBER", ""));
        dn.setText(myPreferences.getString("DNUMBER", ""));
    }

    public void savechanges(android.view.View view) {
        TextView nm = (TextView)findViewById(R.id.editText13);
        TextView sn = (TextView)findViewById(R.id.editText14);
        TextView ad = (TextView)findViewById(R.id.editText11);
        TextView nu = (TextView)findViewById(R.id.editText12);
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(SettingsActivity.this);
        SharedPreferences.Editor myEditor = myPreferences.edit();
        myEditor.putString("NAME",nm.getText().toString());
        myEditor.putString("SYENAME",sn.getText().toString() );
        myEditor.putString("ADDRESS",ad.getText().toString() );
        myEditor.putString("NUMBER",nu.getText().toString() );
        myEditor.commit();
        Toast.makeText(getApplicationContext(), "Changes saved!", Toast.LENGTH_SHORT).show();
    }


    public void reset(android.view.View view) {
        SharedPreferences myPreferences = PreferenceManager.getDefaultSharedPreferences(SettingsActivity.this);
        SharedPreferences.Editor myEditor = myPreferences.edit();
        myEditor.putString("NAME","");
        myEditor.putString("SYENAME","" );
        myEditor.putString("ADDRESS","" );
        myEditor.putString("NUMBER","" );
        myEditor.putString("DNUMBER","");
        myEditor.putString("CODE","");
        myEditor.putBoolean("NEW",true);
        myEditor.commit();
        Toast.makeText(getApplicationContext(), "Reset complete!", Toast.LENGTH_SHORT).show();
        Intent intent = new Intent(SettingsActivity.this, MainActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        startActivity(intent);
        finish();
    }


}
