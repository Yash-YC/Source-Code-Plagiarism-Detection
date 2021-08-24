import std.stdio, std.string, std.conv, std.functional, std.algorithm, std.exception, std.array, std.container;

void main()
{
	File inp = stdin;
	char[] buf;
	inp.readln(buf);
	int tCases = buf.chomp().to!int;
	foreach(t; 1..tCases+1) {
		processTestCase(t, buf, inp);
	}
}

void processTestCase(int t, char[] buf, File f) {
	char[] line = buf[0..f.readln(buf)].chomp();

	DList!dchar output;
	char maximum = 0;
	foreach(i, c; line) {
		// char m = cast(char)reduce!max(line[i..$]);
		if(c >= maximum) {
			maximum = c;
			output.insertFront(c);
		} else {
			output.insertBack(c);
		}
	}


	writeln("Case #", t, ": ", output[]);
}