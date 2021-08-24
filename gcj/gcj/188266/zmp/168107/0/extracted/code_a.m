beolv=textread('A-small-attempt0.in.txt');
n=beolv(1,1);
beolv(1,:)=[];
fid = fopen('out4.txt', 'a');
for i=1:n
    s=beolv(i,:);
    jmax=min(9,length(s'));
    for j=1:jmax
        if s(j)>=2
            s2(j)=s(j);
            j2=j;
        end;
    end;
    k=2;
    talal=0;
    while k<100000000000000000000000000 & talal==0
        m=1;
        jo=1;
        while m<=j2 & jo==1
            jo=happytest(k,s2(m));
            m=m+1;
        end;
        if jo==1
            talal=1
        end;
        k=k+1;
    end;
    eredm(i)=k-1;
    clear s2;
    h1=['Case #',num2str(i),': '];
    fprintf(fid, '%s', h1);
    fprintf(fid, '%u\n',k-1);
end;