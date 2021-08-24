Program Pyf;
var
   p	    : array[0..20] of longint;
   hash	    : array[0..100000000] of longint;
   n , time : longint;
   i , j    : longint;
   ok	    : boolean;
   run , a  : longint;

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

begin
assign( input , 'a-small.in' );
assign( output , 'a-small.out' );
reset( input ); rewrite( output );
   readln( run );
   for run := 1 to run do
   begin
      n := 0;
      while not eoln do
      begin
	 inc( n ); read( p[n] );
      end;
      readln;
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
            writeln( 'Case #' , run , ': ' ,  i );
	    break;
	 end;
      end;
   end;
close( output );
end.
