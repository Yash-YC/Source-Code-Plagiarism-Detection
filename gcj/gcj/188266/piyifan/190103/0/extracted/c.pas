Program Pyf;
var
   f	 : array[0..100] of extended;
   c	 : array[0..50 , 0..50] of extended;
   n , m : longint;
   run   : longint;

procedure init;
begin
   readln( n , m );
end; { init }

function min( a , b : longint ) : longint;
begin
   if a < b then min := a
   else min := b;
end; { min }

function max( a , b : longint ) : longint;
begin
   if a > b then max := a
   else max := b;
end; { max }
		
procedure Dp;
var
   i , j     : longint;
   x , y , t : extended;
begin
   f[n] := 0;
   for i := n - 1 downto 0 do
   begin
      x := 1; y := 0;
      if m - i <= 0 then
      begin
	 t := c[i , m] / c[n , m];
	 x := x - t;
	 y := t;
      end;
      for j := max( m - i , 1 ) to min( n - i , m ) do
      begin
	 t := c[i , m - j] * c[n - i , j] / c[n , m];
	 y := y + t * ( f[i + j] + 1 );
      end;
      f[i] := y / x;
   end;
   writeln( f[0] : 0 : 7 );
end; { Dp }

procedure prepare;
var
   i , j : longint;
begin
   for i := 0 to 40 do c[i , 0] := 1;
   for i := 1 to 40 do
      for j := 1 to i do
	 c[i , j] := c[i - 1 , j] + c[i - 1 , j - 1];
end; { prepare }

begin
   assign( input , 'c1.in' );   reset( input );
   assign( output , 'c1.out' ); rewrite( output );
   prepare;
   readln( run );
   for run := 1 to run do
   begin
      init;
      write( 'Case #' , run , ': ' );
      Dp;
   end;
   close( output );
end.

