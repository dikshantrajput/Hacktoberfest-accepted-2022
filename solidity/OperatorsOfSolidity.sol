// SPDX-License-Identifier: MIT
// compiler version must be greater than or equal to 0.8.13 and less than 0.9.0

pragma solidity ^0.8.13;

// 1) Solidity program to demonstrate primitive data types

contract PrimitiveDataTypes {
    bool public boo = true;

    /*
    uint stands for unsigned integer, meaning non negative integers
    different sizes are available */
    uint8 public u8 = 5;
    uint public u256 = 378;
    uint public u = 123; // uint is an alias for uint256

    /*
    Negative numbers are allowed for int types.
    Like uint, different ranges are available from int8 to int256 */
    int8 public i8 = -7;
    int public i256 = 925;
    int public i = -123; // int is same as int256

    address public addr = 0xCA35b7d915458EF540aDe6068dFe2F44E8fa733c;

    //In Solidity, the data type byte represent a sequence of bytes. 
    
    bytes1 a = 0xb5; //  [10110101]
    bytes1 b = 0x56; //  [01010110]

    // Default values
    // Unassigned variables have a default value
    bool public defaultBoo; // false
    uint public defaultUint; // 0
    int public defaultInt; // 0
    address public defaultAddr; // 0x0000000000000000000000000000000000000000
}

// 2) Solidity program to demonstrate state, local and global variables

contract VariableTypes {
   uint storedData; // State variable
   uint public glob;
   constructor() public {
      storedData = 75;
      glob = block.timestamp; // Global variable
   }
   function getResult() public view returns(uint){
      uint a = 10; // local variable
      uint b = 20;
      uint result = a + b;
      return storedData; //access the state variable
   }
}

// 3) Solidity contract to demonstrate Arithmetic Operator 

contract ArithmeticOperators {
    int a = 20;
    int256 b = 6;
    int public add = a + b; // Addition
    int public sub = a - b; // Subtraction
    int public mul = a * b; // Multiplication
    int public div = a / b; // Division
    int public mod = a % b; // Modulus
    int public inc = ++a; // Increment 
    int public dec = --b; // Decrement
}

// 4) Solidity program to demonstrate Relational Operator 

contract RelationalOperators {
    uint16 public a = 20;
    uint16 public b = 10;
    bool public eq = a == b; // equal
    bool public noteq = a != b; // not equal
    bool public gtr = a > b; // greater than
    bool public les = a < b; // less than
    bool public gtreq = a >= b; // greater than equal
    bool public leseq = a <= b; // less than equal
}

// 5) Solidity program to demonstrate Logical Operators 

contract LogicalOperators {
    function Logic(bool a, bool b) public view returns(bool, bool, bool){
        
       bool and = a&&b; // Logical AND operator 
       bool or = a||b; // Logical OR operator 
       bool not = !a; // Logical NOT operator
       return (and, or, not);
 }
}

// 6) Solidity program to demonstrate Bitwise Operator 

contract BitwiseOperators {
     
    // Declaring variables
    uint16 public a = 20;
    uint16 public b = 10;
 
    // Initializing a variable
    // to '&' value
    uint16 public and = a & b;
 
    // Initializing a variable
    // to '|' value
    uint16 public or = a | b;
 
    // Initializing a variable
    // to '^' value
    uint16 public xor = a ^ b;
 
    // Initializing a variable
    // to '<<' value
    uint16 public leftshift = a << b;
 
    // Initializing a variable
    // to '>>' value
    uint16 public rightshift = a >> b;
   
    // Initializing a variable
    // to '~' value
    uint16 public not = ~a ;
     
}

// 7) Solidity program to demonstrate Assignment Operator 

contract AssignmentOperator {
 
        // Declaring variables
        uint16 public assignment = 20;
        uint public assignment_add = 50;
        uint public assign_sub = 50;
        uint public assign_mul = 10;
        uint public assign_div = 50;
        uint public assign_mod = 32;
     
        // Defining function to
        // demonstrate Assignment Operator
        function getResult() public{
           assignment_add += 10;
           assign_sub -= 20;
           assign_mul *= 10;
           assign_div /= 10;
           assign_mod %= 20;
           return ;
        }
}

// 8) Solidity program to demonstrate Conditional Operator

contract ConditionalOperator {
 
     // Defining function to demonstrate conditional operator
     function sub(
       uint a, uint b) public view returns(
       uint){
      uint result = (a > b? a-b : b-a);
      return result;
 }
}