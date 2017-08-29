package hw4.homework4;

import android.graphics.Bitmap;
import android.graphics.Canvas;

public class Driver extends Car{
    private Bitmap image;
    private int score;
    private double dya;
    private boolean up;
    private boolean driving;
    private long startTime;

    public Driver(Bitmap res, int w, int h) {

        x = Panel.WIDTH;
        y = Panel.HEIGHT;
        dy = 0;
        score = 0;
        height = h;
        width = w;

        image = res;

        startTime = System.nanoTime();

    }

    public void setUp(boolean b){up = b;}

    public void update()
    {
        long elapsed = (System.nanoTime()-startTime)/1000000;
        if(elapsed>100)
        {
            score++;
            startTime = System.nanoTime();
        }

        if(up){
            dy = (int)(dya-=1.1);

        }
        else{
            dy = (int)(dya+=1.1);
        }
        if(dy>14)dy = 14;
        if(dy<-14)dy = 14;
        x+= dy*2;
        dy = 0;

    }

    public void draw(Canvas canvas)
    {
        canvas.drawBitmap(image,x,y,null);
    }
    public int getScore(){return score;}
    public boolean getDriving(){return driving;}
    public void setDriving(boolean b){driving = b;}
    public void resetDYA(){dya = 0;}
    public void resetScore(){score = 0;}
}