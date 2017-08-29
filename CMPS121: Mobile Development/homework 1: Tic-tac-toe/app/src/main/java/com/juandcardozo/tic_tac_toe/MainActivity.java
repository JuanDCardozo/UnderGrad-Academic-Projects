package com.juandcardozo.tic_tac_toe;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Variables to keep track of playing board and turn
    int counter = 1;
    int[] board = new int[9]; // 0 = empty, 1 = circle, -1 = cross

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }


    //Resets the board after the
    public void buttonPress(View v){
        // Find ImageButtons variables
        ImageButton b0 = (ImageButton) findViewById(R.id.imageButton);
        ImageButton b1 = (ImageButton) findViewById(R.id.imageButton1);
        ImageButton b2 = (ImageButton) findViewById(R.id.imageButton2);
        ImageButton b3 = (ImageButton) findViewById(R.id.imageButton3);
        ImageButton b4 = (ImageButton) findViewById(R.id.imageButton4);
        ImageButton b5 = (ImageButton) findViewById(R.id.imageButton5);
        ImageButton b6 = (ImageButton) findViewById(R.id.imageButton6);
        ImageButton b7 = (ImageButton) findViewById(R.id.imageButton7);
        ImageButton b8 = (ImageButton) findViewById(R.id.imageButton8);

        //Clear board information of X's and O's
        for(int i = 0; i < 9; ++i){
            board[i] = 0;
        }

        // Clear the image buttons of X's and O's images
        b0.setImageResource(0);
        b1.setImageResource(0);
        b2.setImageResource(0);
        b3.setImageResource(0);
        b4.setImageResource(0);
        b5.setImageResource(0);
        b6.setImageResource(0);
        b7.setImageResource(0);
        b8.setImageResource(0);

        // Make textView invisible again
        TextView tv = (TextView) findViewById(R.id.textView);
        tv.setVisibility(View.INVISIBLE);
        counter = 1;
    }

    //Check board for three objects in a row. If there is a win it updates the color
    public void checkWin(int[] board, int clickType) {
        int winCounter = 0;

        // Get ImageButtons and TextView variables
        TextView tv = (TextView) findViewById(R.id.textView);
        ImageButton b0 = (ImageButton) findViewById(R.id.imageButton);
        ImageButton b1 = (ImageButton) findViewById(R.id.imageButton1);
        ImageButton b2 = (ImageButton) findViewById(R.id.imageButton2);
        ImageButton b3 = (ImageButton) findViewById(R.id.imageButton3);
        ImageButton b4 = (ImageButton) findViewById(R.id.imageButton4);
        ImageButton b5 = (ImageButton) findViewById(R.id.imageButton5);
        ImageButton b6 = (ImageButton) findViewById(R.id.imageButton6);
        ImageButton b7 = (ImageButton) findViewById(R.id.imageButton7);
        ImageButton b8 = (ImageButton) findViewById(R.id.imageButton8);

        // Check all possible winning casses and set the winning message and color
        if (((board[0] == clickType) && (board[1] == clickType) && ((board[2] == clickType)))) {
            b0.setImageResource(R.color.colorWin);
            b1.setImageResource(R.color.colorWin);
            b2.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        } else if ((board[3] == clickType) && (board[4] == clickType) && ((board[5] == clickType))) {
            b3.setImageResource(R.color.colorWin);
            b4.setImageResource(R.color.colorWin);
            b5.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        } else if ((board[6] == clickType) && (board[7] == clickType) && ((board[8] == clickType))) {
            b6.setImageResource(R.color.colorWin);
            b7.setImageResource(R.color.colorWin);
            b8.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);

        } else if ((board[0] == clickType) && (board[3] == clickType) && ((board[6] == clickType))) {
            b0.setImageResource(R.color.colorWin);
            b3.setImageResource(R.color.colorWin);
            b6.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        } else if ((board[1] == clickType) && (board[4] == clickType) && ((board[7] == clickType))) {
            b1.setImageResource(R.color.colorWin);
            b4.setImageResource(R.color.colorWin);
            b7.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        } else if ((board[2] == clickType) && (board[5] == clickType) && ((board[8] == clickType))) {
            b2.setImageResource(R.color.colorWin);
            b5.setImageResource(R.color.colorWin);
            b8.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        } else if ((board[0] == clickType) && (board[4] == clickType) && ((board[8] == clickType))) {
            b0.setImageResource(R.color.colorWin);
            b4.setImageResource(R.color.colorWin);
            b8.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        } else if ((board[2] == clickType) && (board[4] == clickType) && ((board[6] == clickType))){
            b2.setImageResource(R.color.colorWin);
            b4.setImageResource(R.color.colorWin);
            b6.setImageResource(R.color.colorWin);
            if(clickType == 1) {
                tv.setText(R.string.circleWin);
            }else{
                tv.setText(R.string.crossWin);
            }
            tv.setVisibility(View.VISIBLE);
        }else{
            // Check to see if its a tie
            for(int i = 0; i < 8; ++i){
                if(board[i] != 0){
                    winCounter += 1;
                }
            }
            if(winCounter == 8){
                tv.setText(R.string.tie);
                tv.setVisibility(View.VISIBLE);
            }
        }

    }

    // Keep Track of the Board and set images
    public void clickBoard(View v){
        int t = Integer.parseInt((String) v.getTag());
        ImageButton vv = (ImageButton) v;

        // Check if square is empty and then set image according to turn (counter).
        if(board[t] == 0) {
            if (counter == 1) {
                vv.setImageResource(R.drawable.circle);
                board[t] = 1;
                checkWin(board,1);
            } else {
                vv.setImageResource(R.drawable.cross);
                board[t] = -1;
                checkWin(board,-1);
            }
            counter *= -1;
        }
    }


}
