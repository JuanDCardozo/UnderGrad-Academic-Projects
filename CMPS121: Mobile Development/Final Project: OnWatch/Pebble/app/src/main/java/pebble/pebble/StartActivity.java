package pebble.pebble;

import android.content.Context;
import android.location.Location;
import android.media.MediaPlayer;
import android.media.MediaRecorder;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.view.View;
import android.telephony.SmsManager;
import android.app.AlertDialog;
import android.widget.TextView;
import android.util.Log;

import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.location.LocationListener;
import com.google.android.gms.location.LocationServices;

import com.getpebble.android.kit.PebbleKit;
import com.getpebble.android.kit.util.PebbleDictionary;

import java.io.IOException;
import java.util.UUID;

public class StartActivity extends AppCompatActivity implements GoogleApiClient.ConnectionCallbacks,
        GoogleApiClient.OnConnectionFailedListener, LocationListener{

    // Private Global Variables
    private int mode = 1;
    private int previousMode = 0;
    private PebbleKit.PebbleDataReceiver mReceiver;
    public String[] phoneNumbers;
    public static double latitude, longitude;

    //Audio recording variables
    private MediaRecorder recorder = null;
    private boolean recording = false;
    private static String mFileName = null;
    private MediaPlayer mPlayer = null;

    private static final int
            KEY_BUTTON_EVENT = 0,
            BUTTON_EVENT_UP = 1,
            BUTTON_EVENT_DOWN = 3,
            BUTTON_EVENT_SELECT = 2;

    private Location mLastLocation;
    private GoogleApiClient mGoogleApiClient;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_start);
        Bundle extras = getIntent().getExtras();

        if (mGoogleApiClient == null) {
            mGoogleApiClient = new GoogleApiClient.Builder(this)
                    .addConnectionCallbacks(this)
                    .addOnConnectionFailedListener(this)
                    .addApi(LocationServices.API).build();
        }


        phoneNumbers = extras.getStringArray("PHONES");


    }

    @Override
    protected void onResume() {
        super.onResume();


        // Receie data from the pebble
        mReceiver = new PebbleKit.PebbleDataReceiver(UUID.fromString("4728fd50-df72-432d-8ff3-ecb4f158ec05")) {

            @Override
            public void receiveData(Context context, int transactionId, PebbleDictionary data) {
                //ACK the message
                PebbleKit.sendAckToPebble(context, transactionId);

                //Check the key exists
                if (data.getUnsignedIntegerAsLong(KEY_BUTTON_EVENT) != null) {
                    int button = data.getUnsignedIntegerAsLong(KEY_BUTTON_EVENT).intValue();

                    switch (button) {
                        case BUTTON_EVENT_UP:
                            Button eThreat = (Button) findViewById(R.id.escalateThreat);
                            checkThreat(eThreat);
                            //The UP button was pressed
                            break;
                        case BUTTON_EVENT_DOWN:
                            Button dThreat = (Button) findViewById(R.id.difuseThreat);
                            checkThreat(dThreat);
                            //The DOWN button was pressed
                            break;
                        case BUTTON_EVENT_SELECT:
                            //The SELECT button was pressed
                            break;
                    }
                }
            }

        };

        PebbleKit.registerReceivedDataHandler(this, mReceiver);
    }

    protected void onStart() {
        mGoogleApiClient.connect();
        super.onStart();
    }



    @Override
    protected void onPause() {
        super.onPause();

        unregisterReceiver(mReceiver);
    }

    // Send the sms message with the different Threat levels
    public void sendSMS(String[] phoneNumbers, String message) {
        for (int i = 0; i < phoneNumbers.length; i++) {
            if (phoneNumbers[i] != null) {
                try {
                    SmsManager.getDefault().sendTextMessage(phoneNumbers[i], null, message, null, null);
                } catch (Exception e) {
                    AlertDialog.Builder alertDialogBuilder = new
                            AlertDialog.Builder(this);
                    AlertDialog dialog = alertDialogBuilder.create();

                    dialog.setMessage(e.getMessage());
                    dialog.show();

                }
            }
        }

    }

    public void checkThreat(View v) {
        //Variables Needed
        String[] alertedContacts = phoneNumbers;
        Button escalateThreat = (Button) findViewById(R.id.escalateThreat);
        Button vv = (Button) v;
        RelativeLayout relativeLayoutB = (RelativeLayout) findViewById(R.id.relativeLayout);
        final TextView displayMode = (TextView) findViewById(R.id.modeDisplay);
        TextView descriptionMode = (TextView) findViewById(R.id.modeDescription);

        // CHeck the type of button press and whether to escalate threat or not.
        if (escalateThreat == vv) {
            previousMode = mode;
            ++mode;
            if (mode > 4) {
                mode = 4;
            }
        } else {
            previousMode = mode;
            --mode;
            if (mode < 1) {
                mode = 1;
            }
        }

        switch (mode) {
            case 1:// Safe Mode
                //Set layout
                relativeLayoutB.setBackgroundResource(R.color.safeModeCol);
                displayMode.setText(R.string.safeModeTxt);
                descriptionMode.setText(R.string.safeModeDesc);

                // Check if the threat is decreasing
                if(previousMode > mode){ // From Alert to Safe
                    sendSMS(alertedContacts, getResources().getString(R.string.MessageNoThreat1));
                }
                break;
            case 2: // Alert Mode
                //Set layout
                relativeLayoutB.setBackgroundResource(R.color.alertModeCol);
                displayMode.setText(R.string.alertModeTxt);
                descriptionMode.setText(R.string.alertModeDesc);

                // Check if the threat is decreasing
                if(previousMode > mode){ //From Threat to Alert
                    sendSMS(alertedContacts, getResources().getString(R.string.MessageNoThreat2));
                    String location = latalong();
                    sendSMS(alertedContacts, location);
                }else{ //From Safe to Alert
                    String[] twoContacts = {phoneNumbers[0], phoneNumbers[1]};
                    alertedContacts = twoContacts;
                    sendSMS(twoContacts, getResources().getString(R.string.Message1));
                    String location = latalong();
                    sendSMS(twoContacts, location);
                }
                break;

            case 3: // Threat Mode
                //Set layout
                relativeLayoutB.setBackgroundResource(R.color.threatModeCol);
                displayMode.setText(R.string.threatModeTxt);
                descriptionMode.setText(R.string.threatModeDesc);
                alertedContacts = phoneNumbers;

                // Check if recording and stop it
                if(recording){
                    stopRec();
                }

                // Check if the threat is decreasing
                if(previousMode > mode){ // From Panic to Threat
                    sendSMS(alertedContacts, getResources().getString(R.string.MessageNoThreat3));
                    String location2 = latalong();
                    sendSMS(alertedContacts, location2);
                }else{ //From Alert to Threat

                    sendSMS(phoneNumbers, getResources().getString(R.string.Message2));
                    sendSMS(phoneNumbers, getResources().getString(R.string.Message2_1));
                    String location1 = latalong();
                    sendSMS(phoneNumbers, location1);
                }
                break;
            case 4: //Panic Mode. It will. Text 911, right now it is only sending text to contacts
                //Set layout
                relativeLayoutB.setBackgroundResource(R.color.panicModeCol);
                displayMode.setText(R.string.panicModeTxt);
                descriptionMode.setText(R.string.panicModeDesc);

                // Send Messagge+ location
                sendSMS(phoneNumbers, getResources().getString(R.string.Message3));
                sendSMS(phoneNumbers, getResources().getString(R.string.Message3_1));
                String location2 = latalong();
                sendSMS(phoneNumbers, location2);
                alertedContacts = phoneNumbers;

                // If not recording then start recording
                if (!recording){
                    startRec();
                }
                break;

        }


    }


    public String latalong() {
        mLastLocation = LocationServices.FusedLocationApi.getLastLocation(mGoogleApiClient);
        if (mLastLocation!=null) {
            longitude = mLastLocation.getLongitude();
            latitude = mLastLocation.getLatitude();
        }
        String lat = Double.toString(latitude);
        String log = Double.toString(longitude);

        String coord = String.format("Their last known location: https://maps.google.com/maps?q=%s,%s", lat, log);

        return coord;
    }

//AUDIO RECORDING FUNCTIONS


    private void startRec(){
        recorder = new MediaRecorder();
        recorder.setAudioSource(MediaRecorder.AudioSource.MIC);
        recorder.setOutputFormat(MediaRecorder.OutputFormat.THREE_GPP);
        recorder.setOutputFile(mFileName);
        recorder.setAudioEncoder(MediaRecorder.AudioEncoder.AMR_NB);
        try {
            recorder.prepare();
        }catch (IOException e){
            Log.e("record error", "prepare() failed");
        }
        recorder.start();
        recording = true;
    }

    private void stopRec(){
        recorder.stop();
        recorder.release();
        recorder = null;
        recording = false;

    }

    public void startPlaying(){
        mPlayer = new MediaPlayer();
        try{
            mPlayer.setDataSource(mFileName);
            mPlayer.prepare();
            mPlayer.start();
        }catch (IOException e){
            Log.e("play error", "prepare() failed");
        }
    }

    private void stopPlaying(){
        mPlayer.release();
        mPlayer = null;
    }

    protected void onStop() {
        mGoogleApiClient.disconnect();
        super.onStop();
    }

    public StartActivity(){
        mFileName = Environment.getExternalStorageDirectory().getAbsolutePath();
        mFileName += "/test.3gp";
    }


    @Override
    public void onConnected(Bundle bundle) {

    }

    @Override
    public void onConnectionSuspended(int i) {

    }

    @Override
    public void onLocationChanged(Location location) {

    }

    @Override
    public void onConnectionFailed(ConnectionResult connectionResult) {

    }
}




