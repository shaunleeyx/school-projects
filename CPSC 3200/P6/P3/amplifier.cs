/**Author:Shaun Lee
 *Class Overview: 
 * an amplifier is-a mangler that accepts an integer, call it b, and returns x*b if b is odd or x*(b+1) if b is even
 * 
 *Class Invariant: 
 * variable b is encapsulated through the constructor
 * request() returns x*b if b is odd 
 * request returns x*(b+1) if b is even
 * reset function resets the object to its original state
 *  
 *Interface Invariant:
 * int x can be negative or positive
 * int b can be negative or positive
 **/

namespace P6 {
    public class amplifier : mangler, iamplifier {
        public amplifier (int x) : base (x) {

        }
        /**
         * Precondition:int b
         * Postcondition:returns x*(b+1) or x*b
         **/
        public override int request (int b) {
            requestcount++;
            if (b % 2 == 0) {
                return x * (b + 1);
            } else {
                return x * b;
            }
        }
    }
}
/**
 * Implementation Invariant: 
 * x is a integer
 * x is passed through constructor's param
 * b is a integer
 * b is passed through request fn's param
 * request() returns x*b if b is odd and x*(b+1) if b is even
 * count value to count how many times request has been called
 * getNum() returns the requestcount value
 * amplifier uses base class's reset function
 */