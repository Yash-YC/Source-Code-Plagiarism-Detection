Program Pyf;
var
   ans	     : array[0..1000] of longint;
   a , b , i : longint;
   run       : longint;
begin
   assign( input , 'answer.txt' );
   reset( input );
   for i := 1 to 512 do
   begin
      readln( a , b );
      ans[a] := b;
   end;
   readln;
   close( input );
   assign( input , 'a-big.in' );
   assign( output , 'a-big.out' );
   reset( input ); rewrite( output );
   readln( run );
   for run := 1 to run do
   begin
      a := 0;
      while not eoln do
      begin
	 read( b );
	 inc( a , 1 shl ( b - 2 ) );
      end;
      readln;
      writeln( 'Case #' , run , ': ' , ans[a] );
   end;
   close( output );
end.
