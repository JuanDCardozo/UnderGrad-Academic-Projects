package homework3.homework3;

import android.content.Context;
import android.content.Intent;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import okhttp3.OkHttpClient;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.GsonConverterFactory;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.http.GET;
import retrofit2.http.POST;
import retrofit2.http.Query;

public class ChatActivity extends AppCompatActivity {
    private String user_id, nickname, message, messageid;
    private Float lat, lng;

    private LocationData locationData = LocationData.getLocationData();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_chat);
    }

    private MyAdapter aa;

    private ArrayList<ListElement> aList;

    @Override
    protected void onResume() {
        Intent intent = getIntent();
        String chatName = intent.getStringExtra(MainActivity.nickname);


        aList = new ArrayList<ListElement>();
        aa = new MyAdapter(this, R.layout.list_element, aList);
        ListView myListView = (ListView) findViewById(R.id.chatList);
        myListView.setAdapter(aa);
        aa.notifyDataSetChanged();

        //get_message(chatName);

        super.onResume();
    }

    //Get local messages
    private void get_message(String message) {

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://luca-teaching.appspot.com/localmessages/")    //We are using Foursquare API to get data
                .addConverterFactory(GsonConverterFactory.create())    //parse Gson string
                .build();

        messageGET service = retrofit.create(messageGET.class);

        user_id = message;
        nickname = message;
        lat = (float) 0.0;//(float) locationData.getLocation().getLatitude();
        lng = (float)0.0;//(float) locationData.getLocation().getLongitude();


        Call<LocalMessages> queryResponseCall = service.listChat(user_id, lat, lng);

        //Call retrofit asynchronously
        queryResponseCall.enqueue(new Callback<LocalMessages>() {
            @Override
            public void onResponse(Response<LocalMessages> response) {
                //Grabs messages from server and stores it in an array
                List<ResultList> resultList = getResultList(response.body());
                //Clears list that we're going to put stuff in
                aList.clear();
                for (int i = 0; i < resultList.size(); i++) {
                    aList.add(new ListElement(resultList.get(i).getMessage(), null));
                }

                if (resultList.size() == 0)
                    ((TextView) findViewById(R.id.noResult)).setVisibility(View.VISIBLE);//show not found
                aa.notifyDataSetChanged();
            }

            @Override
            public void onFailure(Throwable t) {

            }


            //parse the response for list of restaurants

            private List<ResultList> getResultList(LocalMessages response) {
                List<ResultList> resultList;
                resultList = response.getResultList();
                return resultList;
            }

        });
    }

    // Post a message to the chat
    public void post_message(View view) {

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://luca-teaching.appspot.com/localmessages/")    //We are using Foursquare API to get data
                .addConverterFactory(GsonConverterFactory.create())    //parse Gson string
                .build();

        messagePOST service = retrofit.create(messagePOST.class);

        EditText editText = (EditText) findViewById(R.id.message);
        Intent intent = getIntent();
        String nickname = intent.getStringExtra(MainActivity.nickname);//get search word

        user_id = "458";
        lat =(float) 0.0;//(float) locationData.getLocation().getLatitude();
        lng = (float) 0.0;//(float) locationData.getLocation().getLongitude();
        messageid = "1550";
        message = editText.getText().toString();

        ResultList ResultList = new ResultList(user_id, lat, lng, nickname, message, messageid);
        Call<LocalMessages> queryResponseCall = service.listChat(user_id, lat, lng, nickname, message, messageid);

        //Call retrofit asynchronously
        queryResponseCall.enqueue(new Callback<LocalMessages>() {

            @Override
            public void onResponse(Response<LocalMessages> response) {

            }

            @Override
            public void onFailure(Throwable t) {
                // Log error here since request failed
            }

            //parse the response for list of restaurants

        });
        get_message(nickname);
    }

    public void clickRefresh(View view) {
        Intent intent = getIntent();
        String nickname = intent.getStringExtra(MainActivity.nickname);//get search word
        get_message(nickname);
    }


    /**
     * Foursquare api https://developer.foursquare.com/docs/venues/search
     */
    public interface messageGET {
        @GET("default/get_messages")
        Call<LocalMessages> listChat(
                @Query("user_id") String user_id,
                @Query("lat") Float lat,
                @Query("lng") Float lng
        );
    }

    public interface messagePOST {
        @POST("default/post_message")
        Call<LocalMessages> listChat(
                @Query("user_id") String user_id,
                @Query("lat") Float lat,
                @Query("lng") Float lng,
                @Query("nickname") String nickname,
                @Query("message") String message,
                @Query("message_id") String messageid
        );
    }
}

