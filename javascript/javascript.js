// javascript notes
// dan woolsey

/*

DEFINITIONS:

  selector -> an HTML tag to which CSS or JS can be applied to
  null     -> acts as 0 for numerical work and false for boolean work
  DOM      -> document object model - treats an HTML/XHTML/XML document as a tree with nodes for each section of the document

NOTES:
  - When applying JS to an HTML document, remember JAVASCRIPT AFFECTS HTML, not the other way round
  - For this reason, put the <script> tag at the end of the section you want it to affect, e.g. <head>, <body>, ...

CONTEXT:
  (https://en.wikipedia.org/wiki/ECMAScript)
  -> ECMAScript: standardized scripting language specification based on Javascript BUT is also its own language (.es)
  -> JS creator -> Brendan Eich - CEO of Mozilla

IMPORTANT FUNCTIONS AND OBJECTS:
  document -> refers to the entire HTML page being dealt with
  querySelector([selector])            -> refers to a tag in the html document
  getAttribute([attr_name])            -> given a tag, return the data found in attr_name
  setAttribute([attr_name],[new_data]) -> given a tag, set 'attr_name' to 'new_data'
  innerHTML                            -> the HTML content of the document
  typeof var_name                      -> returns the type of var_name

*/

// 1) variable declarations

    var a    // declares a variable, optionally giving it a value to begin with
    let b    // block scope local variable, allows one variable to hold multiple values in different blocks of code
    const c  // read only variable, name declaration in all caps, cannot be changed after declaration (final in java)

// 2) testing equality

  var a = 3;
  var b = 3;

  a === b;   // returns true -> 'equality with type coercion' -> compares equality of value AND type
  a == b;    // returns true -> compares equality of just value (SHOULDN'T BE USED)
  !(a === b) // returns false (are a and b not equal)
  a !== 3    // return false (is a not equal to 3 - false)

// extra reading: http://stackoverflow.com/questions/523643/difference-between-and-in-javascript

// 3) editing sections

    var myHeading = document.querySelector('h1');  // choose any tag in an html document
    myHeading.textContent = 'Hello world!';        // change the data in the selected tag

// 4) conditionals

    testOne = 'abc';
    if(testOne === 'abc')
    {
      alert('testOne is equal to abc');  // brings up an option box for the user
    }
    else
    {
        alert('testOne is not equal to abc');
    }

// 5) functions

    function multiply(a,b)
    {
      var result = a * b;
      return result;
    }

// 6) events

    document.querySelector('html').onclick = function() // this creates a 'nameless' function
    {
        alert('ooer'); // whenever the screen is clicked, an alert box is displayed
    }

// 7) storing data

    localStorage.setItem(age, 6); // stores the var age as 6 in the browsers cache

// extra reading: http://stackoverflow.com/questions/7079075/where-does-firefox-store-javascript-html-localstorage

// 8) arrays

    var newArray = [];
    if(!newArray[0])   // if the array is empty
    {
        doThis();
    }
    else
    {
        doThat();
    }

// 9) variable hoisting

(function()
{
    console.log(myvar);         // undefined
    var myvar = "local value";  // myvar is given the value "local value"
    console.log(myvar);         // "local value"
})();

// if js didnt have variable hoisting, this would be the equivalent of writing

(function()
{
    var myvar;
    console.log(myvar); // undefined
    myvar = "local value";
    console.log(myvar); // "local value"
})();

// variable hoisting doesn't work for 'let' or 'const' declarations

  console.log(x); // ReferenceError is thrown
  let x = 3;      // x is defined in the program block

// 10) functions

// -- FUNCTION DECLARATION:
//      defines a named function variable without requiring variable assignment

function bar()
{
    return 5;
}

bar() // 5
bar   // function

// -- FUNCTION EXPRESSION:
//      defines a function as part of a larger expression syntax

// a) anonymous function expression

var a = function()
{
    return 1;
}

a(); // 1
a;   // function a()

// b) named function expression

var b = function bar()
{
    return 2;
}

b();   // 2
b;     // function bar()
bar(); // ReferenceError: bar is not defined

// c) self invoking function expression

(function sayHello()
{
    alert("hello");
})(); // 'hello' in an alert box

// 10.5) function hoisting

// function declarations are hoisted

foo() // 3

function foo()
{
    return 3;
}

// function expressions are not hoisted

bar() // ReferenceError: bar is not a function

var bar = function()
{
    return 3;
}

// extra reading: https://javascriptweblog.wordpress.com/2010/07/06/function-declarations-vs-function-expressions/

// 11) global variables

// properties of the global object -> known as window for web pages
// means global variables are defined by window.GLOBAL_VARIABLE

const window.MAX_NUM_OF_USERS = 100;

// 12) data types

// javascript has 7 data types:

// PRIMITIVE TYPES:

    null      // keyword denotes null value
    undefined // var whos value isn't yet defined
    Boolean   // true/false
    Number    // any int or float
    String    // any set of characters
    Symbol    // immutable and may be used as an identifier for object properties

// OBJECT:

    Object()  // structure containing data and operations on said data

// examples

var a = true;
typeof a       // boolean

typeof b;      // undefined (due to hoisting)
var b = 6.7;

// 13) type conversion

// returns an integer from a string, even if given a float
parseInt(string, radix); // radix is just the numerical base

// e.g.

var a = "14";
typeof a;     // string

var b = parseInt(a, 10);
b;                       // 14
typeof b;                // number

// returns a float from a string
parseFloat(string);

var c = parseFloat("3.532");
c;                            // 3.532

// 14) literals

// the values inside the data structure are defined upon initalisation

// array literals
var coffees = ["French Roast", , "Kona"]; // using two commas makes a space in the array known as undefined

coffees[0]; // "French Roast"
coffees[1]; // undefined
coffees[2]; // "Kona"

// note: using trailing commas at the start and end of an array can cause errors, avoid where possible
//       its best to initalise these blank spaces as undefined to avoid any confusion

// object literals
//    best explained by example

var sales = "Toyota";

function carTypes(name)
{
    if(name === "Honda")
    {
        return name;
    }
    else
    {
        return "We don't sell " + name + " cars";
    }
}

var car =
{
    myCar : "Saturn",
    getCar : carTypes("Honda"),
    special : sales,
    manyCars : {a : "Saab", b : "Jeep"}, // you can nest objects inside of objects
    "!" : "Please input a valid option", // other data types can also be used as identifiers but are accessed through array notation WITHOUT a dot
    toString()
    {
        return "Car Type: " + this.getCar + "\nCar Model: " + this.getCar + "\nCar Specials: " + this.special;
    }
}

car.myCar;      // Saturn
car.getCar;     // Honda
car.special;    // Toyota
car.manyCars.a; // Saab
car.manyCars.b; // Jeep
car."";         // SyntaxError: missing name after . operator
car[""];        // Please input a valid option
car.toString(); // "Car Type: Honda\nCar Model: Honda\nCar Specials: Toyota"

// 15) regex (regular expressions)

var re = /ab+c/;                    // abc, abbc, abbbc, ... (matches this if found in any expression)
var result = re.exec("lhsgabcsj");  // searches the given string and returns an array with the found regex pattern(s)
result;                             // Array["abc"]

// you can also generate a regexp object in the following syntax:
// RegExp(pattern, [flag]) (flag is optional)
// note: for pattern, define as a literal (RegExp(/ab+c/)) when the regex is going to remain constant
//                    define as a constructor (RegExp("ab+c")) when the regex will change
// (for literal regex, compilation is done at evaluation as opposed to runtime for constructor regex)
// (literal regex can't accept dynamic input but have better performance over constructor regex)

var re = new RegExp("ab+c");
var results = re.exec("ftglsabbcacxy");
results; // Array[abbc]
