function info = readFile(filename)

f = fopen(filename, 'r');

info = {};

while(~feof(f))
    line = fgetl(f);
    info = [info; line];
end

fclose(f);
