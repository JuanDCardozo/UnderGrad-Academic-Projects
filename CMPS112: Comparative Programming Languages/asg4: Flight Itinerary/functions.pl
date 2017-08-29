#!/afs/cats.ucsc.edu/courses/cmps112-wm/usr/gprolog/bin/gprolog --consult-file


% Prolog version of not. (Works).
not(X) :- X, !, fail.
not(_).

% Get the arrival time from of a flight(Works).
get_Arrive_time(X, X, _, ArrivalTime):-
  ArrivalTime is 0.

% Get the arrival time from of a flight (Works).
get_Arrive_time(flight(Airport1, Airport2, time(DepartureHour,DepartureMin)), ArrivalTime) :-
    flight_time(Airport1, Airport2, FlightTime),
    hoursmins_to_hours(time(DepartureHour,DepartureMin), DepartureTime),
    ArrivalTime is DepartureTime + FlightTime.

% This returns the flight time. (Works).
flight_time(Airport1,Airport2, FlightTime) :-

   airport( Airport1,_, degmin( DegLat1, MinLat1),degmin( DegLon1, MinLon1)),
   airport( Airport2,_,degmin( DegLat2, MinLat2),degmin( DegLon2, MinLon2)),
   haversine_radians(degmin( DegLat1, MinLat1),degmin( DegLon1, MinLon1),
       degmin( DegLat2, MinLat2),degmin( DegLon2, MinLon2), Distance),
   FlightTime is Distance/ 500.

% Transforms minutes to hours.(Works).
mins_to_hours(Mins, Hours):-
     Hours is (Mins / 60).

% Transforms hours to minutes.(Works).
hours_to_mins(Hours,Mins) :-
     Mins is Hours * 60.

% Transforms time(hours,mins) to hours.(Works).
hoursmins_to_hours( time( Hours, Mins) , Hoursonly ) :-
     mins_to_hours(Mins,TempHours),
     Hoursonly is (Hours + TempHours).

 % Transforms hours to time(hours,mins).(Works).
 hours_to_hoursmins(Hoursonly, Hours, Mins) :-
      TempMinutes is round(Hoursonly*60),
      Mins is mod(TempMinutes,60),
      Hours is round((TempMinutes - Mins)/60).

% Transforms (degres, min) to degress. (Works).
degmin_to_deg( degmin( Degrees, Minutes ), Degreesonly ) :-
     Degreesonly is Degrees + Minutes / 60.

% Transforms degrees into radians. (Works).
degrees_to_radians(Degrees, Radians) :-
  Radians is ((Degrees)/180) * pi.


% Gets distance between two airports in miles using Haversine function.(Works).
haversine_radians(degmin( DegLat1, MinLat1),degmin( DegLon1, MinLon1),
    degmin( DegLat2, MinLat2),degmin( DegLon2, MinLon2) , Distance ) :-

    degmin_to_deg( degmin( DegLat1, MinLat1 ), DLat1 ),
    degmin_to_deg( degmin( DegLon1, MinLon1), DLon1 ),
    degmin_to_deg( degmin( DegLat2, MinLat2 ), DLat2 ),
    degmin_to_deg( degmin( DegLon2, MinLon2 ), DLon2 ),
    degrees_to_radians(DLat1,Lat1),
    degrees_to_radians(DLon1,Lon1),
    degrees_to_radians(DLat2,Lat2),
    degrees_to_radians(DLon2,Lon2),

     Dlon is (Lon2 - Lon1),
     Dlat is (Lat2 - Lat1),
     A is sin( Dlat / 2 ) ** 2
        + cos( Lat1 ) * cos( Lat2 ) * sin( Dlon / 2 ) ** 2,
     Dist is 2 * atan2( sqrt( A ), sqrt( 1 - A )),
     Distance is Dist * 3961.

   % Checks if the transfer time is 30 minutes or less. Returns true or false
   check_transfer_possible(Hours1, Time2) :-
      hoursmins_to_hours(Time2, Hours2),
      hours_to_mins(Hours2, Mins2),
      hours_to_mins(Hours1, Mins1),
      Mins1 + 29 < Mins2.

   % Checks if the arrival time is before midnight. Returns true or false.
   check_arrival_less_than_day(ArrivalTime) :-
      ArrivalTime < 24.


% Finds a travel itinerary path.
findpath(From, To) :-
        Path = [],
        findpath_time(From, To, time(0,0),Path).

findpath_time(X, X, _,_):-
        print('done.'),
        nl.

findpath_time(From, To, time(HourA, MinA), Path) :-

        airport( From, From_name, _, _ ),
        flight(From, X, time(HourB, MinB)),
        Next = flight(From, X, time(HourB, MinB)),
        not( member( Next, Path )),
        Path2 = append([Next], Path),
        % print(Path2),nl,
        airport( X, X_name, _, _ ),



        A is HourA + MinA/60,
        B is HourB + MinB/60,
        A < B,
        check_arrival_less_than_day(A),
        get_Arrive_time(flight(From,X,time(HourB,MinB)), ArrivalTime),
        hours_to_hoursmins(ArrivalTime, ArrivalHours, ArrivalMins),
        format('depart ~w ~w ~0f:~0f ~n',[From,From_name,HourB,MinB]),
        format('arrive ~w ~w ~0f:~0f ~n',[X,X_name,ArrivalHours,ArrivalMins]),

        findpath_time(X, To, time(ArrivalHours, ArrivalMins), Path2).


fly( Depart, Depart ) :-
 write('Error: Departure and arrival airports are the same.'),
  !, fail.

  fly( Depart, _ ) :-
   \+ airport(Depart, _, _, _),
   write('Error: Departure airport was invalid.'),
    !, fail.

  fly( _, Arrive ) :-
   \+ airport(Arrive, _, _, _),
   write('Error: Arrive airport was invalid.'),
   !, fail.

fly( Depart, Arrive ) :-
  findpath(Depart, Arrive),
  !, fail.


fly( Depart, Arrive ) :-
  \+findpath(Depart, Arrive),
  write('Error: Did not find a valid itinerary.'),
   !, fail.
