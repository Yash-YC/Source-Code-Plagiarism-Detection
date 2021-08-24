clear

MyDir='C:\Users\Zita\Documents\A_CodeJam\';
MyFN='A-small-attempt0.in.crdownload';
MyFN2=['res_' MyFN];

fid = fopen([MyDir MyFN]);
fileID2 = fopen([MyDir MyFN2],'w');

t = fscanf(fid, '%d',1);

s0='ABCDEFGHIJKLMNOPQRSTUVWXYZ';

for ii=1:t
    s = fscanf(fid, '%s',1);
    
    n=length(s);
    k=1:26;
    
    for i=1:n
        s1(i)=k(s0==s(i));
    end
    
    s21=[];
    s22=[];
    while n>0
        
        m=max(s1);
        m1=max(k(s1==m));
        s22=[s1((m1+1):end) s22 ];
        s21=[s21 s1(m1)];
        n=m1-1;
        s1=s1(1:n);
        
    end
    
    p=s0([s21 s22]);
        
    fprintf(fileID2,['Case #' num2str(ii) ':' ' ' p '\r\n']);
        
end


fclose(fid);
fclose(fileID2);
