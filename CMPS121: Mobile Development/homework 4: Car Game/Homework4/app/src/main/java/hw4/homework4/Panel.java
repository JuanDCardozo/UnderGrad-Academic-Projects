package hw4.homework4;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.support.annotation.MainThread;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class Panel extends SurfaceView implements SurfaceHolder.Callback
{
    public static final int WIDTH = 400;
    public static final int HEIGHT = 380;
    private GameThread thread;
    private RoadBackground bg;
    public  Driver driver;
    private long lastTime;

    public Panel(Context context)
    {
        super(context);


        //add the callback to the surfaceholder to intercept events
        getHolder().addCallback(this);

        thread = new GameThread(getHolder(), this);

        //make panel focusable so it can handle events
        setFocusable(true);
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height){
        bg.setVector(5);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder){
        boolean retry = true;
        while(retry)
        {
            try{thread.setRunning(false);
                thread.join();

            }catch(InterruptedException e){e.printStackTrace();}
            retry = false;
        }

    }

    @Override
    public void surfaceCreated(SurfaceHolder holder){

        bg = new RoadBackground(BitmapFactory.decodeResource(getResources(), R.drawable.road));
        bg.setVector(5);

        driver = new Driver(BitmapFactory.decodeResource(getResources(),R.drawable.car),200,418);
        //we can safely start the game loop
        thread.setRunning(true);
        thread.start();

    }


    @Override
    public boolean onTouchEvent(MotionEvent event)
    {
        if(event.getAction()==MotionEvent.ACTION_DOWN){
            if(!driver.getDriving())
            {
                driver.setDriving(true);
            }
            else
            {
                driver.setUp(true);
            }
            return true;
        }
        if(event.getAction()==MotionEvent.ACTION_UP)
        {
            driver.setUp(false);
            return true;
        }

        return super.onTouchEvent(event);
    }


    public void update()
    {
        if(driver.getDriving()) {
            bg.update();
            driver.update();
        }

    }
    @Override
    public void draw(Canvas canvas)
    {
        super.draw(canvas);
        final float scalerX = (float) getWidth()/WIDTH;
        final float scalerY = (float) getHeight()/HEIGHT;
        if(canvas!=null) {
            final int savedState = canvas.save();
            canvas.scale(scalerX, scalerY);
            bg.draw(canvas);
            canvas.restoreToCount(savedState);
            driver.draw(canvas);
        }
    }

}