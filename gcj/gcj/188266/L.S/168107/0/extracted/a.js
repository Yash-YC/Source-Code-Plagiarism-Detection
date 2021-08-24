import System;
import System.Console;

/*@cc_on @*/
/*@set @debug=true@*/
function trace(variable){
	/*@if (@debug==true)
		print(variable);
	@end @*/
}

var GetInts=function(){
	var line=Console.ReadLine();
	var words=line.split(" ");
	for(var i=0,len=words.length;i<len;i++){
		words[i]=parseInt(words[i]);
	}
	return words;
}



Array.prototype.forEach=function(f){
	//f:callback function
	//f(element,index)
	for(var i:int=0,len:int=this.length;i<len;i++){
		f(i,this[i]);
	}
}

Array.prototype.assign=function(f){
	//f(index)
	for(var i:int=0,len:int=this.length;i<len;i++){
		this[i]=f(i);
	}
}

Array.prototype.has=function(el){
	for(var i:int=0,len:int=this.length;i<len;i++){
		if(this[i]===el)
			return true;
	}
	return false;
}

Object.prototype.forEach=function(f){
	//f:callback function
	//f(name,value)
	for(var name in this){
		if(name!="forEach")//Do not print itself
			f(name,this[name]);
	}
}




class Table{
	var buf;
	public var width:int=0,height:int=0;
	public function Table(w,h){
		width=w;
		height=h;
		buf=new Object[width,height];
	}
	public function forEach(f){
		//f(i,j,el)
		for(var i:int=0;i<width;i++){
			for(var j:int=0;j<height;j++){
				f(i,j,buf[i,j]);
			}
		}
	}
	public function assign(f){
		//f(i,j)
		for(var i:int=0;i<width;i++){
			for(var j:int=0;j<height;j++){
				buf[i,j]=f(i,j);
			}
		}
	}
}

function isHappy(n,b){
	var obj=[];
	while(n!=1){
			if(obj[n])	return false;
			obj[n]=true;
			var s=n.toString(b);
			var sum=0;
			for(var i=0,len=s.length;i<len;i++){
				var c=parseInt(s.charAt(i));
				sum+=c*c;
			}
			n=sum;
	}
	return true;
}

var ints=GetInts();
var t=ints[0];
for(var i=0;i<t;i++){
	var bases=GetInts();
	var j=2;
	while(true){
		var happy=true;
		for(var k=0,len=bases.length;k<len;k++){
			var b=bases[k];
			if(!isHappy(j,b)){
				happy=false;
				break;
			}
		}
		if(happy){
			print("Case #"+(i+1)+": "+j+"");
			break;
		}else{
			j++;
		}
	}
}