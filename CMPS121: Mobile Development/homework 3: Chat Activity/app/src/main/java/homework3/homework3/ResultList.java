package homework3.homework3;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

public class ResultList {

    @SerializedName("timestamp")
    @Expose
    public String timestamp;
    @SerializedName("message")
    @Expose
    public String message;
    @SerializedName("nickname")
    @Expose
    public String nickname;
    @SerializedName("message_id")
    @Expose
    public String messageId;
    @SerializedName("user_id")
    @Expose
    public String userId;
    @SerializedName("lat")
    @Expose
    public Float lat;
    @SerializedName("lng")
    @Expose
    public Float lng;

    //Constructors
    public ResultList(String userId, Float lat, Float lng, String nickname, String message, String messageId ) {
        this.userId = userId;
        this.lat = lat;
        this.lng = lng;
        this.nickname = nickname;
        this.message = message;
        this.messageId = messageId;
    }

    public String getNickname() { return nickname; }

    public String getMessage() {
        String NameAndMessage;
        NameAndMessage = ("Name: " + nickname + "\n" + "Message: " +message );
        return NameAndMessage;
    }
}