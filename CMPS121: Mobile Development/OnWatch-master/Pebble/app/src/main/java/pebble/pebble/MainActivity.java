package pebble.pebble;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.Button;
import android.content.SharedPreferences;
import android.view.View.OnClickListener;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    EditText contactText, numberText, eDelete;
    TextView c1,c2,c3,n1,n2,n3, added, deleted, del;
    Button addButton, deleteButton, saved, ok;
    RelativeLayout rLayout;
    String[] contact = new String[3]; //Contacts Stored
    String[] numbers = new String[3];     //Numbers Stored
    private SharedPreferences preferenceSettings;
    private SharedPreferences.Editor preferenceEditor;
    private static final int PREFERENCE_MODE_PRIVATE = 0;

    String d;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        //Code from before
        //SharedPreferences sp = getSharedPreferences(myPREFERENCES, Activity.MODE_PRIVATE);
        preferenceSettings = getPreferences(PREFERENCE_MODE_PRIVATE);
        preferenceEditor = preferenceSettings.edit();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String name,number;

        /*New layout */
        contactText = (EditText) findViewById(R.id.textView2); //Edit contact text box
        numberText = (EditText) findViewById(R.id.textView3);  //Edit number text box
        rLayout = (RelativeLayout) findViewById(R.id.rLayout); //Relative Layout
        addButton = (Button) findViewById(R.id.button2);     //Add button
        deleteButton = (Button) findViewById(R.id.button3); //Delete Button
        added = (TextView) findViewById(R.id.textView4);
        saved = (Button) findViewById(R.id.button);
        deleted =(TextView) findViewById(R.id.textView5);
        eDelete = (EditText) findViewById(R.id.textView6);
        ok = (Button) findViewById(R.id.button4);
        del = (TextView) findViewById(R.id.textView10);


        c1 = (TextView) findViewById(R.id.c1);
        c2 = (TextView) findViewById(R.id.c2);
        c3 = (TextView) findViewById(R.id.c3);
        n1 = (TextView) findViewById(R.id.n1);
        n2 = (TextView) findViewById(R.id.n2);
        n3 = (TextView) findViewById(R.id.n3);


        String rn1 = preferenceSettings.getString(contact[0], contact[0]);
        String rn2 = preferenceSettings.getString(contact[1], contact[1]);
        String rn3 = preferenceSettings.getString(contact[2], contact[2]);
        String nn1 = preferenceSettings.getString(numbers[0], numbers[0]);
        String nn2 = preferenceSettings.getString(numbers[1], numbers[1]);
        String nn3 = preferenceSettings.getString(numbers[2], numbers[2]);


        if (rn1 != null) {
            name = "Contact #1:" + rn1;
            number = "Number #1:" + nn1;
            c1.setText(name);
            n1.setText(number);
            c1.setVisibility(View.VISIBLE);
            n1.setVisibility(View.VISIBLE);
        }
        if (rn2 != null) {
            name = "Contact #2:" + rn2;
            number = "Number #2:" + nn2;
            c2.setText(name);
            n2.setText(number);
            c2.setVisibility(View.VISIBLE);
            n2.setVisibility(View.VISIBLE);
        }
        if (rn3 != null) {
            name = "Contact #3:" + rn3;
            number = "Number #3:" + nn3;
            c3.setText(name);
            n3.setText(number);
            c3.setVisibility(View.VISIBLE);
            n3.setVisibility(View.VISIBLE);
        }
        //--------------------------------------------------------------------------
        //Added the hints for user to input
        contactText.setHint("Name");
        numberText.setHint("Phone Number");


        OnClickListener delete = new OnClickListener() {
            @Override
            public void onClick(View v) {
                deleted.setVisibility(View.VISIBLE);
                eDelete.setVisibility(View.VISIBLE);
                ok.setVisibility(View.VISIBLE);

                eDelete.setHint("Insert number of contact (1-3)");
            }
        };

        OnClickListener okay = new OnClickListener() {
            @Override
            public void onClick(View v) {
                deleted.setVisibility(View.INVISIBLE);
                eDelete.setVisibility(View.INVISIBLE);
                ok.setVisibility(View.INVISIBLE);
                d = eDelete.getText().toString();
                int de = Integer.parseInt(d);
                de = de - 1;
                contact[de] = null;
                numbers[de] = null;
                if (de == 0) {
                    c1.setVisibility(View.INVISIBLE);
                    n1.setVisibility(View.INVISIBLE);
                } else if (de == 1) {
                    c2.setVisibility(View.INVISIBLE);
                    n2.setVisibility(View.INVISIBLE);
                } else if (de == 2) {
                    c3.setVisibility(View.INVISIBLE);
                    n3.setVisibility(View.INVISIBLE);
                }

                del.setVisibility(View.VISIBLE);
                del.postDelayed(new Runnable() {
                    public void run() {
                        del.setVisibility(View.INVISIBLE);
                    }
                }, 1000);
            }
        };



        OnClickListener onClick = new OnClickListener() {
            @Override
            public void onClick(View v) {
                String c = contactText.getText().toString();
                String n = numberText.getText().toString();
                String name,number;
                //Add contacts to array
                for (int i = 0; i < 3; i++) {
                    if (contact[i] == null) {
                        contact[i] = c;
                        numbers[i] = n;
                        if (i == 0) {
                            name = "Contact #1: " + contact[i];
                            number = "Number #1: " + numbers[i];
                            c1.setText(name);
                            n1.setText(number);
                        } else if (i == 1) {
                            name = "Contact #2: " + contact[i];
                            number = "Number #2: " + numbers[i];
                            c2.setText(name);
                            n2.setText(number);
                        } else if (i == 2) {
                            name = "Contact #3: " + contact[i];
                            number = "Number #3: " + numbers[i];
                            c3.setText(name);
                            n3.setText(number);
                        }
                        preferenceEditor.putString(contact[i],contact[i]);
                        preferenceEditor.putString(numbers[i], numbers[i]);
                        preferenceEditor.apply();//commit();
                        break;
                    }
                }
                //Timer that accounces that the name and number has been added
                added.setVisibility(View.VISIBLE);

                added.postDelayed(new Runnable() {
                    public void run() {
                        added.setVisibility(View.INVISIBLE);
                    }
                }, 1000);

                //Prints out the added contacts
                for (int i = 0; i < 3; i++) {
                    if (contact[i] == null) {
                        break;
                    } else {
                        if (i == 0) {
                            c1.setVisibility(View.VISIBLE);
                            n1.setVisibility(View.VISIBLE);
                        } else if (i == 1) {
                            c2.setVisibility(View.VISIBLE);
                            n2.setVisibility(View.VISIBLE);
                        } else if (i == 2) {
                            c3.setVisibility(View.VISIBLE);
                            n3.setVisibility(View.VISIBLE);
                        }
                    }
                }
            }
        };

        OnClickListener savedC = new OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(), StartActivity.class);
                i.putExtra("PHONES", numbers);
                startActivity(i);
            }
        };

        addButton.setOnClickListener(onClick);
        deleteButton.setOnClickListener(delete);
        saved.setOnClickListener(savedC);
        ok.setOnClickListener(okay);

    }
}
