var num1 = 0;
var num2 = 0;
var operation = "";

function addNum(num){	
	var input = document.getElementById("txtInput");
	input.value = input.value + num.toString();
}

function operate(opr){
	var input = document.getElementById("txtInput");
	
	if(operation==""){
		num1 = input.value;
	}else{
		num2 = input.value;
		total = parseInt(num1) + parseInt(num2);
		num1 = total;
		num2 = 0;
	}
	
	operation = opr;
	
	input.value = "";
}

function equalNum(){
	var input = document.getElementById("txtInput");	
	var total = 0;
	
	num2 = input.value;
	
	if(operation=="+"){
		total = parseInt(num1) + parseInt(num2);
	}
	
	if(operation=="-"){
		total = parseInt(num1) - parseInt(num2);
	}
	
	if(operation=="*"){
		total = parseInt(num1) * parseInt(num2);
	}
	
	if(operation=="/"){
		total = parseInt(num1) / parseInt(num2);
	}
	
	input.value = total;
	operation = "";
}

function clearAll(){
	var input = document.getElementById("txtInput");	
	var num1 = 0;
	var num2 = 0;
	var operation = "";
	input.value = "";
}
