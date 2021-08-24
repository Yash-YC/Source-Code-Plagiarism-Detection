var infile = 'A-large.in';
var outfile = './output_a.txt';

function solve(s) {
    var word = '';
    var first = '';
    var second = '';
    for (var i = 0; i< s.length; i++){
        first = word + s[i];
        second = s[i] + word;
        word = first > second ? first : second;
    }
    return word;
}


var util = require('util');
var fs = require('fs');
var endOfLine = require('os').EOL;
try {
    fs.unlink(outfile);
} catch (err) {
}
var file = fs.createWriteStream(outfile);
var lineReader = require('readline').createInterface({
    input: fs.createReadStream(infile)
});
var n = -1;
lineReader.on('line', function (line) {
    n++;
    if (n == 0) return;
    var ans = solve(line);
    console.log('Line from file:', line);
    file.write(util.format('Case #%s: %s%s', n, ans, endOfLine));
});