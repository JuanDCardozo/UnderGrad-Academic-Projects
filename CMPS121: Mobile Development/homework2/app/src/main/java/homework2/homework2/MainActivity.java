package homework2.homework2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import okhttp3.OkHttpClient;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.GsonConverterFactory;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.http.GET;


public class MainActivity extends AppCompatActivity {

    // Clear the text of the views and sets an error message depending on the response.code()
    public void setErrorViews(String errorMessage){
        String temp = "";
        TextView errorView = (TextView) findViewById(R.id.weather);
        errorView.setText(errorMessage);
        errorView = (TextView) findViewById(R.id.temperature);
        errorView.setText(temp);

        errorView = (TextView) findViewById(R.id.location);
        errorView.setText(temp);

        errorView = (TextView) findViewById(R.id.wind);
        errorView.setText(temp);

        errorView = (TextView) findViewById(R.id.windGust);
        errorView.setText(temp);

        errorView = (TextView) findViewById(R.id.humidity);
        errorView.setText(temp);

        errorView = (TextView) findViewById(R.id.elevation);
        errorView.setText(temp);

    }

    //Gets the data from the http
    public interface WeatherInfo {
        @GET("/weather/default/get_weather")
        Call<WeatherResponse> getWeatherInfo();
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    // onClick make an HTTP call to get weather data and populate screen
    public void setWeatherData(View v) {
        OkHttpClient httpClient = new OkHttpClient.Builder().build();

        final Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("http://luca-teaching.appspot.com")    //We are using luca's API to get data
                .addConverterFactory(GsonConverterFactory.create())    //parse Gson string
                .client(httpClient)    //add logging
                .build();

        WeatherInfo service = retrofit.create(WeatherInfo.class);

        Call<WeatherResponse> queryResponseCall = service.getWeatherInfo();

        queryResponseCall.enqueue(new Callback<WeatherResponse>() {

            // On response it will check code() and populate the screen acordingly
            @Override
            public void onResponse(Response<WeatherResponse> response) {
                String temp;// = response.body().response.result;

                if(response.code() == 500){                                 // Server Error (500)
                   setErrorViews("Server Error (500):Try again!");
                }else if(response.code() == 200){
                    if(response.body().response.result.equals("error")) {   // Empty Error
                        setErrorViews("Error: Could not load data!");
                    }else{                                                  // Result == ok

                        temp = "Location: " + response.body().response.conditions.
                                observationLocation.city;
                        TextView locationView = (TextView) findViewById(R.id.location);
                        locationView.setText(temp);

                        temp = "Weather: " + response.body().response.conditions.weather;
                        TextView weatherView = (TextView) findViewById(R.id.weather);
                        weatherView.setText(temp);


                        temp = "Elevation: " + response.body().
                                response.conditions.observationLocation.elevation;
                        TextView elevationView = (TextView) findViewById(R.id.elevation);
                        elevationView.setText(temp);

                        temp = "Wind Speed: " + response.body().response.conditions.windMph + " mph";
                        TextView windView = (TextView) findViewById(R.id.wind);
                        windView.setText(temp);

                        temp = "Humidity: " + response.body().response.conditions.relativeHumidity;
                        TextView humidityView = (TextView) findViewById(R.id.humidity);
                        humidityView.setText(temp);

                        temp = response.body().response.conditions.tempC + " C°";
                        TextView temperatureView = (TextView) findViewById(R.id.temperature);
                        temperatureView.setText(temp);

                        temp = "Wind Gust: " + response.body().response.conditions.windGustMph + " mph";
                        TextView windGustView = (TextView) findViewById(R.id.windGust);
                        windGustView.setText(temp);
                    }
                }
            }

            @Override
            public void onFailure(Throwable t) {
                // Log error here since request failed
            }
        });
    }

}


