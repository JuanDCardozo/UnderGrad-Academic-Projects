package homework3.homework3;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.preference.PreferenceManager;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public final static String nickname = "com.mycompany.myfirstapp.nicknameSearch";

    //public final static String nickname = "homework3.homework3.nickname";

    private String user_id;
    Location lastLocation;
    private double lastAccuracy = (double) 1e10;
    private long lastAccuracyTime = 0;
    private static final String LOG_TAG = "localChat";
    private LocationData locationData = LocationData.getLocationData();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Gets the settings, and creates a random user id if missing.
        SharedPreferences settings = PreferenceManager.getDefaultSharedPreferences(this);
        user_id = settings.getString("user_id", null);
        if (user_id == null) {
            // Creates a random one, and sets it.
            SecureRandomString srs = new SecureRandomString();
            user_id = srs.nextString();
            SharedPreferences.Editor e = settings.edit();
            e.putString("user_id", user_id);
            e.commit();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            return;
        }
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            return;
        }
        locationManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 0, 0, locationListener);
        locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);
    }

    @Override
    protected void onPause() {
        LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {

            return;
        }
        locationManager.removeUpdates(locationListener);
        super.onPause();
    }


    LocationListener locationListener = new LocationListener() {
        @Override
        public void onLocationChanged(Location location) {
            double newAccuracy = location.getAccuracy();
            Log.i(LOG_TAG, "Accuracy is " + newAccuracy);
            long newTime = location.getTime();
            // Is this better than what we had?  We allow a bit of degradation in time.
            boolean isBetter = ((lastLocation == null) ||
                    newAccuracy < lastAccuracy + (newTime - lastAccuracyTime));
            if (isBetter) {
                // We replace the old estimate by this one.
                lastLocation = location;
                lastAccuracy = location.getAccuracy();
                lastAccuracyTime = location.getTime();
                // We display the accuracy.
                locationEnabled(location);
            }
        }

        @Override
        public void onStatusChanged(String provider, int status, Bundle extras) {

        }

        @Override
        public void onProviderEnabled(String provider) {

        }

        @Override
        public void onProviderDisabled(String provider) {

        }
    };


        private void locationEnabled(Location location) {
            String acc = "Chat Button Disabled:\nAcquiring Location";
            TextView locationText = (TextView) findViewById(R.id.location);
            Button chatButton = (Button) findViewById(R.id.button);
            if ((location == null) || (location.getAccuracy() > 50)) {
                chatButton.setEnabled(false);
                locationText.setText(acc);
            } else {
                acc = String.format("Chat Button Enabled:\nLocation Accuracy %5.1f m", location.getAccuracy());
                chatButton.setEnabled(true);
                locationText.setText(acc);
            }
        }


        // Get the Nickname for the chat and move to the next activity
        public void goToChat(View v) {
            Intent intent = new Intent(this, ChatActivity.class);
            EditText nickName = (EditText) findViewById(R.id.nickname);
            // Store name in preferences
            SharedPreferences settings = PreferenceManager.getDefaultSharedPreferences(this);
            SharedPreferences.Editor e = settings.edit();
            e.putString("nickName", nickName.getText().toString());
            e.commit();

            //Pass the Chat name to the next activity

            intent.putExtra(nickname, nickName.getText().toString());
            startActivity(intent);
        }
    }
