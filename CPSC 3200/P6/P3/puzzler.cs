/**Author:Shaun Lee
 *Platform:VsCode
 *Class Overview: 
 This class inherits from the mangler class. it does x*(b+1) when b is even and x*b when b is odd
 *
 *Class Invariant:
 * if the requestcount is divisible by clear variable request will return 0
 * clear and int b can both be positive or negative
 * requestcounts increments when request is called
 * 
 *Interface Invariant: 
 *x,clear,b can be negative and positive 
  **/
namespace P6 {
    public class puzzler : mangler, ipuzzler {
        private int clear;
        public puzzler (int x, int clear) : base (x) {
            if (clear <= 0) clear = 1;
            this.clear = clear;
        }
        /**
         * Precondition:int
         * Postcondition:returns x*(b+1) or x*b depending on b
         **/
        public override int request (int b) {
            requestcount++;
            if (requestcount % clear == 0) return 0;
            if (b % 2 == 0) {
                return x * (b + 1);
            } else {
                return x * b;
            }

        }
    }
}
/*
 * Implementation invariant: 
 *                          i encapsulated the clear variable through the constructor's 2nd arg
 *                          if b is even then request returns x * (b+1)
 *                          if b is odd then request returns x * b;
 *                          if requestcount is divisible by clear then request's call will return 0
 *                          if clear is less or equal to 0 it will be 1
 *                          puzzler uses reset() from mangler
 */