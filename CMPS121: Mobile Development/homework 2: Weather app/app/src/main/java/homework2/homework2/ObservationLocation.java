package homework2.homework2;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;


public class ObservationLocation {

    @SerializedName("city")
    @Expose
    public String city;
    @SerializedName("elevation")
    @Expose
    public String elevation;

}