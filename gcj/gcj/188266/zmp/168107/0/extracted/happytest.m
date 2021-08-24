function out_jo=happytest(a,p)
if p==2
    jo=1;
end;
if p==4
    jo=1;
end;
jo=1;
folyt=1;
if p==3
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==2 | a==4 | a==5 | a==8
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
if p==5
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==4 | a==3*5+1 | a==2*5 | a==2*5+3 | a==3*5+3
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
if p==6
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==3*6+2 | a==2*6+1 | a==5 | a==4*6+1 | a==2*6+5
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
if p==7
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==3*7+4 | a==1*7+3 | a==2*7+3 | a==6*7+3 | a==4*7+4 | a== 2*7+2
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
if p==8
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==4 | a==5 | a==3*8+2 | a==2*8+4 | a==6*8+4
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
if p==9
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==5*9+5 | a==5*9+8 | a==4*9+5 | a==7*9+5
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
if p==10
    while jo==1 & folyt==1
        a=dec2base(a,p);
        szaml=0;
        h=length(a);
        for i=1:h
            szaml=szaml+str2num(a(i))^2;
        end;
        a=szaml;
        if a==4 | a==16 | a==37 | a==58
            jo=0;
        end;
        if a==1
            folyt=0;
        end;
    end;
end;
out_jo=jo;