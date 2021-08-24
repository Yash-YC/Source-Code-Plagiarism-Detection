Program Pyf;
var
   p	       : array[0..20] of longint;
   hash        : array[0..100000000] of longint;
   n , time    : longint;
   run , a     : longint;

function check( x , p : longint ) : boolean;
var
   t : longint;
begin
   inc( time );
   repeat
      if x = 1 then exit( true );
      if hash[x] = time then exit( false );
      hash[x] := time;
      t := 0;
      while x > 0 do
      begin
	 inc( t , sqr( x mod p ) );
	 x := x div p;
      end;
      x := t;
   until false;
end; { check }

procedure calc( wh : longint );
var
   i , j : longint;
   ok	 : boolean;
begin
write( wh , ' ' );
   for i := 2 to maxlongint do
   begin
      ok := true;
      for j := 1 to n do
	 if not check( i , p[j] ) then
	 begin
	    ok := false;
	    break;
	 end;
      if ok then
      begin
         writeln( i );
	 break;
      end;
   end;
end; { calc }

procedure dfs( x , y : longint );
begin
   if ( x > 10 ) then
   begin
      calc( y );
      exit;
   end;
   dfs( x + 1 , y );
   inc( n ); p[n] := x;
   dfs( x + 1 , y + ( 1 shl ( x - 2 ) ) );
   dec( n );
end; { dfs }

begin
   assign( output , 'answer.txt' );
   rewrite( output );
   dfs( 2 , 0 );
   close( output );
   {
   readln( run );
   for run := 1 to run do
   begin
      n := 0;
      while not eoln do
      begin
	 read( a );
	 inc( n , ( 1 shl ( a - 2 ) ) );
      end;
      readln;
      writeln( 'Case #' , run , ': ' , ans[n] );
   end;
   }
end.
