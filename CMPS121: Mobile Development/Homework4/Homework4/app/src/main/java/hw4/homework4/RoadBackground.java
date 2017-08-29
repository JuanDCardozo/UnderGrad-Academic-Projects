package hw4.homework4;

import android.graphics.Bitmap;
import android.graphics.Canvas;


public class RoadBackground {

    private Bitmap image;
    private int x,y, dy;

    public RoadBackground(Bitmap res)
    {
        image = res;
    }
    public void update()
    {
        y+=dy;
        if(y > Panel.HEIGHT){
            y=0;
        }
    }
    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(image, x, y ,null);
        if(y<0)
        {
            canvas.drawBitmap(image, x, y+Panel.HEIGHT, null);
        }
    }
    public void setVector(int dy)
    {
        this.dy = dy;
    }
}
