// Run of OS X Javascript Interpreter
// I'm sure it works fine on other shells too.
// /System/Library/Frameworks/JavaScriptCode.framework/Versions/A/Resources/jsc
//
// Run with:
// jsc thisFile.js -- "`cat inputFile.in`"
//

// Utility functions
function exists(variable) {
	return typeof(variable)!="undefined";
}
// Functions from http://www.java2s.com/Code/JavaScript/Security/NumberBaseConverterinJavaScript.htm
function baseCon(from,to,val) {
	val2=baseXCon10(from,val);
	if(""+val2=="nh")sum="No alpha-numerics in base "+from+" numbers."; else sum=base10ConX(to,val2);
		return sum;
}
function baseXCon10(from,val){
	val=""+val;sum=0;sgn=1;pl=0;div=1;
	for(a=0;a<val.length;a++) {
		ch=val.substring(a,a+1);
		if(ch=="+" && a==0)sgn=1;
		else {
			if(ch=="-" && a==0)sgn=-1;
			else {
				if(ch==".")div=pl;
				else {
					if(ch>='0' && ch<='9')dg=1*ch;
					ch=ch.toUpperCase();
					if(ch=='A')dg=10;if(ch=='B')dg=11;if(ch=='C')dg=12;if(ch=='D')dg=13;if(ch=='E')dg=14;if(ch=='F')dg=15;
					if(ch>='A' && ch<='Z' && from<=10 && from>0) {nh="nh"; return nh;}
					sum+=Math.pow(from,pl)*dg;
					pl--;
				}
			}
		}
	}
	if(div==1)div=pl;
	sum/=Math.pow(from,div+1);
	if(sum>1000000 && sum-Math.floor(sum)<.000001) sum=Math.floor(sum);
	if(sum>1000000 && Math.ceil(sum)-sum<.000001) sum=Math.ceil(sum);
	sum*=sgn; round=1000000000000
	sum=Math.floor(sum*round+.5)/round;
	return sum;
}
function base10ConX(to,val) {
	if(val<0){sgn="-";val=-val;}else{sgn="";}
	sum="";

	c=Math.floor(val);

	start=0;rem=0;digits=0;
	if(c==0)sum="0";
	while(Math.abs(c)>=1) {
		d=c-Math.floor(c/to)*to;
		dfl=Math.floor(d);
		if(dfl!=d){rem=d-dfl;d=dfl;}
		if(Math.abs(d)>Math.abs(to)) d=0;
		c=Math.floor(c/to);
		if((start==0 && d!=0) || c<val*to)start=1;start=1;
		sum=""+alp(d,to)+sum;
		digits++;
	}
	c=val-Math.floor(val)+rem;
	if(c!=0) {//decimals
		sum+=".";
		for(a=0;a<32/Math.log(to)-digits;a++) {
			if(c==0)break;
			d=Math.floor(c*to);
			if(to<0 && d==to) break;
			c=c*to-d;
			sum+=alp(d,to);
		}
	}
	sum=sgn+sum;
	return sum;
}
function alp(d,to) {
	if(d>=0 && d<=9)w=""+d;
	if(to>=10 && to<=36) {
		if(d==10)w="A";if(d==11)w="B";if(d==12)w="C";if(d==13)w="D";if(d==14)w="E";if(d==15)w="F";if(d==16)w="G";if(d==17)w="H";if(d==18)w="I";if(d==19)w="J";if(d==20)w="K";if(d==21)w="L";if(d==22)w="M";if(d==23)w="N";if(d==24)w="o";if(d==25)w="P";if(d==26)w="Q";if(d==27)w="R";if(d==28)w="S";if(d==29)w="T";if(d==20)w="U";if(d==31)w="V";if(d==32)w="W";if(d==33)w="X";if(d==34)w="Y";if(d==35)w="Z";
	}
	if(d<0 || d>35 || (d>9 && to>36))
		w="["+d+"]";
	return w;
}
function multiplyInBase(num1,num2,base) {
	
}
// End
/*function isHappyInBase(number,base) {
    var m, digit,digitPosition;
    var cycle = new Array();
 	
	number = baseCon(10,base,number);

    while(number != 1 && cycle[number] != true) {
        cycle[number] = true;
        m = 0;
		digitPosition = 0;
        while (digitPosition < number.length) {
			// Double the correct digit and add it
			digit = number.charAt(digitPosition);
            //digit = number % base;
			var base10digit = baseCon(base,10,digit);
            m += base10digit * base10digit;
			digitPosition++;
        }
        number = baseCon(10,base,m);
    }
    return (number == 1);
};*/
function isHappyInBase(number,base) {
    var m, digit ;
    var cycle = new Array() ;
 
    while(number != 1 && cycle[number] != true) {
        cycle[number] = true ;
        m = 0 ;
        while (number > 0) {
            digit = number % base ;
            m += digit * digit ;
            number = (number  - digit) / base ;
        }
        number = m ;
    }
    return (number == 1) ;
} ;

var debug=false;

output = print;

if (!exists(arguments)) {
	var arguments = Array();
	arguments[0] = "3\n2 3\n2 3 7\n9 10";
	output = console.info;
}

var allData = arguments[0].split("\n").reverse();

allData.pop(); // Get rid of first line (number of cases)
allData.reverse();
if (debug) output(allData);
// Actual logic

for (var i=0; i < allData.length; i++) {
	var testBases = allData[i].split(" ");
	
	var testNumber = 2;
	while (true) {
		if (isHappyInBase(testNumber,testBases[0])) {
			if (debug) output(testNumber + " is happy in base "+testBases[0]);
			// Test the other bases
			var isGood = true;
			for (var j=1; j < testBases.length; j++) {
				if (debug) output("Testing in base "+testBases[j]);
				var base = testBases[j];
				var inBase = baseCon(10,base,testNumber)
				if (debug) output(testNumber+" in base "+base+" is "+ inBase);
				if (!isHappyInBase(testNumber,base)) {
					if (debug) output(testNumber + " is NOT happy in base "+base);
					
					isGood = false;
					 break;
				}
			};
			//if (debug) output("Made it out good? "+isGood);
			if (isGood) {
				output("Case #"+(i+1)+": "+testNumber);
				break;
			}
		} else {
			if (debug) output(testNumber + " is NOT happy in base "+testBases[0]);
		}
		//if (debug) output("Increasing "+testNumber);
		testNumber++;
	}
	
	//break;
};