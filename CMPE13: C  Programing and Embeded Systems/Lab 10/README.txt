******************************************************************************
* Name: Juan D. Cardozo
* Student I.D: 1362585
* Lab 10
* CMPE 13L
*****************************************************************************
****************************Collaborated with********************************

* Andrea David and Victoria Ly

****************************Summary of the Lab********************************

* In this lab we had to implement an rpg game by opening files and reading
the description of the room and storing the information in a struct. 
Then using that information we had to show the information on the OLED , show
the available exits on the room and scroll down the description of the room
using the potentiometer. In addition, we had to implement timers to known
when a button or adc event happened to update de room and the output.

***************************Approach to the Lab********************************

*  I first read the lab manual and then I played around with the files to get
an idea of how to use the functions to read files. After that I implemnted
the player library, then the game library and finaly the rpg functionality. 
The only thing I had trouble with was with creating the output for the OLED and
then updating it with the potentiometer. I know we had to use sprintf(), but I
had trouble on how to show parts of de description at a time when using the 
ponentiometer, as the whole description would not fit the OLED.

***************************Results of the Lab ********************************

*  I was able to transition between all the rooms and show a part of the 
description when scrolling with the potentiometer. In addition, I was able
to show the exits on the LED's. Also, I know that game.c and player.c all work
properly, the only thing that does not work properly is the rpg functionality.
I think the lab manual should have a snippet of code to show hot to use the
fread,fseek and fgetc functions.

***************************Just for fun***************************************
  This class was fun. Thank you. Have a good spring break.
                              ,d8b,
                         _,,aadd8888888bbaa,,_
                    _,ad88P"""8,  I8I  ,8"""Y88ba,_
                 ,ad88P" `Ya  `8, `8' ,8'  aP' "Y88ba,
               ,d8"' "Yb   "b, `b  8  d' ,d"   dP" `"8b,
              dP"Yb,  `Yb,  `8, 8  8  8 ,8'  ,dP'  ,dP"Yb 
           ,ad8b, `Yb,  "Ya  `b Y, 8 ,P d'  aP"  ,dP' ,d8ba,
          dP" `Y8b, `Yb, `Yb, Y,`8 8 8',P ,dP' ,dP' ,d8P' "Yb
         ,88888888Yb, `Yb,`Yb,`8 8 8 8 8',dP',dP' ,dY88888888,
         dP     `Yb`Yb, Yb,`8b 8 8 8 8 8 d8',dP ,dP'dP'     Yb
        ,8888888888b "8, Yba888888888888888adP ,8" d8888888888,
        dP        `Yb,`Y8P""'             `""Y8P',dP'        Yb
       ,88888888888P"Y8P'_.---.._     _..---._`Y8P"Y88888888888,
       dP         d'  8 '  ____  `. .'  ____  ` 8  `b         Yb
      ,888888888888   8   <(@@)>  | |  <(@@)>   8   888888888888,
      dP          8   8    `"""         """'    8   8          Yb
     ,8888888888888,  8          ,   ,          8  ,8888888888888,
     dP           `b  8,        (.-_-.)        ,8  d'           Yb
    ,88888888888888Yaa8b      ,'       `,      d8aaP88888888888888,
    dP               ""8b     _,gd888bg,_     d8""               Yb
   ,888888888888888888888b,    ""Y888P""    ,d888888888888888888888,
   dP                   "8"b,             ,d"8"                   Yb
  ,888888888888888888888888,"Ya,_,ggg,_,aP",888888888888888888888888,
  dP                      "8,  "8"\x/"8"  ,8"                      Yb
 ,88888888888888888888888888b   8\\x//8   d88888888888888888888888888,
 8888bgg,_                  8   8\\x//8   8                  _,ggd8888
  `"Yb, ""8888888888888888888   Y\\x//P   8888888888888888888"" ,dP"'
    _d8bg,_"8,              8   `b\x/d'   8              ,8"_,gd8b_
  ,iP"   "Yb,8888888888888888    8\x/8    8888888888888888,dP"  `"Yi,
 ,P"    __,888              8    8\x/8    8              888,__    "Y,
,8baaad8P"":Y8888888888888888 aaa8\x/8aaa 8888888888888888P:""Y8baaad8,
dP"':::::::::8              8 8::8\x/8::8 8              8:::::::::`"Yb
8::::::::::::8888888888888888 8::88888::8 8888888888888888::::::::::::8
8::::::::::::8,             8 8:::::::::8 8             ,8::::::::::::8
8::::::::::::8888888888888888 8:::::::::8 8888888888888888::::::::::::8
8::::::::::::Ya             8 8:::::::::8 8             aP::::::::::::8
8:::::::::::::888888888888888 8:::::::::8 888888888888888:::::::::::::8
8:::::::::::::Ya            8 8:::::::::8 8            aP:::::::::::::8
Ya:::::::::::::88888888888888 8:::::::::8 88888888888888:::::::::::::aP
`8;:::::::::::::Ya,         8 8:::::::::8 8         ,aP:::::::::::::;8'
 Ya:::::::::::::::"Y888888888 8:::::::::8 888888888P":::::::::::::::aP
 `8;::::::::::::::::::::""""Y8888888888888P""""::::::::::::::::::::;8'
  Ya:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::aP
   "b;::::::::::::::::::::::::::::::::::::::::::: Normand  ::::::;d"
    `Ya;::::::::::::::::::::::::::::::::::::::::: Veilleux ::::;aP'
      `Ya;:::::::::::::::::::::::::::::::::::::::::::::::::::;aP'
         "Ya;:::::::::::::::::::::::::::::::::::::::::::::;aP"
            "Yba;;;:::::::::::::::::::::::::::::::::;;;adP"
                `"""""""Y888888888888888888888P"""""
*****************************************************************************