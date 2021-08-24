function A()

filenameIn = '~/Desktop/Round 1/A/A-small-attempt0.in';
filenameOut = [filenameIn '.out'];

info = readFile(filenameIn);

fid = fopen(filenameOut, 'w');

nCase = str2double(info{1});

for loopcase = 1:nCase
    inString = info{loopcase+1};
    strings =  allPossibleStrings(inString);
    l = findLargestString(strings);
    fprintf(fid, 'Case #%d: %s\n', loopcase, l);
end

fclose(fid);

function listStrings = allPossibleStrings(inString)
listStrings = {inString(1)};

for k = 2:length(inString)
    tempList = listStrings;
    
    for j = 1:length(tempList)
        listStrings{j} = [inString(k) listStrings{j}];
        tempList{j} = [tempList{j} inString(k)];
    end
    listStrings = [listStrings; tempList];
end

function res = findLargestString(strings)
res = strings{1};
for k = 2:length(strings)
    if firstStringWin(strings{k}, res)
        res = strings{k};
    end
end

function res = firstStringWin(A, B)

res = 0;

for k = 1:length(A)
    if (A(k) == B(k))
        continue;
        
    else if (A(k) > B(k))
            res = 1;
            return;
        else
            return;
        end
    end
end