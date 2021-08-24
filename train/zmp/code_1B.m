clear

MyDir='C:\Users\Zita\Documents\A_CodeJam\';
MyFN='B-large.in';
MyFN2=['res_' MyFN];

fid = fopen([MyDir MyFN]);
fileID2 = fopen([MyDir MyFN2],'w');

t = fscanf(fid, '%d',1);

for ii=1:t
    n = fscanf(fid, '%d',1);
    r1=[];
    k=1:(n*n);
    
    for i=1:(2*n-1)
        for j=1:n
            r0=fscanf(fid, '%d',1);
            if sum(r1==r0)==0
                r1=[r1 r0];
                m1(length(r1))=1;
            else
                m1(k(r1==r0))=m1(k(r1==r0))+1;
            end
        end
    end
    
    p=sort(r1(mod(m1,2)==1));
    
    fprintf(fileID2,['Case #' num2str(ii) ':' ' ']);
    for i=1:n
        fprintf(fileID2,[num2str(p(i)) ' ']);
    end
    
    clear r m1
    fprintf(fileID2,['\r\n']);
end


fclose(fid);
fclose(fileID2);
