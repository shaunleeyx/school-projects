/**Author:Shaun Lee
 *Class Overview:
 * a mangler accepts an integer, call it b, and alternates between returning x+b, x-b, or x*b
 *
 *Class Invariant: 
 * variable b can be negative or positive int
 * request() will return x+b,x-b,x*b in a sequence and then loops back
 * The class encapsulates a variable b through the constructor 
 * getNum returns the number of times request has been called
 * request returns -1 if invalid state
 *                  
 *Interface Invariant: 
 * x can be negative or positive
 * b can be negative or positive
 *              
 **/

namespace P6 {
    public class mangler : imangler {
        protected readonly int x;
        protected State objState;
        protected int requestcount;
        public mangler (int x) {
            this.x = x;
            objState = State.addition;
            requestcount = 0;
        }
        protected enum State {
            subtraction,
            multiplication,
            addition
        }

        /**
         * Precondition: int
         * Postcondition: returns x+b or x - b or x*b
         **/
        public virtual int request (int b) //document request
        {
            requestcount++;
            switch (objState) {
                case State.addition:
                    objState = State.subtraction;
                    return x + b;
                case State.subtraction:
                    objState = State.multiplication;
                    return x - b;
                case State.multiplication:
                    objState = State.addition;
                    return x * b;
            }
            return -1; //returns -1 when invalid state
        }

        /**
         * Precondition:none
         * Postcondition:returns requestcount
         **/
        public int getNum () {
            return requestcount;
        }
        /**
         * Precondition:none
         * Postcondition:resets obj
         **/
        public void reset () {
            objState = State.addition;
            requestcount = 0;
        }
    }
}
/**
 * Implementation Invariant: 
 * 3 different states that determines if its going to return x+b, x-b, x*b
 * b is injected through the request function
 * reset() resets the object to its original state
 * requestcount is number of times request has been called
 * getNum() returns the requestcount value 
 *
 */